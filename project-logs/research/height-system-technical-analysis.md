# Height System in Paper2D - Deep Technical Analysis

## Executive Summary

**Can we implement height-based terrain in Paper2D?** 

**Short Answer:** Yes, but with significant limitations and trade-offs. The implementation is **technically feasible** but requires **breaking Paper2D's batching optimizations** or using **alternative visualization methods**.

## Paper2D Rendering Architecture

### Current Rendering Pipeline

Paper2D uses a **batched rendering system** for performance:

1. **RebuildRenderData()** (`PaperTileMapComponent.cpp:246`)
   - Iterates through all layers and tiles
   - Groups tiles by texture/material into `FSpriteRenderSection` batches
   - All tiles in a batch share the same Z-position for batching efficiency

2. **Batching Logic** (`PaperTileMapComponent.cpp:395-404`)
   ```cpp
   if ((SourceTexture != LastSourceTexture) || (CurrentBatch == nullptr))
   {
       CurrentBatch = new (Sections) FSpriteRenderSection();
       CurrentBatch->BaseTexture = SourceTexture;
       CurrentDestinationOrigin = TopLeftCornerOfTile.ProjectOnTo(PaperAxisZ);
   }
   ```
   - **Key Issue**: `CurrentDestinationOrigin` is projected onto `PaperAxisZ`
   - This means all tiles in a batch share the same Z coordinate
   - Batching breaks if tiles have different Z positions

3. **Tile Position Calculation** (`PaperTileMap.cpp:416-450`)
   ```cpp
   FVector UPaperTileMap::GetTilePositionInLocalSpace(float TileX, float TileY, int32 LayerIndex) const
   {
       // ... projection mode calculations ...
       
       const float TotalSeparation = (SeparationPerLayer * LayerIndex) + 
                                     (SeparationPerTileX * TileX) + 
                                     (SeparationPerTileY * TileY);
       const FVector PartialZ = TotalSeparation * PaperAxisZ;
       
       return LocalPos;
   }
   ```
   - Currently uses **global** separation values (`SeparationPerLayer`, `SeparationPerTileX/Y`)
   - These are **per-map**, not **per-tile**
   - No per-tile Z-offset support currently

## Implementation Approaches - Detailed Analysis

### Approach 1: Modify GetTilePositionInLocalSpace() (Direct Height)

**Concept:** Add height offset directly to tile position calculation.

#### Implementation

```cpp
// In PaperTileLayer.h - Extend FPaperTileMetadata
struct FPaperTileMetadata
{
    // ... existing fields ...
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Height = 0;  // Height level (0 = ground, positive = raised)
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HeightUnitSize = 50.0f;  // Unreal units per height level
};

// In PaperTileMap.cpp - Modify GetTilePositionInLocalSpace()
FVector UPaperTileMap::GetTilePositionInLocalSpace(float TileX, float TileY, int32 LayerIndex) const
{
    // ... existing calculation ...
    
    // Add height offset from metadata
    float HeightOffset = 0.0f;
    if (TileLayers.IsValidIndex(LayerIndex))
    {
        UPaperTileLayer* Layer = TileLayers[LayerIndex];
        FPaperTileInfo TileInfo = Layer->GetCell((int32)TileX, (int32)TileY);
        
        if (TileInfo.Metadata.IsSet())
        {
            const FPaperTileMetadata& Metadata = TileInfo.Metadata.GetValue();
            HeightOffset = Metadata.Height * Metadata.HeightUnitSize;
        }
    }
    
    const FVector PartialZ = (TotalSeparation * PaperAxisZ) + (HeightOffset * PaperAxisZ);
    
    return LocalPos;
}
```

#### Problems

1. **Batching Breaks** ⚠️
   - Tiles with different heights can't be in the same batch
   - Each height level needs separate batches
   - Performance degradation: More draw calls, less batching efficiency

2. **Rendering Order Issues** ⚠️
   - Higher tiles might render behind lower tiles
   - Need careful sorting/ordering
   - May require per-tile rendering instead of batching

3. **Collision Updates** ⚠️
   - Collision geometry needs to update with height
   - `AugmentBodySetup()` would need height-aware calculations
   - More complex collision generation

#### Performance Impact

- **Before**: 1-5 batches per layer (grouped by texture)
- **After**: Potentially 10-50+ batches (grouped by texture AND height)
- **Draw Call Increase**: 5-10x (depending on height variation)
- **Still Acceptable?** Yes, for small-medium maps (<1000 tiles). Problematic for large maps.

