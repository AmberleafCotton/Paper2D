# Landscape Isometric Projection Mode - Implementation Plan

## Goal

Create a new `LandscapeIsometric` projection mode that:
- Uses **exact same grid math as Orthogonal** (simple square grid)
- Designed for **horizontal placement** (flat on ground, like Landscape)
- **Rotate component 45°** to get isometric visual look from orthographic camera
- Works with orthographic camera at 25.565° angle
- Makes physics, raycasts, and actor placement easy

**Key Point:** This is Orthogonal grid, but designed to be placed horizontally and rotated 45° for isometric visual. The grid itself is simple squares - the isometric look comes from the 45° rotation.

## Why This is Needed

**Current Orthogonal problems:**
- ❌ Designed for vertical placement (side-scrolling)
- ❌ When placed horizontally, doesn't look right
- ❌ No built-in support for 45° rotation workflow

**Current IsometricDiamond problems:**
- ❌ Tile map is vertically placed (hard for physics)
- ❌ Diamond grid math is complex
- ❌ Hard to know where things will end up
- ❌ Camera must look top-down (no angle)

**New LandscapeIsometric benefits:**
- ✅ **Same simple grid as Orthogonal** (square tiles, easy math)
- ✅ **Designed for horizontal placement** (flat on ground)
- ✅ **Rotate 45° for isometric visual** (looks like isometric from camera)
- ✅ **Camera at 25.565° angle works perfectly**
- ✅ **Easy physics, raycasts, actor placement** (horizontal surface)
- ✅ **Simple grid logic** (just like Orthogonal, but horizontal + rotated)

## Implementation

### Phase 1: Add Enum Value

**File:** `Plugins/Paper2D/Source/Paper2D/Classes/PaperTileMap.h`

```cpp
// The different kinds of projection modes supported
UENUM()
namespace ETileMapProjectionMode
{
    enum Type : int
    {
        /** Square tile layout */
        Orthogonal,

        // Isometric tile layout (shaped like a diamond) */
        IsometricDiamond,

        /** Landscape isometric - orthogonal grid placed horizontally, rotated 45° for isometric look */
        LandscapeIsometric,

        /** Isometric tile layout (roughly in a square with alternating rows staggered).  Warning: Not fully supported yet. */
        IsometricStaggered,

        /** Hexagonal tile layout (roughly in a square with alternating rows staggered).  Warning: Not fully supported yet. */
        HexagonalStaggered
    };
}
```

### Phase 2: Implement Grid Calculations

**File:** `Plugins/Paper2D/Source/Paper2D/Private/PaperTileMap.cpp`

#### 2.1: GetTileToLocalParameters()

**Location:** Around line 305

```cpp
void UPaperTileMap::GetTileToLocalParameters(FVector& OutCornerPosition, FVector& OutStepX, FVector& OutStepY, FVector& OutOffsetYFactor) const
{
    const float UnrealUnitsPerPixel = GetUnrealUnitsPerPixel();
    const float TileWidthInUU = TileWidth * UnrealUnitsPerPixel;
    const float TileHeightInUU = TileHeight * UnrealUnitsPerPixel;

    switch (ProjectionMode)
    {
    case ETileMapProjectionMode::Orthogonal:
    default:
        OutCornerPosition = -(TileWidthInUU * PaperAxisX * 0.5f) + (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = FVector::ZeroVector;
        OutStepX = PaperAxisX * TileWidthInUU;
        OutStepY = -PaperAxisY * TileHeightInUU;
        break;
    case ETileMapProjectionMode::IsometricDiamond:
        OutCornerPosition = (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = FVector::ZeroVector;
        OutStepX = (TileWidthInUU * PaperAxisX * 0.5f) - (TileHeightInUU * PaperAxisY * 0.5f);
        OutStepY = (TileWidthInUU * PaperAxisX * -0.5f) - (TileHeightInUU * PaperAxisY * 0.5f);
        break;
    case ETileMapProjectionMode::LandscapeIsometric:
        // EXACT SAME as Orthogonal - simple square grid
        // The isometric look comes from rotating the component 45°
        // This is just Orthogonal grid, but designed for horizontal + 45° rotation
        OutCornerPosition = -(TileWidthInUU * PaperAxisX * 0.5f) + (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = FVector::ZeroVector;
        OutStepX = PaperAxisX * TileWidthInUU;        // Same as Orthogonal
        OutStepY = -PaperAxisY * TileHeightInUU;     // Same as Orthogonal
        break;
    case ETileMapProjectionMode::HexagonalStaggered:
    case ETileMapProjectionMode::IsometricStaggered:
        OutCornerPosition = -(TileWidthInUU * PaperAxisX * 0.5f) + (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = 0.5f * TileWidthInUU * PaperAxisX;
        OutStepX = PaperAxisX * TileWidthInUU;
        OutStepY = 0.5f * -PaperAxisY * TileHeightInUU;
        break;
    }
}
```

