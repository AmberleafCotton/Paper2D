# Populous-Style Height Grid System - Research & Implementation Plan

## Overview

Analysis of a Populous-style 2D grid system with height variations (from [Pakz001/html5examples/populous](https://github.com/Pakz001/html5examples/tree/master/Games/populous)) and how to implement similar functionality in Unreal Engine using Paper2D.

## Populous Game Concept

Populous is a god game where players manipulate terrain height on a grid-based map. Key features:
- **Grid-based terrain** - 2D grid where each cell has a height value
- **Height manipulation** - Raise/lower terrain to create hills, valleys, and plateaus
- **Visual representation** - Height differences visualized through shading, elevation, or 3D projection
- **Gameplay mechanics** - Height affects movement, line of sight, and strategic positioning

## JavaScript Implementation Analysis

Based on the repository structure, the system likely implements:

### Core Components

1. **Grid Data Structure**
   - 2D array storing height values per cell
   - Each cell: `{ x, y, height }`
   - Height typically ranges from 0 to some maximum (e.g., 0-15)

2. **Rendering System**
   - Visual representation of height differences
   - Isometric or orthographic projection
   - Shading/coloring based on height
   - Smooth transitions between height levels

3. **Height Manipulation**
   - Click/drag to raise/lower terrain
   - Brush tools for area modification
   - Constraints (min/max height, smooth transitions)

4. **Game Logic**
   - Pathfinding that considers height
   - Movement costs based on height differences
   - Line of sight calculations

## Unreal Engine Implementation Approaches

### Approach 1: Extend Paper2D Tile Metadata (Recommended)

**Leverage the newly implemented tile metadata system** to store height information.

#### Implementation Steps

1. **Extend FPaperTileMetadata**
   ```cpp
   // In PaperTileLayer.h
   struct FPaperTileMetadata
   {
       // ... existing fields ...
       
       // Height/elevation value (0 = ground level, positive = raised)
       UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile Properties")
       int32 Height;
       
       // Height offset in Unreal units (for visual positioning)
       UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile Properties")
       float HeightOffset;
   };
   ```

2. **Visual Representation**
   - Use `SeparationPerLayer` or custom Z-offset per tile
   - Adjust tile position based on height metadata
   - Use different tile sprites for different height levels
   - Apply shading/materials based on height

3. **Height Manipulation Tools**
   - Add "Raise Terrain" and "Lower Terrain" tools to tile map editor
   - Brush-based height modification
   - Smooth height transitions

4. **Rendering Adjustments**
   - Modify `GetTilePositionInLocalSpace()` to account for height
   - Update collision geometry based on height
   - Adjust sorting/layering for proper visual order

**Pros:**
- Works with existing Paper2D system
- Leverages new metadata system
- Backward compatible (height defaults to 0)
- Blueprint accessible

**Cons:**
- Limited to discrete height values per tile
- May need custom rendering for smooth height transitions

### Approach 2: Custom Height Grid Component

Create a separate component that manages height data independently from Paper2D.

#### Implementation Steps

1. **Create UHeightGridComponent**
   ```cpp
   UCLASS(BlueprintType)
   class UHeightGridComponent : public UActorComponent
   {
       // 2D array of height values
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       TArray<int32> HeightGrid;
       
       // Grid dimensions
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       int32 GridWidth;
       
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       int32 GridHeight;
       
       // Height manipulation
       UFUNCTION(BlueprintCallable)
       void SetHeight(int32 X, int32 Y, int32 Height);
       
       UFUNCTION(BlueprintPure)
       int32 GetHeight(int32 X, int32 Y) const;
   };
   ```

2. **Integration with Paper2D**
   - Sync height grid with tile map dimensions
   - Use height data to adjust tile positions
   - Update tile metadata when height changes

**Pros:**
- Separates height logic from tile rendering
- More flexible for complex height systems
- Can support smooth height interpolation

**Cons:**
- Requires additional component management
- More complex synchronization with tile map

### Approach 3: Procedural Mesh with Height Map

Use Unreal's procedural mesh system to create a 3D terrain from height data.

#### Implementation Steps

1. **Generate Mesh from Height Grid**
   - Create procedural mesh component
   - Generate vertices based on height values
   - Apply tile textures as materials

2. **Height Manipulation**
   - Modify height data
   - Regenerate mesh on changes
   - Smooth height transitions

**Pros:**
- True 3D representation
- Smooth height transitions
- Better for complex terrain

**Cons:**
- More complex implementation
- Less aligned with Paper2D's 2D focus
- Performance considerations

## Recommended Implementation Strategy

### Phase 1: Basic Height Support (Using Metadata)

1. **Extend Tile Metadata**
   - Add `Height` field to `FPaperTileMetadata`
   - Default height = 0 (ground level)

2. **Visual Representation**
   - Use `SeparationPerLayer` or custom offset for height visualization
   - Create height-based tile variants (ground, level 1, level 2, etc.)
   - Apply height offset in `GetTilePositionInLocalSpace()`

3. **Editor Tools**
   - Add "Height" property to Tile Details panel
   - Add "Raise/Lower Terrain" tools to toolbar
   - Visual feedback showing height differences

### Phase 2: Height Manipulation Tools

1. **Brush Tools**
   - Height brush (raise/lower area)
   - Smooth height tool
   - Level terrain tool

2. **Constraints**
   - Min/max height limits
   - Height change validation
   - Undo/redo support

### Phase 3: Gameplay Integration

1. **Pathfinding**
   - Modify pathfinding to consider height
   - Movement costs based on height differences
   - Height-based movement restrictions

2. **Collision**
   - Adjust collision geometry based on height
   - Height-based collision layers

3. **Visual Effects**
   - Height-based shading
   - Fog/atmosphere effects
   - Particle effects at height transitions

## Technical Considerations

### Height Storage

**Option A: Per-Tile Height (Discrete)**
- Each tile has one height value
- Simple, efficient
- Limited to tile-level granularity

**Option B: Per-Vertex Height (Smooth)**
- Height at each corner of tile
- Smooth transitions
- More complex, requires custom mesh

### Height Visualization

1. **Z-Offset Method**
   - Adjust Z position based on height
   - Use `SeparationPerLayer` or custom offset
   - Simple but may cause sorting issues

2. **Sprite Variants**
   - Different sprites for different heights
   - Visual clarity
   - Requires more art assets

3. **Material Shading**
   - Use material parameters for height-based shading
   - Single sprite with dynamic shading
   - Flexible but less clear

### Performance

- Height data is lightweight (int32 per tile)
- Rendering adjustments minimal if using existing systems
- Pathfinding may need optimization for height-aware algorithms

## Integration with Existing Systems

### Tile Metadata System
- Height stored in `FPaperTileMetadata.Height`
- Accessible via Blueprint library functions
- Editable in Tile Details panel

### Paper2D Rendering
- Use existing tile rendering pipeline
- Adjust positions based on height
- Maintain layer sorting

### Editor Tools
- Extend `FEdModeTileMap` with height tools
- Add height visualization in viewport
- Height editing in details panel

## Example Implementation Snippet

```cpp
// Extend FPaperTileMetadata
struct FPaperTileMetadata
{
    // ... existing fields ...
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile Properties")
    int32 Height = 0;  // Height level (0 = ground, positive = raised)
};

// Adjust tile position based on height
FVector UPaperTileMap::GetTilePositionInLocalSpace(float TileX, float TileY, int32 LayerIndex) const
{
    // ... existing calculation ...
    
    // Get height from metadata if available
    if (UPaperTileLayer* Layer = TileLayers[LayerIndex])
    {
        FPaperTileInfo TileInfo = Layer->GetCell(TileX, TileY);
        if (TileInfo.Metadata.IsSet() && TileInfo.Metadata.GetValue().Height > 0)
        {
            const float HeightOffset = TileInfo.Metadata.GetValue().Height * HeightUnitSize;
            LocalPos += PaperAxisZ * HeightOffset;
        }
    }
    
    return LocalPos;
}
```

## References

- [Populous Game Repository](https://github.com/Pakz001/html5examples/tree/master/Games/populous)
- [Unreal Engine Grid Plugin](https://github.com/jinyuliao/Grid)
- [Graph A* Example for Hexagonal Grids](https://github.com/ZioYuri78/GraphAStarExample)
- Paper2D Documentation: `Plugins/Paper2D/Source/Paper2D/Classes/PaperTileMap.h`
- Tile Metadata System: `Plugins/Paper2D/project-logs/tasks/tile-metadata-system-research.md`

## Next Steps

1. **Research Phase**
   - Review Populous repository code structure
   - Analyze height manipulation algorithms
   - Study smooth height transition techniques

2. **Design Phase**
   - Finalize height storage approach
   - Design editor tools UI
   - Plan rendering strategy

3. **Implementation Phase**
   - Extend metadata with height field
   - Implement height visualization
   - Create height manipulation tools
   - Add gameplay integration

