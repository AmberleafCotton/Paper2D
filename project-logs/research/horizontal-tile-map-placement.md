# Horizontal Tile Map Placement - Landscape Style

## Critical Requirement

**The tile map must be placed horizontally (like a floor/landscape), not vertically.**

This is essential for:
- ✅ **Raycasts** - Need to hit tiles from above (downward raycasts)
- ✅ **Gameplay** - Units/buildings placed on flat horizontal surface
- ✅ **Navigation** - Pathfinding on horizontal plane
- ✅ **Physics** - Gravity and collisions work with horizontal surface
- ✅ **Actor Placement** - Actors spawn on horizontal ground

## Paper2D Coordinate System

Paper2D uses a **2D coordinate system** that gets transformed to 3D:

### Paper2D Axes (Default)
- **PaperAxisX** = `FVector(1, 0, 0)` (Right)
- **PaperAxisY** = `FVector(0, 1, 0)` (Forward)
- **PaperAxisZ** = `FVector(0, 0, 1)` (Up)

### Default Paper2D Orientation
By default, Paper2D tile maps are designed for **side-scrolling** (vertical):
- Tile map plane is in **X-Z plane** (vertical wall)
- Y-axis is depth
- This is **NOT suitable** for top-down/isometric games

## Solution: Component Transform Rotation

The `UPaperTileMapComponent` is a `UMeshComponent`, which means it has a **world transform** (location, rotation, scale).

### How Tile Positions Are Calculated

```cpp
// PaperTileMapComponent.cpp - GetTileCenterPosition()
FVector UPaperTileMapComponent::GetTileCenterPosition(int32 TileX, int32 TileY, int32 LayerIndex, bool bWorldSpace) const
{
    FVector Result = TileMap->GetTileCenterInLocalSpace(TileX, TileY, LayerIndex);
    
    if (bWorldSpace)
    {
        Result = GetComponentTransform().TransformPosition(Result);  // ← TRANSFORM APPLIED HERE
    }
    return Result;
}
```

**Key Point:** The component's transform is applied to local tile positions, so we can **rotate the component** to make the tile map horizontal.

## Horizontal Placement Setup

### Option 1: Rotate Component in Editor (Recommended)

1. **Place Tile Map Actor** in level
2. **Rotate the Actor/Component:**
   - **Pitch: -90°** (rotate around X-axis to lay flat)
   - Or **Roll: -90°** (rotate around Z-axis)
   - Or **Yaw: 90°** then **Pitch: -90°** (depending on desired orientation)

3. **Result:**
   - Tile map plane is now horizontal (parallel to X-Y plane)
   - Z-axis is up (normal Unreal convention)
   - Raycasts from above will hit tiles correctly

### Option 2: Set Rotation in Code

```cpp
// In actor constructor or BeginPlay
UPaperTileMapComponent* TileMapComponent = GetComponentByClass<UPaperTileMapComponent>();
if (TileMapComponent)
{
    // Rotate to horizontal (pitch -90 degrees)
    FRotator HorizontalRotation(-90.0f, 0.0f, 0.0f);
    TileMapComponent->SetWorldRotation(HorizontalRotation);
    
    // Or set actor rotation
    SetActorRotation(HorizontalRotation);
}
```

### Option 3: Create Helper Function

```cpp
// In TerrainActorManager or Blueprint Library
UFUNCTION(BlueprintCallable, Category="Terrain")
void SetTileMapHorizontal(UPaperTileMapComponent* TileMapComponent)
{
    if (TileMapComponent)
    {
        // Rotate component to horizontal orientation
        FRotator HorizontalRotation(-90.0f, 0.0f, 0.0f);
        TileMapComponent->SetWorldRotation(HorizontalRotation);
    }
}
```

## Coordinate System After Rotation

### Before Rotation (Default - Vertical)
```
     Z (Up)
     |
     |____ X (Right)
    /
   Y (Forward)
   
Tile map plane: X-Z (vertical wall)
```

### After Rotation (Horizontal - Landscape)
```
     Z (Up)
     |
     |____ X (Right)
    /
   Y (Forward)
   
Tile map plane: X-Y (horizontal floor)
Z-axis is up (normal Unreal convention)
```

## Raycast Compatibility

### Downward Raycasts (From Above)

```cpp
// Raycast from above to hit tile map
FVector StartLocation = ActorLocation + FVector(0, 0, 1000);  // Above
FVector EndLocation = ActorLocation + FVector(0, 0, -1000);   // Below

FHitResult HitResult;
if (GetWorld()->LineTraceSingleByChannel(
    HitResult,
    StartLocation,
    EndLocation,
    ECC_Visibility))
{
    // HitResult.Location is on horizontal tile map
    // HitResult.Normal should be (0, 0, 1) - pointing up
}
```

### Tile Position to World Space

```cpp
// Get tile center in world space (already accounts for component rotation)
FVector TileWorldPos = TileMapComponent->GetTileCenterPosition(
    TileX, TileY, LayerIndex, true);  // bWorldSpace = true

// This position is on the horizontal plane
// Z-coordinate is the height of the tile map
```

## Actor Placement on Horizontal Tiles

### Spawning Actors at Tile Positions