### Approach 2: Per-Tile Rendering (Break Batching)

**Concept:** Force each tile to render individually, allowing per-tile Z-offsets.

#### Implementation

```cpp
// In PaperTileMapComponent.cpp - Modify RebuildRenderData()
// Instead of batching by texture, create separate batches per tile when height varies

for (int32 Y = 0; Y < TileMap->MapHeight; ++Y)
{
    for (int32 X = 0; X < TileMap->MapWidth; ++X)
    {
        FPaperTileInfo TileInfo = Layer->GetCell(X, Y);
        
        // Check if tile has height
        bool bHasHeight = false;
        float HeightOffset = 0.0f;
        if (TileInfo.Metadata.IsSet())
        {
            const FPaperTileMetadata& Metadata = TileInfo.Metadata.GetValue();
            if (Metadata.Height > 0)
            {
                bHasHeight = true;
                HeightOffset = Metadata.Height * Metadata.HeightUnitSize;
            }
        }
        
        // If height varies, create separate batch
        if (bHasHeight || (LastHeight != HeightOffset))
        {
            CurrentBatch = new (Sections) FSpriteRenderSection();
            // ... setup batch ...
            CurrentDestinationOrigin = (TopLeftCornerOfTile + HeightOffset * PaperAxisZ).ProjectOnTo(PaperAxisZ);
        }
        
        // Add vertex with height offset
        FVector TilePosition = TopLeftCornerOfTile + (HeightOffset * PaperAxisZ);
        // ... add vertices ...
    }
}
```

#### Problems

1. **Massive Performance Hit** ❌
   - Every tile becomes a potential batch break
   - Worst case: 1 batch per tile = thousands of draw calls
   - Unacceptable for real-time rendering

2. **Memory Overhead** ❌
   - More render sections = more memory
   - Vertex buffer fragmentation

#### Performance Impact

- **Draw Calls**: 1-5 → 100-1000+ (unacceptable)
- **Not Recommended** for production use

### Approach 3: Height-Based Layer Separation (Recommended)

**Concept:** Use separate layers for different height levels, leverage existing `SeparationPerLayer`.

#### Implementation

```cpp
// Instead of per-tile height, use height layers:
// Layer 0: Height 0 (ground)
// Layer 1: Height 1 (raised level 1)
// Layer 2: Height 2 (raised level 2)
// etc.

// When painting with height:
void FEdModeTileMap::PaintTileWithHeight(int32 X, int32 Y, int32 Height)
{
    // Find or create layer for this height
    int32 TargetLayerIndex = FindOrCreateHeightLayer(Height);
    
    // Paint to that layer
    UPaperTileLayer* HeightLayer = TileMap->TileLayers[TargetLayerIndex];
    HeightLayer->SetCell(X, Y, TileInfo);
}

// Height is encoded in layer index, not tile metadata
// SeparationPerLayer provides visual separation
```

#### Advantages

✅ **Maintains Batching** - Each layer batches normally
✅ **Uses Existing System** - Leverages `SeparationPerLayer`
✅ **Good Performance** - No batching breaks
✅ **Simple Implementation** - Minimal code changes

#### Disadvantages

⚠️ **Layer Management** - Need to manage many layers
⚠️ **Memory Overhead** - One layer per height level
⚠️ **Less Flexible** - Can't have smooth height transitions
⚠️ **Editor Complexity** - Height selection = layer selection

#### Performance Impact

- **Draw Calls**: Same as before (1-5 per height layer)
- **Memory**: ~N layers × tile map size (acceptable for <10 height levels)
- **Best Performance** of all approaches

### Approach 4: Visual-Only Height (No Position Change)

**Concept:** Use visual tricks (shading, sprites, materials) to represent height without changing Z-position.

#### Implementation

```cpp
// Store height in metadata
struct FPaperTileMetadata
{
    int32 Height = 0;
};

// Use material parameters for height-based shading
// In material:
// - Height parameter controls brightness/darkness
// - Higher = brighter (sunlight), Lower = darker (shadow)

// Or use different tile sprites for different heights
// - Ground sprite for height 0
// - Raised sprite for height 1
// - Hill sprite for height 2
```

#### Advantages

✅ **No Batching Issues** - Positions unchanged
✅ **Best Performance** - Zero rendering overhead
✅ **Simple** - Just metadata + visual assets

#### Disadvantages