#### 2.2: GetLocalToTileParameters()

**Location:** Around line 336

```cpp
void UPaperTileMap::GetLocalToTileParameters(FVector& OutCornerPosition, FVector& OutStepX, FVector& OutStepY, FVector& OutOffsetYFactor) const
{
    const float UnrealUnitsPerPixel = GetUnrealUnitsPerPixel();
    const float TileWidthInUU = TileWidth * UnrealUnitsPerPixel;
    const float TileHeightInUU = TileHeight * UnrealUnitsPerPixel;

    switch (ProjectionMode)
    {
    case ETileMapProjectionMode::Orthogonal:
    default:
        OutCornerPosition = -(TileWidthInUU * PaperAxisX * 0.5f) + (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = FVector::ZeroVector;
        OutStepX = PaperAxisX / TileWidthInUU;
        OutStepY = -PaperAxisY / TileHeightInUU;
        break;
    case ETileMapProjectionMode::IsometricDiamond:
        OutCornerPosition = (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = FVector::ZeroVector;
        OutStepX = (PaperAxisX / TileWidthInUU) - (PaperAxisY / TileHeightInUU);
        OutStepY = (-PaperAxisX / TileWidthInUU) - (PaperAxisY / TileHeightInUU);
        break;
    case ETileMapProjectionMode::LandscapeIsometric:
        // EXACT SAME as Orthogonal - simple square grid
        OutCornerPosition = -(TileWidthInUU * PaperAxisX * 0.5f) + (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = FVector::ZeroVector;
        OutStepX = PaperAxisX / TileWidthInUU;        // Same as Orthogonal
        OutStepY = -PaperAxisY / TileHeightInUU;   // Same as Orthogonal
        break;
    case ETileMapProjectionMode::HexagonalStaggered:
    case ETileMapProjectionMode::IsometricStaggered:
        OutCornerPosition = -(TileWidthInUU * PaperAxisX * 0.5f) + (TileHeightInUU * PaperAxisY * 0.5f);
        OutOffsetYFactor = 0.5f * TileWidthInUU * PaperAxisX;
        OutStepX = PaperAxisX / TileWidthInUU;
        OutStepY = -PaperAxisY / TileHeightInUU;
        break;
    }
}
```

#### 2.3: GetTilePositionInLocalSpace()

**Location:** Around line 416

```cpp
FVector UPaperTileMap::GetTilePositionInLocalSpace(float TileX, float TileY, int32 LayerIndex) const
{
    FVector CornerPosition;
    FVector OffsetYFactor;
    FVector StepX;
    FVector StepY;

    GetTileToLocalParameters(/*out*/ CornerPosition, /*out*/ StepX, /*out*/ StepY, /*out*/ OffsetYFactor);

    FVector TotalOffset;
    switch (ProjectionMode)
    {
    case ETileMapProjectionMode::Orthogonal:
    default:
        TotalOffset = CornerPosition;
        break;
    case ETileMapProjectionMode::IsometricDiamond:
        TotalOffset = CornerPosition;
        break;
    case ETileMapProjectionMode::LandscapeIsometric:
        // EXACT SAME as Orthogonal - no special offset
        TotalOffset = CornerPosition;
        break;
    case ETileMapProjectionMode::HexagonalStaggered:
    case ETileMapProjectionMode::IsometricStaggered:
        TotalOffset = CornerPosition + ((int32)TileY & 1) * OffsetYFactor;
        break;
    }

    const FVector PartialX = TileX * StepX;
    const FVector PartialY = TileY * StepY;

    const float TotalSeparation = (SeparationPerLayer * LayerIndex) + (SeparationPerTileX * TileX) + (SeparationPerTileY * TileY);
    const FVector PartialZ = TotalSeparation * PaperAxisZ;

    const FVector LocalPos(PartialX + PartialY + PartialZ + TotalOffset);

    return LocalPos;
}
```

