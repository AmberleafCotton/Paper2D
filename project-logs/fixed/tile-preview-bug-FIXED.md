# Tile Preview Bug - FIXED ✅

**Date Fixed:** 2025-12-07  
**Status:** Implemented and Working  
**Bug:** Double tile indicator in isometric tile map editor  
**File Modified:** `EdModeTileMap.cpp` (Lines 1117-1135)

---

## Bug Description

**Issue:** Double tile indicator when painting in isometric tile map editor

**Symptoms:**
- Grid tile size: 32×16
- Tile set sprites: 64×64
- Expected: 2×2 tile preview when painting
- Actual: 4×2 cells displayed (doubled)
- Two visible indicators: one empty outline + one with the actual tile

---

## Root Cause

### Location
`EdModeTileMap.cpp` - Lines 1117-1122 in `SetActivePaint()` function

### The Bug
```cpp
FIntPoint Scale(1, 1);
if (TileSet != nullptr)
{
    Scale.X = FMath::Max(1, TileSet->GetTileSize().X / CursorPreviewComponent->TileMap->TileWidth);
    Scale.Y = FMath::Max(1, TileSet->GetTileSize().Y / CursorPreviewComponent->TileMap->TileHeight);
}

DestructiveResizePreviewComponent(Dimensions.X * Scale.X, Dimensions.Y * Scale.Y);
```

### The Problem

When using isometric tiles with:
- **Grid tile size:** 32 (width) × 16 (height)
- **Tile set sprite size:** 64 × 64

The scale is calculated as:
- `Scale.X = 64 / 32 = 2` ✓ Correct
- `Scale.Y = 64 / 16 = 4` ✗ **WRONG!**

**Result:** 
- Selecting a 1×1 tile creates a preview component sized 2×4 (2 * 1, 4 * 1)
- This shows 2 columns and 4 rows instead of 2×2
- User sees **double preview** (4×2 cells instead of 2×2)

### Why This Happens

The code calculates scale independently for X and Y axes based on grid dimensions. This works for **orthogonal** projection where tiles are square, but fails for **isometric diamond** where:
- Grid width and height have different ratios (2:1 for isometric)
- Sprite is typically square (1:1 ratio)
- The Y scale gets incorrectly doubled

---

## The Fix

### Original Code (Lines 1117-1122)

```cpp
FIntPoint Scale(1, 1);
if (TileSet != nullptr)
{
    Scale.X = FMath::Max(1, TileSet->GetTileSize().X / CursorPreviewComponent->TileMap->TileWidth);
    Scale.Y = FMath::Max(1, TileSet->GetTileSize().Y / CursorPreviewComponent->TileMap->TileHeight);
}
```

### Fixed Code (Lines 1117-1135)

```cpp
FIntPoint Scale(1, 1);
if (TileSet != nullptr)
{
    // For isometric diamond projection, use uniform scaling to prevent double tile preview bug
    // The grid has different X/Y dimensions (e.g., 32x16) but sprites are typically square (e.g., 64x64)
    // Using independent scaling would create 2x4 preview instead of 2x2
    if (CursorPreviewComponent->TileMap->ProjectionMode == ETileMapProjectionMode::IsometricDiamond)
    {
        // Calculate uniform scale based on width (which represents the diagonal of the diamond)
        const int32 UniformScale = FMath::Max(1, TileSet->GetTileSize().X / CursorPreviewComponent->TileMap->TileWidth);
        Scale.X = UniformScale;
        Scale.Y = UniformScale;
    }
    else
    {
        // Orthogonal and other modes: use independent scaling (original behavior)
        Scale.X = FMath::Max(1, TileSet->GetTileSize().X / CursorPreviewComponent->TileMap->TileWidth);
        Scale.Y = FMath::Max(1, TileSet->GetTileSize().Y / CursorPreviewComponent->TileMap->TileHeight);
    }
}
```

### Technical Explanation

For isometric diamond projection, we now use **uniform scaling** based on the width:
- `UniformScale = 64 / 32 = 2`
- `Scale.X = 2`
- `Scale.Y = 2`

This creates a correctly sized **2×2** preview component.

**Why Uniform Scaling?**

In isometric diamond projection:
- The grid dimensions (32×16) represent the **projected** diamond shape
- The tile sprite (64×64) is typically square and should map uniformly to the diamond
- The 2:1 ratio of grid width to height is a projection artifact, not a scaling factor
- Using independent scaling misinterprets the projection as actual tile dimensions

---

## Backward Compatibility

The fix maintains full backward compatibility:
- **Orthogonal mode:** Uses original independent scaling (unchanged behavior)
- **Other projection modes:** Use original independent scaling (unchanged behavior)
- **Isometric diamond mode:** Uses new uniform scaling (fixes the bug)

No existing functionality is broken by this change.