⚠️ **No True 3D** - Purely visual, no Z-offset
⚠️ **Collision Issues** - Collision doesn't match visuals
⚠️ **Limited Realism** - Can't have true elevation

## Recommended Hybrid Approach

### Phase 1: Visual Height (Quick Win)

1. **Add Height to Metadata**
   ```cpp
   struct FPaperTileMetadata
   {
       int32 Height = 0;
   };
   ```

2. **Height-Based Tile Selection**
   - Different tile sprites for different heights
   - Material shading based on height
   - Visual representation without Z-offset

3. **Editor Tools**
   - Height brush tool
   - Height visualization in viewport
   - Height editing in details panel

**Result:** Functional height system with zero performance impact.

### Phase 2: Optional Z-Offset (Advanced)

1. **Add Height Offset Calculation**
   - Modify `GetTilePositionInLocalSpace()` to add height offset
   - Accept batching performance trade-off
   - Make it optional/toggleable

2. **Height-Aware Batching**
   - Group tiles by (texture, height) instead of just texture
   - More batches, but still reasonable
   - Performance acceptable for medium maps

3. **Collision Updates**
   - Update collision geometry based on height
   - Height-aware pathfinding

**Result:** True 3D height with acceptable performance.

## Technical Challenges & Solutions

### Challenge 1: Batching Performance

**Problem:** Per-tile height breaks texture batching.

**Solution:** 
- Accept more batches (group by texture + height)
- Or use layer-based approach (one layer per height)
- Or visual-only (no Z-offset)

### Challenge 2: Rendering Order

**Problem:** Higher tiles might render behind lower tiles.

**Solution:**
- Sort tiles by height before batching
- Use depth sorting in render pipeline
- Or use separate render passes per height level

### Challenge 3: Collision Geometry

**Problem:** Collision needs to match visual height.

**Solution:**
- Modify `AugmentBodySetup()` to account for height
- Add height offset to collision geometry
- Or disable collision for height-varied tiles (use separate collision system)

### Challenge 4: Editor Visualization

**Problem:** Need to show height differences in editor.

**Solution:**
- Use `SeparationPerLayer` for visual separation
- Or custom viewport rendering
- Or height-based color coding

## Code Modification Points

### 1. Core Position Calculation
**File:** `Plugins/Paper2D/Source/Paper2D/Private/PaperTileMap.cpp`
**Function:** `GetTilePositionInLocalSpace()`
**Change:** Add height offset from metadata

### 2. Rendering Pipeline
**File:** `Plugins/Paper2D/Source/Paper2D/Private/PaperTileMapComponent.cpp`
**Function:** `RebuildRenderData()`
**Change:** Group batches by (texture, height) instead of just texture

### 3. Collision Generation
**File:** `Plugins/Paper2D/Source/Paper2D/Private/PaperTileLayer.cpp`
**Function:** `AugmentBodySetup()`
**Change:** Add height offset to collision geometry

### 4. Editor Tools
**File:** `Plugins/Paper2D/Source/Paper2DEditor/Private/TileMapEditing/EdModeTileMap.cpp`
**Change:** Add height manipulation tools, visualization

## Performance Benchmarks (Estimated)

### Scenario: 100×100 tile map, 5 height levels, 3 textures

| Approach | Batches | Draw Calls | Performance |
|----------|---------|------------|-------------|
| **Current (No Height)** | 3-5 | 3-5 | Baseline (100%) |
| **Approach 1 (Per-Tile Z)** | 15-25 | 15-25 | Good (80-90%) |
| **Approach 2 (Individual)** | 100-500 | 100-500 | Poor (20-30%) |
| **Approach 3 (Layers)** | 15-25 | 15-25 | Excellent (95-100%) |
| **Approach 4 (Visual)** | 3-5 | 3-5 | Excellent (100%) |

## Conclusion

**Yes, height can be implemented in Paper2D**, but with trade-offs:

1. **Best Performance**: Visual-only height (Approach 4)
2. **Best Balance**: Height-based layers (Approach 3)
3. **True 3D**: Per-tile Z-offset (Approach 1) - acceptable performance
4. **Not Recommended**: Individual tile rendering (Approach 2)

**Recommended Path:**
1. Start with **visual height** (metadata + sprites/materials)
2. Add **optional Z-offset** for true 3D (with performance trade-off)
3. Use **layer-based approach** if height levels are discrete

The system is **technically feasible** and can work well for **small to medium maps** with **reasonable height variation** (<10 levels).