#### 2.4: GetTilePolygon()

**Location:** Around line 452

```cpp
void UPaperTileMap::GetTilePolygon(int32 TileX, int32 TileY, int32 LayerIndex, TArray<FVector>& LocalSpacePoints) const
{
    switch (ProjectionMode)
    {
    case ETileMapProjectionMode::Orthogonal:
    case ETileMapProjectionMode::IsometricDiamond:
    case ETileMapProjectionMode::LandscapeIsometric:  // Same as Orthogonal - square tiles
    default:
        LocalSpacePoints.Add(GetTilePositionInLocalSpace(TileX, TileY, LayerIndex));
        LocalSpacePoints.Add(GetTilePositionInLocalSpace(TileX + 1, TileY, LayerIndex));
        LocalSpacePoints.Add(GetTilePositionInLocalSpace(TileX + 1, TileY + 1, LayerIndex));
        LocalSpacePoints.Add(GetTilePositionInLocalSpace(TileX, TileY + 1, LayerIndex));
        break;

    // ... rest of cases ...
}
```

#### 2.5: GetTileCenterInLocalSpace()

**Location:** Around line 515

```cpp
FVector UPaperTileMap::GetTileCenterInLocalSpace(float TileX, float TileY, int32 LayerIndex) const
{
    switch (ProjectionMode)
    {
    case ETileMapProjectionMode::Orthogonal:
    case ETileMapProjectionMode::LandscapeIsometric:  // Same as Orthogonal
    default:
        return GetTilePositionInLocalSpace(TileX + 0.5f, TileY + 0.5f, LayerIndex);

    case ETileMapProjectionMode::IsometricDiamond:
        return GetTilePositionInLocalSpace(TileX + 0.5f, TileY + 0.5f, LayerIndex);

    // ... rest of cases ...
}
```

### Phase 3: Collision Building

**File:** `Plugins/Paper2D/Source/Paper2D/Private/PaperTileLayer.cpp`

**Location:** Around line 262

```cpp
FVector ProjectionOffset;
switch (TileMap->ProjectionMode)
{
case ETileMapProjectionMode::Orthogonal: // General offset used by default.
default:
    ProjectionOffset.X = TileWidth * CellX;
    ProjectionOffset.Y = TileHeight * -CellY;
    break;

case ETileMapProjectionMode::IsometricDiamond: // Offset to compensate for the Isometric Scatter of the grid.
    ProjectionOffset.X = (CellX * TileWidth * 0.5f) + -(CellY * TileWidth * 0.5f);
    ProjectionOffset.Y = -(CellX * TileHeight * 0.5f) - (CellY * TileHeight * 0.5f);
    break;

    case ETileMapProjectionMode::LandscapeIsometric:
        // EXACT SAME as Orthogonal - simple square grid
        ProjectionOffset.X = TileWidth * CellX;
        ProjectionOffset.Y = TileHeight * -CellY;
        break;

case ETileMapProjectionMode::IsometricStaggered: // Isometric & Hexagonal share the same offsets.
case ETileMapProjectionMode::HexagonalStaggered:
    ProjectionOffset.X = (CellX * TileWidth) + CellY % 2 * (TileWidth * 0.5f);
    ProjectionOffset.Y = -CellY * (TileHeight * 0.5f);
    break;
}
```

### Phase 4: Rendering

