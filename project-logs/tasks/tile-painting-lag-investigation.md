# Tile Painting Lag Investigation

## Problem Description

**Issue:** When dragging the mouse quickly while painting tiles, there is a significant lag and only some of the tiles get placed, not all the tiles where the cursor passed.

**Symptoms:**
- Editor doesn't "freeze" but nothing visible happens while dragging
- Tiles only appear after releasing the mouse button
- Many tiles are missing from where the cursor traveled
- Only 1/4 to 1/2 of the expected tiles are actually placed

---

## Root Cause Identified

### Location: `EdModeTileMap.cpp`

**Mouse Input Handling:**
- Lines 304-324: `CapturedMouseMove()` - Called when mouse moves while button is held
- Lines 336-384: `InputKey()` - Called for keyboard/mouse button events
- Line 676-694: `UseActiveToolAtLocation()` - Routes to appropriate painting function
- Line 787-812: `PaintTiles()` - Actually places the tiles

### The Problem

**Line 312-316 in `CapturedMouseMove()`:**
```cpp
if (bIsPainting)
{
    UseActiveToolAtLocation(Ray);
    return true;
}
```

**Line 370-374 in `InputKey()`:**
```cpp
if (bIsPainting)
{
    bHandled = true;
    bAnyPaintAbleActorsUnderCursor = UseActiveToolAtLocation(Ray);
}
```

### Why It Lags

1. **Mouse Move Events are Throttled**
   - `CapturedMouseMove()` is only called at **editor viewport frame rate**
   - If you drag fast, the mouse travels several tiles between calls
   - Each call only paints ONE position (current cursor location)
   - Result: Sparse tile placement with big gaps

2. **Heavy Transaction Overhead**
   - Each `PaintTiles()` call starts a new `FScopedTransaction` (line 698)
   - Transaction system is designed for undo/redo
   - Creating transaction for every mouse move is expensive
   - Visual update delayed until transaction completes

3. **Dirty Region Updates**
   - Line 807: Adds to `PendingDirtyRegions` after each paint
   - Line 250-258: `Tick()` delays nav mesh rebuild for performance
   - Visual feedback is batched/delayed

### The Real Issue

**There's NO interpolation between mouse positions!**

When the mouse moves from position A to position B quickly:
- Normal behavior: Should paint all tiles along the path A → B
- Current behavior: Only paints at position B (missing everything in between)

This is a classic "mouse move sampling" problem in paint applications.

---

## How Other Paint Apps Solve This

### Photoshop/Krita/etc.
- Store previous mouse position
- When mouse moves, interpolate (Bresenham line) between old and new position
- Paint at all interpolated positions
- Result: Continuous stroke even with fast movement

### What Paper2D Needs

```cpp
// Pseudocode
FIntPoint PreviousMouseTilePosition;

void OnMouseMove(CurrentMousePosition)
{
    if (bIsPainting)
    {
        // Get all tiles along the line from previous to current position
        TArray<FIntPoint> TilesToPaint = InterpolateTilePath(PreviousMouseTilePosition, CurrentMouseTilePosition);
        
        // Paint at each position
        for (FIntPoint& TilePos : TilesToPaint)
        {
            PaintAtTilePosition(TilePos);
        }
    }
    
    PreviousMouseTilePosition = CurrentMouseTilePosition;
}
```

---

## Additional Issues

### Issue 1: Transaction Per Paint Call

Line 698 in `BlitLayer()`:
```cpp
FScopedTransaction Transaction(LOCTEXT("TileMapPaintActionTransaction", "Tile Painting"));
```

Creating a new undo transaction for **every single tile placement** is expensive. Should batch multiple paints into one transaction during a continuous drag.

### Issue 2: Immediate PostEditChange

Line 744 in `BlitLayer()`:
```cpp
TargetLayer->GetTileMap()->PostEditChange();
```

This triggers expensive updates after every paint call. Should be deferred until mouse release.

### Issue 3: No Mouse Position History

