# Landscape Isometric Projection - Analysis & Implementation

## Your Camera Setup

- **Orthographic Camera**
- **Angle: 25.565°** (elevation)
- **Tilt: 45°** (rotation around vertical axis)
- **Result:** Top-down isometric view looking at horizontal terrain

## Code Differences: Orthogonal vs IsometricDiamond

### Orthogonal Projection

```cpp
// GetTileToLocalParameters() - Orthogonal
OutCornerPosition = -(TileWidthInUU * PaperAxisX * 0.5f) + (TileHeightInUU * PaperAxisY * 0.5f);
OutStepX = PaperAxisX * TileWidthInUU;           // Move right by full tile width
OutStepY = -PaperAxisY * TileHeightInUU;        // Move down by full tile height
```

**Grid Layout:**
```
[0,0] [1,0] [2,0] [3,0]
[0,1] [1,1] [2,1] [3,1]
[0,2] [1,2] [2,2] [3,2]
```

**Tile Shape:** Rectangle (square when TileWidth == TileHeight)

**Visual:**
```
┌───┐┌───┐┌───┐
│   ││   ││   │
└───┘└───┘└───┘
┌───┐┌───┐┌───┐
│   ││   ││   │
└───┘└───┘└───┘
```

### IsometricDiamond Projection

```cpp
// GetTileToLocalParameters() - IsometricDiamond
OutCornerPosition = (TileHeightInUU * PaperAxisY * 0.5f);
OutStepX = (TileWidthInUU * PaperAxisX * 0.5f) - (TileHeightInUU * PaperAxisY * 0.5f);
OutStepY = (TileWidthInUU * PaperAxisX * -0.5f) - (TileHeightInUU * PaperAxisY * 0.5f);
```

**Grid Layout:**
```
      [0,0]
   [0,1] [1,0]
[0,2] [1,1] [2,0]
   [1,2] [2,1]
      [2,2]
```

**Tile Shape:** Diamond (rotated 45°)

**Visual:**
```
    ◇
   ◇ ◇
  ◇ ◇ ◇
   ◇ ◇
    ◇
```

**Key Difference:**
- **StepX** moves: `+0.5*Width` in X, `-0.5*Height` in Y (diagonal up-right)
- **StepY** moves: `-0.5*Width` in X, `-0.5*Height` in Y (diagonal up-left)
- Creates diamond grid pattern

## What Grid Do You Need?

### For Orthographic Camera (25.565°, 45° Tilt)

**You need: IsometricDiamond projection** ✅

**Why:**
1. Camera is at an angle (not top-down)
2. Tiles need to be diamond-shaped to look correct
3. Grid must be diamond-patterned

**Tile Requirements:**
- **Tile Shape:** Diamond (isometric tile sprite)
- **Tile Width:** Usually 2x Tile Height (e.g., 128x64 pixels)
- **Grid Pattern:** Diamond layout (IsometricDiamond mode)

### Tile Appearance

With your camera setup:
- **Top edge** of diamond tile faces camera
- **Bottom edge** faces away
- **Left/Right edges** are at 45° angles
- Creates classic isometric look

## Do You Need a New Projection Mode?

### Option 1: Use Existing IsometricDiamond (Recommended)

**Just use `ETileMapProjectionMode::IsometricDiamond`** ✅

**Why it works:**
- Already creates diamond grid
- Tiles are diamond-shaped
- Works with orthographic camera
- No code changes needed

**Setup:**
1. Set `ProjectionMode = IsometricDiamond`
2. Use diamond-shaped tiles (128x64 or similar)
3. Place tile map horizontally (rotate component -90°)
4. Camera at 25.565° angle, 45° tilt

### Option 2: Create LandscapeIsometric Mode

**Only if you need different grid calculations**

**When you'd need this:**
- Different step vectors than IsometricDiamond
- Custom tile positioning
- Special grid alignment

**Implementation:**
```cpp
// In PaperTileMap.h - Add to enum
namespace ETileMapProjectionMode
{
    enum Type : int
    {
        Orthogonal,
        IsometricDiamond,
        LandscapeIsometric,  // NEW
        // ...
    };
}

// In PaperTileMap.cpp - GetTileToLocalParameters()
case ETileMapProjectionMode::LandscapeIsometric:
    // Same as IsometricDiamond, or customize if needed
    OutCornerPosition = (TileHeightInUU * PaperAxisY * 0.5f);
    OutStepX = (TileWidthInUU * PaperAxisX * 0.5f) - (TileHeightInUU * PaperAxisY * 0.5f);
    OutStepY = (TileWidthInUU * PaperAxisX * -0.5f) - (TileHeightInUU * PaperAxisY * -0.5f);
    break;
```