```cpp
// Get tile center in world space (already horizontal if component is rotated)
FVector TileWorldPos = TileMapComponent->GetTileCenterPosition(
    TileX, TileY, LayerIndex, true);

// Spawn actor at this position
// Actor will be on horizontal surface
AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(
    ActorClass,
    TileWorldPos,
    FRotator::ZeroRotator  // Actor rotation (can be adjusted)
);
```

### Ensuring Actor is on Ground

```cpp
FVector TileWorldPos = TileMapComponent->GetTileCenterPosition(
    TileX, TileY, LayerIndex, true);

// Optional: Raycast down to find exact ground position
FVector RayStart = TileWorldPos + FVector(0, 0, 100);
FVector RayEnd = TileWorldPos + FVector(0, 0, -100);

FHitResult HitResult;
if (GetWorld()->LineTraceSingleByChannel(
    HitResult, RayStart, RayEnd, ECC_Visibility))
{
    TileWorldPos = HitResult.Location;
}

// Spawn actor
AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(
    ActorClass,
    TileWorldPos,
    FRotator::ZeroRotator
);
```

## Isometric Diamond Projection + Horizontal Placement

### Isometric Diamond on Horizontal Plane

When using `ETileMapProjectionMode::IsometricDiamond` with horizontal placement:

1. **Tile positions** are calculated in local space (isometric diamond layout)
2. **Component transform** rotates the entire tile map to horizontal
3. **Result:** Isometric diamond tiles on horizontal floor

### Visual Result

```
Top-Down View (looking down Z-axis):
     /\
    /  \
   /    \
  /      \
 /        \
```

Tiles are laid out in isometric diamond pattern, but the **entire plane is horizontal**.

## Collision and Physics

### Collision Geometry

- Collision is generated in **local space** (isometric diamond layout)
- Component transform rotates collision to match tile map orientation
- **Result:** Collision is horizontal (suitable for ground)

### Physics Queries

```cpp
// Sweep test on horizontal tile map
FVector Start = ActorLocation;
FVector End = ActorLocation + MovementDirection;
FCollisionShape CollisionShape = FCollisionShape::MakeSphere(50.0f);

FHitResult HitResult;
if (GetWorld()->SweepSingleByChannel(
    HitResult,
    Start,
    End,
    FQuat::Identity,
    ECC_Pawn,
    CollisionShape))
{
    // Hit horizontal tile map
}
```

## Implementation Notes

### 1. Component vs Actor Rotation

- **Component Rotation:** Rotates just the tile map component
- **Actor Rotation:** Rotates the entire actor (if component is root)
- **Recommendation:** Rotate the component directly for clarity

### 2. Preserving Isometric Layout

- Isometric diamond layout is calculated in **local space**
- Component rotation doesn't affect the isometric math
- Only the **final world position** is rotated
- **Result:** Isometric tiles remain isometric, just rotated to horizontal

### 3. Editor Workflow

1. Create tile map asset (isometric diamond projection)
2. Place tile map actor in level
3. **Rotate actor/component to horizontal** (pitch -90°)
4. Paint tiles as normal
5. Actors spawned at tile positions will be on horizontal surface

### 4. Blueprint Integration

```cpp
// Blueprint-callable function to ensure horizontal placement
UFUNCTION(BlueprintCallable, Category="Terrain")
void EnsureHorizontalPlacement(UPaperTileMapComponent* TileMapComponent)
{
    if (!TileMapComponent)
        return;
    
    // Get current rotation
    FRotator CurrentRotation = TileMapComponent->GetComponentRotation();
    
    // Check if already horizontal (pitch should be -90 or 90)
    float Pitch = CurrentRotation.Pitch;
    if (FMath::Abs(FMath::Abs(Pitch) - 90.0f) > 1.0f)
    {
        // Not horizontal, rotate to horizontal
        FRotator HorizontalRotation(-90.0f, CurrentRotation.Yaw, CurrentRotation.Roll);
        TileMapComponent->SetWorldRotation(HorizontalRotation);
    }
}
```

## Verification

### Check if Tile Map is Horizontal

```cpp
// Get tile positions
FVector Tile1Pos = TileMapComponent->GetTileCenterPosition(0, 0, 0, true);
FVector Tile2Pos = TileMapComponent->GetTileCenterPosition(1, 0, 0, true);
FVector Tile3Pos = TileMapComponent->GetTileCenterPosition(0, 1, 0, true);

// Calculate normal of tile map plane
FVector V1 = Tile2Pos - Tile1Pos;
FVector V2 = Tile3Pos - Tile1Pos;
FVector Normal = FVector::CrossProduct(V1, V2).GetSafeNormal();

// Normal should be approximately (0, 0, 1) for horizontal
// Dot product with up vector should be close to 1.0
float DotWithUp = FVector::DotProduct(Normal, FVector::UpVector);
bool bIsHorizontal = FMath::Abs(DotWithUp - 1.0f) < 0.1f;
```

## Summary

✅ **Solution:** Rotate `UPaperTileMapComponent` to horizontal orientation
✅ **Method:** Set component rotation to pitch -90° (or equivalent)
✅ **Result:** Tile map plane is horizontal, suitable for:
   - Downward raycasts
   - Horizontal actor placement
   - Ground-based gameplay
   - Navigation/pathfinding

✅ **Isometric Diamond:** Works perfectly with horizontal placement
✅ **Actor Placement:** Actors spawn on horizontal surface at tile positions
✅ **No Code Changes Needed:** Just rotate the component in editor or via code