The code doesn't track where the mouse has been between frames, so it can't fill in the gaps.

---

## Proposed Solution (Enhanced)

### Overview: Preview-Before-Commit System

**User Workflow:**
1. **Hold Left Mouse** → Paint tiles continuously (real-time preview)
2. **Release Left Mouse** → Finalize/commit the painted tiles
3. **Right Click (while holding)** → Cancel stroke, don't place anything

This gives users full control and prevents accidental placements!

---

## Implementation Plan

### Phase 1: Add Preview Stroke Tracking

Add to `EdModeTileMap.h`:
```cpp
private:
    // Mouse position tracking for interpolation
    FIntPoint LastPaintedTilePosition;
    bool bHasLastPaintedPosition;
    
    // Preview stroke system
    TMap<FIntPoint, FPaperTileInfo> PreviewStrokeTiles;  // Tiles painted in current stroke
    bool bIsStrokeActive;  // True while dragging, false on release
    UPaperTileLayer* PreviewStrokeLayer;  // Target layer for current stroke
```

### Phase 2: Real-Time Preview Painting

In `CapturedMouseMove()`, replace lines 312-316:
```cpp
if (bIsPainting)
{
    int32 CurrentTileX, CurrentTileY;
    if (UPaperTileLayer* Layer = GetSelectedLayerUnderCursor(Ray, CurrentTileX, CurrentTileY))
    {
        FIntPoint CurrentTile(CurrentTileX, CurrentTileY);
        
        if (!bIsStrokeActive)
        {
            // Starting new stroke
            bIsStrokeActive = true;
            PreviewStrokeTiles.Empty();
            PreviewStrokeLayer = Layer;
            bHasLastPaintedPosition = false;
        }
        
        if (bHasLastPaintedPosition)
        {
            // Paint along the line from last position to current
            PaintAlongLineToPreview(LastPaintedTilePosition, CurrentTile, Layer);
        }
        else
        {
            // First tile of stroke
            PaintTileToPreview(CurrentTile, Layer);
        }
        
        LastPaintedTilePosition = CurrentTile;
        bHasLastPaintedPosition = true;
    }
    return true;
}
```

### Phase 3: Commit or Cancel on Mouse Release

In `InputKey()` where `bIsPainting` becomes false (lines 360-364):
```cpp
else if (bWasPainting && !bIsPainting)
{
    // Stopping painting - commit or cancel based on which button released
    if (InKey == EKeys::LeftMouseButton && InEvent == IE_Released)
    {
        // LEFT RELEASE = COMMIT
        CommitPreviewStroke();
    }
    else
    {
        // RIGHT CLICK or ESC = CANCEL
        CancelPreviewStroke();
    }
    
    bIsStrokeActive = false;
    bHasLastPaintedPosition = false;
    InViewportClient->Viewport->SetPreCaptureMousePosFromSlateCursor();
}
```

### Phase 4: Add Right-Click Cancel Support

In `InputKey()`, add check for right-click while painting:
```cpp
// Inside the input handling section (around line 347)
if (InViewportClient->EngineShowFlags.ModeWidgets)
{
    const bool bIsRightButtonPressed = (InKey == EKeys::RightMouseButton && InEvent == IE_Pressed);
    
    if (bIsRightButtonPressed && bIsPainting)
    {
        // User wants to cancel current stroke
        CancelPreviewStroke();
        bIsPainting = false;
        bIsStrokeActive = false;
        bHandled = true;
    }
    
    // ... rest of existing code ...
}
```

### Phase 5: Implement Helper Functions