**But:** IsometricDiamond should work fine for your use case!

## Understanding Your Setup

### Camera Configuration

**Orthographic Camera:**
- **Projection:** Orthographic (no perspective)
- **Angle:** 25.565° (elevation from horizontal)
- **Tilt:** 45° (rotation around vertical)

**Visual Result:**
```
     Camera (looking down at angle)
          \
           \
            \
             \
              ──────── Terrain (horizontal)
```

### Tile Map Setup

1. **Projection Mode:** `IsometricDiamond`
2. **Component Rotation:** Horizontal (pitch -90°)
3. **Tile Shape:** Diamond (128x64 pixels typical)
4. **Grid:** Diamond pattern

### How Tiles Look

**From Camera View:**
```
    ◇     ◇     ◇
   ◇ ◇   ◇ ◇   ◇ ◇
  ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇
   ◇ ◇   ◇ ◇   ◇ ◇
    ◇     ◇     ◇
```

**In 3D Space (Horizontal):**
- Tiles are flat on X-Y plane
- Z-axis is up
- Diamond shape creates isometric illusion from camera angle

## Tile Dimensions

### Standard Isometric Tile Ratios

**2:1 Ratio (Most Common):**
- **Tile Width:** 128 pixels
- **Tile Height:** 64 pixels
- **Aspect Ratio:** 2:1

**Why 2:1:**
- Creates perfect diamond when rotated 45°
- Matches isometric projection math
- Standard in isometric games

### Your Tile Requirements

**For 25.565° camera angle:**
- Use **2:1 ratio** tiles (128x64)
- Or adjust based on your exact camera angle
- Test and adjust `PixelsPerUnrealUnit` for correct scale

## Implementation Recommendation

### ✅ Use Existing IsometricDiamond Mode

**Steps:**
1. **Set Projection Mode:**
   ```cpp
   TileMap->ProjectionMode = ETileMapProjectionMode::IsometricDiamond;
   ```

2. **Use Diamond Tiles:**
   - Tile Width: 128 pixels (or 2x height)
   - Tile Height: 64 pixels
   - Shape: Diamond (isometric sprite)

3. **Place Horizontally:**
   ```cpp
   // Rotate component to horizontal
   TileMapComponent->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));
   ```

4. **Configure Camera:**
   - Orthographic projection
   - Angle: 25.565°
   - Tilt: 45°

### Result

- ✅ Diamond grid pattern
- ✅ Tiles fit correctly
- ✅ No rotation needed (grid is already isometric)
- ✅ Works with orthographic camera
- ✅ Horizontal placement for raycasts

## Code Comparison Summary

| Aspect | Orthogonal | IsometricDiamond |
|--------|-----------|------------------|
| **StepX** | `PaperAxisX * Width` | `0.5*Width*X - 0.5*Height*Y` |
| **StepY** | `-PaperAxisY * Height` | `-0.5*Width*X - 0.5*Height*Y` |
| **Grid** | Square/Rectangle | Diamond |
| **Tile Shape** | Rectangle | Diamond |
| **Use Case** | Top-down, side-scrolling | Isometric games |

## Answer to Your Question

**"What kind of grid do I need?"**

✅ **IsometricDiamond grid** - Already exists in Paper2D!

**"How would tiles look?"**

✅ **Diamond-shaped tiles** (128x64 pixels typical)
- Top edge faces camera
- Bottom edge faces away
- Left/Right edges at 45° angles
- Creates isometric illusion

**"Do I need a new projection mode?"**

❌ **No** - `IsometricDiamond` should work perfectly for your camera setup!

**"What about the 45° rotation?"**

✅ **Not needed** - IsometricDiamond already creates the diamond grid. Just:
1. Use IsometricDiamond mode
2. Place tile map horizontally
3. Use diamond-shaped tiles
4. Camera at your angle

## Next Steps

1. **Test with IsometricDiamond mode**
2. **Use diamond tiles** (2:1 ratio)
3. **Place horizontally** (rotate component)
4. **Adjust camera** to 25.565° angle, 45° tilt
5. **Fine-tune** `PixelsPerUnrealUnit` for correct scale

If IsometricDiamond doesn't match your exact needs, then we can create a custom `LandscapeIsometric` mode with adjusted step vectors.

