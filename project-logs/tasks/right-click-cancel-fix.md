# Right-Click Cancel Fix - Implementation Instructions

## Problem Statement

When the user:
1. Holds left mouse button and starts painting
2. Clicks right mouse button to cancel (while still holding left)
3. Continues moving mouse (still holding left button)

**Current behavior:** Painting resumes immediately after right-click
**Desired behavior:** Painting should NOT resume until user releases and re-presses left button

## Root Cause Analysis

### The Issue

In `CapturedMouseMove()` at **line 347-401**, there is logic that says:
```cpp
if (!bIsStrokeActive)
{
    // Starting new stroke
    bIsStrokeActive = true;
    // ... initialize stroke ...
}
```

This means `CapturedMouseMove()` will **automatically start a new stroke** if there isn't one active.

### Why This Causes the Problem

1. User presses left button → `InputKey()` sets `bIsStrokeActive = true` (line 495)
2. User right-clicks → `InputKey()` sets `bIsStrokeActive = false` (line 475)
3. User moves mouse (left still held) → `CapturedMouseMove()` is called
4. `CapturedMouseMove()` sees `!bIsStrokeActive` and **re-initializes the stroke** (line 350)
5. Painting resumes!

## The Solution

**Strokes should ONLY be initialized in `InputKey()` when the left button is pressed.**

`CapturedMouseMove()` should ONLY continue existing strokes, never start new ones.

## Code Changes Required

### File: `EdModeTileMap.cpp`

**Location:** Lines 347-401 in `CapturedMouseMove()` function

**OLD CODE (lines 347-401):**
```cpp
				if (!bIsStrokeActive)
				{
					// Starting new stroke
					bIsStrokeActive = true;
					PreviewStrokeTiles.Empty();
					OriginalStrokeTiles.Empty();
					PreviewStrokeLayer = Layer;
					bHasLastPaintedPosition = false;

					// Initialize visual preview
					if (StrokePreviewComponent && PreviewStrokeLayer)
					{
						UPaperTileMap* TargetTileMap = PreviewStrokeLayer->GetTileMap();
						
						// Sync properties
						StrokePreviewComponent->TileMap->TileWidth = TargetTileMap->TileWidth;
						StrokePreviewComponent->TileMap->TileHeight = TargetTileMap->TileHeight;
						StrokePreviewComponent->TileMap->PixelsPerUnrealUnit = TargetTileMap->PixelsPerUnrealUnit;
						StrokePreviewComponent->TileMap->SeparationPerTileX = TargetTileMap->SeparationPerTileX;
						StrokePreviewComponent->TileMap->SeparationPerTileY = TargetTileMap->SeparationPerTileY;
						StrokePreviewComponent->TileMap->SeparationPerLayer = TargetTileMap->SeparationPerLayer;
						StrokePreviewComponent->TileMap->Material = TargetTileMap->Material;
						StrokePreviewComponent->TileMap->ProjectionMode = TargetTileMap->ProjectionMode;
						
						// Ensure map size matches
						StrokePreviewComponent->TileMap->MapWidth = TargetTileMap->MapWidth;
						StrokePreviewComponent->TileMap->MapHeight = TargetTileMap->MapHeight;
						StrokePreviewComponent->TileMap->ResizeMap(TargetTileMap->MapWidth, TargetTileMap->MapHeight);

						// Clear any existing tiles
						// Clear any existing tiles
						StrokePreviewComponent->TileMap->TileLayers[0]->ResizeMap(TargetTileMap->MapWidth, TargetTileMap->MapHeight);
						const FPaperTileInfo EmptyTile;
						for (int32 Y = 0; Y < TargetTileMap->MapHeight; ++Y)
						{
							for (int32 X = 0; X < TargetTileMap->MapWidth; ++X)
							{
								StrokePreviewComponent->TileMap->TileLayers[0]->SetCell(X, Y, EmptyTile);
							}
						}

						// Setup transform
						UPaperTileMapComponent* TargetComponent = FindSelectedComponent();
						if (TargetComponent)
						{
							StrokePreviewComponent->SetWorldLocation(TargetComponent->GetComponentLocation() + (PaperAxisZ * 0.1f)); // Slight offset to prevent z-fighting
							StrokePreviewComponent->SetWorldRotation(TargetComponent->GetComponentRotation());
							StrokePreviewComponent->SetWorldScale3D(TargetComponent->GetComponentScale());
						}
						
						// Show it
						StrokePreviewComponent->SetVisibility(true);
						StrokePreviewComponent->MarkRenderStateDirty();
					}
				}
```

**NEW CODE (replace lines 347-401 with this):**
```cpp
				// Don't start new strokes in CapturedMouseMove - only continue existing ones
				// Strokes are initialized in InputKey() when left button is pressed
				if (!bIsStrokeActive)
				{
					// No active stroke - user must release and re-press left button
					// This prevents painting from resuming after right-click cancel
					return true;
				}
```

## Expected Behavior After Fix

1. **Normal painting:** Click left → drag → release → tiles placed ✅
2. **Single click:** Click left → release (no drag) → tile placed ✅  
3. **Right-click cancel:** Click left → drag → right-click → **painting stops** ✅
4. **After cancel:** Continue moving mouse (left still held) → **NO painting** ✅
5. **Resume painting:** Release left → click left again → painting works ✅

## Testing Steps

1. Rebuild Paper2D plugin
2. Open tile map editor
3. Select paintbrush tool
4. Test scenario: Hold left, paint some tiles, right-click (while holding left), move mouse
5. **Expected:** No tiles painted after right-click
6. **Expected:** Must release and re-click left to paint again