---

## Code Investigation Notes

### Key Files Identified

1. **EdModeTileMap.h** - Main tile map editing mode header
2. **EdModeTileMap.cpp** - Implementation with cursor preview logic

### Critical Components

#### CursorPreviewComponent (UPaperTileMapComponent*)
- Created on mode Enter() at line 172-184
- Purpose: Shows preview of tile being painted
- Properties:
  - TranslucencySortPriority = 99999
  - Grids disabled
  - No collision
  - Static mobility

#### UpdatePreviewCursor() - Lines 1379-1429
Main function that updates the cursor preview position and size.

**Key calculations:**
```cpp
Line 1414: DrawPreviewDimensionsLS = 0.5f*((PaperAxisX * CursorWidth * TileMap->TileWidth) + (PaperAxisY * -CursorHeight * TileMap->TileHeight));
```

#### Render() - Lines 391-447
Draws wireframe cursor overlay using PDI (Primitive Draw Interface).

**Lines 427-444:** Loops through cursor range and draws tile polygon outlines

#### Two Rendering Paths

**Path 1: Wireframe cursor** (Render() function)
- Draws outline of tiles using PDI
- Uses LastCursorTileX/Y and CursorWidth/Height
- This is the "empty" indicator (correct size)

**Path 2: CursorPreviewComponent** 
- Actual rendered tile map component
- Shows the actual tiles being painted
- Positioned at ComponentPreviewLocation (line 1423)
- **This was incorrectly sized, causing the double preview**

---

## Testing & Validation

### Test Case 1: Verify Fix (Isometric Diamond) ✅

1. Create or open a tile map with **Isometric Diamond** projection
2. Set grid tile size to **32×16**
3. Create or use a tile set with **64×64** sprites
4. Select one tile from the tile set
5. Move cursor over the tile map

**Expected Result:** Preview shows **2×2 grid cells** (one cohesive diamond shape)  
**Previous Bug:** Preview showed **4×2 grid cells** (doubled/stretched)  
**Status:** ✅ **WORKING!**

### Test Case 2: Various Sizes

Test different combinations:
- Grid: 32×16, Sprite: 32×32 → Expect 1×1 preview
- Grid: 16×8, Sprite: 64×64 → Expect 4×4 preview  
- Grid: 64×32, Sprite: 64×64 → Expect 1×1 preview

### Test Case 3: Backward Compatibility (Orthogonal)

1. Create or open a tile map with **Orthogonal** projection
2. Set grid tile size to **32×32**
3. Use a tile set with **64×64** sprites
4. Select one tile

**Expected Result:** Preview shows **2×2 grid cells** (same as before)

---

## Performance Impact

**Negligible.** The fix adds:
- One conditional check (`if (ProjectionMode == IsometricDiamond)`)
- No additional calculations (same number of divisions and assignments)
- No memory allocation changes

The performance impact is unmeasurable in practice.

---

## Future Considerations

### Isometric Staggered and Hexagonal Modes

The current fix only addresses **IsometricDiamond** mode. IsometricStaggered and HexagonalStaggered modes are experimental and not fully supported.

**Recommendation:** Monitor these modes for similar issues if they become fully supported. They may need analogous uniform scaling logic.

### Tile Aspect Ratio Awareness

A more sophisticated approach could detect tile sprite aspect ratio and adjust scaling accordingly. This would handle non-square isometric sprites better.

**Current Status:** Not needed for typical use cases. Can be implemented if users request it.

---

## Additional Notes

### Related Functions

- `GetBrushWidth()` (line 1460) - Returns `GetSourceInkLayer()->GetLayerWidth()`
- `GetBrushHeight()` (line 1489) - Returns `GetSourceInkLayer()->GetLayerHeight()`
- `GetCursorWidth()` / `GetCursorHeight()` (lines 1518-1528) - Wrap brush dimensions

These all depend on the preview component size, which is now correctly set by the fix.

### Suspicious Line (Line 1155)

There's also this interesting line that might need review in the future:
```cpp
PreviewLayer->SetCell(X * Scale.X, Y * Scale.Y + Scale.Y - 1, TileInfo);
```

The `+ Scale.Y - 1` offset seems suspicious and might be related to coordinate system issues. However, the current fix resolves the main bug without needing to modify this.

---

## Verification Checklist

After implementing this fix:

- [x] Isometric diamond mode: 64×64 sprite on 32×16 grid shows 2×2 preview
- [x] Isometric diamond mode: No double/ghost indicators
- [x] Painting tiles works correctly with new preview
- [x] Fix confirmed working by user

---

**Status:** ✅ **FIXED AND WORKING**  
**Implemented:** 2025-12-07  
**Tested By User:** ✅ Confirmed working  
**Ready for Production:** Yes (after plugin rebuild)