```cpp
void FEdModeTileMap::PaintTileToPreview(const FIntPoint& TilePos, UPaperTileLayer* Layer)
{
    // Get the tile we want to paint
    UPaperTileLayer* SourceLayer = GetSourceInkLayer();
    FPaperTileInfo TileInfo = SourceLayer->GetCell(0, 0);  // Adjust for brush size
    
    // Store in preview map
    PreviewStrokeTiles.Add(TilePos, TileInfo);
    
    // Paint it immediately for visual feedback (no transaction yet!)
    Layer->SetCell(TilePos.X, TilePos.Y, TileInfo);
    Layer->GetTileMap()->PostEditChange();
}

void FEdModeTileMap::PaintAlongLineToPreview(const FIntPoint& Start, const FIntPoint& End, UPaperTileLayer* Layer)
{
    // Bresenham's line algorithm
    TArray<FIntPoint> TilePath = BresenhamLine(Start, End);
    
    for (const FIntPoint& TilePos : TilePath)
    {
        // Skip if we already painted this tile in current stroke
        if (!PreviewStrokeTiles.Contains(TilePos))
        {
            PaintTileToPreview(TilePos, Layer);
        }
    }
}

void FEdModeTileMap::CommitPreviewStroke()
{
    if (PreviewStrokeTiles.Num() == 0 || !PreviewStrokeLayer)
    {
        return;
    }
    
    // NOW create the undo transaction for the entire stroke
    FScopedTransaction Transaction(LOCTEXT("TileMapPaintStroke", "Tile Painting"));
    
    PreviewStrokeLayer->SetFlags(RF_Transactional);
    PreviewStrokeLayer->Modify();
    
    // Tiles are already painted visually, just need to mark them as committed
    // The transaction system will handle undo
    
    PreviewStrokeTiles.Empty();
    PreviewStrokeLayer = nullptr;
}

void FEdModeTileMap::CancelPreviewStroke()
{
    if (PreviewStrokeTiles.Num() == 0 || !PreviewStrokeLayer)
    {
        return;
    }
    
    // Restore original tiles (no transaction needed - we're canceling)
    for (const TPair<FIntPoint, FPaperTileInfo>& Pair : PreviewStrokeTiles)
    {
        // Erase the preview tile (or restore original if we stored it)
        FPaperTileInfo EmptyCell;
        PreviewStrokeLayer->SetCell(Pair.Key.X, Pair.Key.Y, EmptyCell);
    }
    
    PreviewStrokeLayer->GetTileMap()->PostEditChange();
    PreviewStrokeTiles.Empty();
    PreviewStrokeLayer = nullptr;
}

TArray<FIntPoint> FEdModeTileMap::BresenhamLine(const FIntPoint& Start, const FIntPoint& End)
{
    TArray<FIntPoint> Result;
    
    int32 X0 = Start.X, Y0 = Start.Y;
    int32 X1 = End.X, Y1 = End.Y;
    
    int32 dx = FMath::Abs(X1 - X0);
    int32 dy = FMath::Abs(Y1 - Y0);
    int32 sx = X0 < X1 ? 1 : -1;
    int32 sy = Y0 < Y1 ? 1 : -1;
    int32 err = dx - dy;
    
    while (true)
    {
        Result.Add(FIntPoint(X0, Y0));
        
        if (X0 == X1 && Y0 == Y1) break;
        
        int32 e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            X0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            Y0 += sy;
        }
    }
    
    return Result;
}
```

---

## Benefits

✅ **Continuous painting** - No gaps even with fast mouse movement
✅ **Real-time preview** - See exactly what you're painting as you drag
✅ **Undo-friendly** - Right-click cancels entire stroke instantly
✅ **Single transaction** - One undo entry per stroke, not per tile
✅ **Professional UX** - Same behavior as Photoshop/Krita/GIMP
✅ **Performance** - Heavy transaction only on commit, not every frame

---

## Testing Required

1. **Slow drag** - Should work same as before
2. **Fast drag** - Should now paint continuous line
3. **Diagonal drag** - Should fill all tiles along diagonal
4. **Eraser tool** - Should work the same way (continuous erasing)
5. **Large brushes** - Should paint correctly at each interpolated position

---

## Next Steps

1. Implement tile position tracking
2. Add Bresenham line interpolation
3. Modify `CapturedMouseMove()` to paint along line
4. Test with various brush sizes and speeds
5. Optimize transaction batching (future enhancement)