**File:** `Plugins/Paper2D/Source/Paper2D/Private/PaperTileMapComponent.cpp`

**Location:** Around line 344

```cpp
switch (TileMap->ProjectionMode)
{
case ETileMapProjectionMode::Orthogonal:
default:
    EffectiveTopLeftCorner = CornerOffset;
    break;
case ETileMapProjectionMode::IsometricDiamond:
    EffectiveTopLeftCorner = CornerOffset - 0.5f * StepPerTileX + 0.5f * StepPerTileY;
    break;
    case ETileMapProjectionMode::LandscapeIsometric:
        // EXACT SAME as Orthogonal - simple square grid
        EffectiveTopLeftCorner = CornerOffset;
        break;
case ETileMapProjectionMode::IsometricStaggered:
case ETileMapProjectionMode::HexagonalStaggered:
    EffectiveTopLeftCorner = CornerOffset + (Y & 1) * OffsetYFactor;
    break;
}
```

### Phase 5: Bounds Calculation

**File:** `Plugins/Paper2D/Source/Paper2D/Private/PaperTileMap.cpp`

**Location:** Around line 576

```cpp
case ETileMapProjectionMode::Orthogonal:
case ETileMapProjectionMode::LandscapeIsometric:  // Same as Orthogonal
default:
{
    const FVector BottomLeft((-0.5f) * TileWidthInUU, -HalfThickness - Depth, -(MapHeight - 0.5f) * TileHeightInUU);
    const FVector Dimensions(MapWidth * TileWidthInUU, Depth + 2 * HalfThickness, MapHeight * TileHeightInUU);

    const FBox Box(BottomLeft, BottomLeft + Dimensions);
    return FBoxSphereBounds(Box);
}
```

## Usage

### Setup Steps

1. **Create Tile Map:**
   - Set `ProjectionMode = LandscapeIsometric`
   - Use square tiles (e.g., 64x64 or 128x128 pixels)

2. **Place Horizontally:**
   ```cpp
   // Rotate to horizontal (pitch -90°)
   TileMapComponent->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));
   ```

3. **Rotate 45° for Isometric Look:**
   ```cpp
   // Rotate 45° around Z-axis (yaw) for isometric visual
   FRotator CurrentRotation = TileMapComponent->GetComponentRotation();
   FRotator IsometricRotation(CurrentRotation.Pitch, CurrentRotation.Yaw + 45.0f, CurrentRotation.Roll);
   TileMapComponent->SetWorldRotation(IsometricRotation);
   ```

4. **Camera Setup:**
   - Orthographic camera
   - Angle: 25.565°
   - Tilt: 45° (or adjust based on rotation)

### Result

- ✅ **Horizontal tile map** (flat on ground, easy physics, raycasts)
- ✅ **Simple square grid** (exact same as Orthogonal - easy to work with)
- ✅ **Isometric visual look** (from 45° rotation - looks like isometric from camera)
- ✅ **Camera at 25.565° angle** works correctly
- ✅ **Easy actor placement** (horizontal surface, simple grid coordinates)

**The Magic:** 
- Grid is simple squares (like Orthogonal)
- Place horizontally (flat on ground)
- Rotate 45° (yaw)
- Camera at 25.565° angle
- **Result:** Looks like isometric, but grid is simple squares!

## Files to Modify

1. `Plugins/Paper2D/Source/Paper2D/Classes/PaperTileMap.h` - Add enum value
2. `Plugins/Paper2D/Source/Paper2D/Private/PaperTileMap.cpp` - Implement grid calculations
3. `Plugins/Paper2D/Source/Paper2D/Private/PaperTileLayer.cpp` - Collision offsets
4. `Plugins/Paper2D/Source/Paper2D/Private/PaperTileMapComponent.cpp` - Rendering

## Testing

1. Create tile map with `LandscapeIsometric` mode
2. Place horizontally (pitch -90°)
3. Rotate 45° (yaw +45°)
4. Verify grid is square
5. Verify tiles align correctly
6. Test physics/raycasts work
7. Test actor placement

