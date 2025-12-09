# Actor-on-Grid Approach - Analysis & Implementation Plan

## Concept

Instead of implementing height-based terrain, use **actors placed on grid positions**:
- Each tile can reference an actor class/instance
- Actors are placed at exact grid coordinates
- Actors visible in outliner, fully editable
- Use actor properties/components for customization
- Focus on improving tile editor for actor placement

## Advantages

✅ **Much Simpler** - No complex height rendering
✅ **More Flexible** - Actors can have any components/properties
✅ **Better Editor Integration** - Actors show in outliner
✅ **Reuses Existing Systems** - Paper2D + Unreal actor system
✅ **No Performance Issues** - No batching problems
✅ **Easy to Extend** - Add actor properties as needed

## Current Paper2D Capabilities

### ✅ What We Already Have

1. **Tile Position Calculation**
   ```cpp
   // PaperTileMapComponent.h
   FVector GetTileCenterPosition(int32 TileX, int32 TileY, int32 LayerIndex, bool bWorldSpace) const;
   FVector GetTileCornerPosition(int32 TileX, int32 TileY, int32 LayerIndex, bool bWorldSpace) const;
   ```
   - Can get exact world position for any tile ✅
   - Works with isometric diamond projection ✅

2. **Tile Metadata System** (Just Implemented!)
   ```cpp
   struct FPaperTileLayerMetadata
   {
       FName TileType;
       bool bIsWalkable;
       // Can add: TSubclassOf<AActor> ActorClass;
       // Can add: TWeakObjectPtr<AActor> ActorInstance;
   };
   ```
   - Already stores custom data per tile ✅
   - Can extend with actor references ✅

3. **Isometric Diamond Projection**
   - Already supported in Paper2D ✅
   - `ETileMapProjectionMode::IsometricDiamond` ✅

## Implementation Approach

### Option 1: Actor Class Reference (Recommended)

**Store actor class in tile metadata, spawn on demand**

```cpp
// Extend FPaperTileLayerMetadata
struct FPaperTileLayerMetadata
{
    // ... existing fields (TileType, bIsWalkable) ...
    
    // Actor class to spawn at this tile
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
    TSubclassOf<AActor> ActorClass;
    
    // Instance reference (if already spawned)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
    TWeakObjectPtr<AActor> ActorInstance;
    
    // Should actor be visible in editor but hidden at runtime?
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor")
    bool bHideActorAtRuntime = false;
};
```

**Workflow:**
1. Designer selects tile
2. Chooses actor class from dropdown
3. Actor spawns at tile position
4. Actor visible in outliner, editable
5. Tile stores reference to actor

### Option 2: Actor Instance Reference

**Store direct reference to spawned actor**

```cpp
struct FPaperTileLayerMetadata
{
    // ... existing fields ...
    
    // Direct reference to actor instance
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TWeakObjectPtr<AActor> ActorInstance;
    
    // Actor class (for spawning new instances)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> ActorClass;
};
```

**Workflow:**
1. Designer places actor in level
2. Selects tile, assigns actor to tile
3. Actor position synced to tile position
4. Tile stores reference

### Option 3: Hybrid - Component-Based

**Create component that manages actor placement**

```cpp
// TerrainActorComponent.h
UCLASS(BlueprintType)
class UTerrainActorComponent : public UActorComponent
{
    GENERATED_BODY()
    
    // Tile map component reference
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UPaperTileMapComponent> TileMapComponent;
    
    // Spawn actor at tile position
    UFUNCTION(BlueprintCallable)
    AActor* SpawnActorAtTile(int32 X, int32 Y, TSubclassOf<AActor> ActorClass);
    
    // Get actor at tile position
    UFUNCTION(BlueprintPure)
    AActor* GetActorAtTile(int32 X, int32 Y) const;
    
    // Remove actor from tile
    UFUNCTION(BlueprintCallable)
    void RemoveActorAtTile(int32 X, int32 Y);
};
```

## Recommended Implementation

### Phase 1: Extend Metadata

```cpp
// PaperTileLayer.h - Extend FPaperTileLayerMetadata
struct FPaperTileLayerMetadata
{
    // ... existing fields (TileType, bIsWalkable) ...
    
    // Actor class to place at this tile
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Placement")
    TSubclassOf<AActor> ActorClass;
    
    // Reference to spawned actor instance
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Placement")
    TWeakObjectPtr<AActor> ActorInstance;
    
    // Auto-spawn actor when tile is placed?
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Placement")
    bool bAutoSpawnActor = true;
    
    // Hide actor at runtime (editor-only visualization)?
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Placement")
    bool bHideAtRuntime = false;
};
```

### Phase 2: Actor Placement System

```cpp
// TerrainActorManager.h (NEW)
UCLASS(BlueprintType)
class UTerrainActorManager : public UObject
{
    GENERATED_BODY()
    
public:
    // Spawn actor at tile position
    UFUNCTION(BlueprintCallable, Category="Terrain")
    AActor* SpawnActorAtTile(
        UPaperTileMapComponent* TileMapComponent,
        int32 X, int32 Y,
        TSubclassOf<AActor> ActorClass);
    
    // Get actor at tile position
    UFUNCTION(BlueprintPure, Category="Terrain")
    AActor* GetActorAtTile(
        UPaperTileMapComponent* TileMapComponent,
        int32 X, int32 Y) const;
    
    // Remove actor from tile
    UFUNCTION(BlueprintCallable, Category="Terrain")
    void RemoveActorAtTile(
        UPaperTileMapComponent* TileMapComponent,
        int32 X, int32 Y);
    
    // Sync all actors to tile positions (after tile map changes)
    UFUNCTION(BlueprintCallable, Category="Terrain")
    void SyncActorsToTiles(UPaperTileMapComponent* TileMapComponent);
};
```

### Phase 3: Editor Integration

**Extend Tile Details Panel:**
```cpp
// In PaperTileMapDetailsCustomization.cpp
// Add to AddTileDetailsSection():

// Actor Placement Section
TileDetailsCategory.AddCustomRow(LOCTEXT("ActorClass", "Actor Class"))
.NameContent()
[
    SNew(STextBlock)
    .Text(LOCTEXT("ActorClassLabel", "Actor Class"))
    .Font(DetailLayout.GetDetailFont())
]
.ValueContent()
[
    SNew(SClassPropertyEntryBox)
    .MetaClass(AActor::StaticClass())
    .SelectedClass(Metadata->ActorClass)
    .OnSetClass_Lambda([SelectedLayer, SelectedPos, Metadata, &DetailLayout](const UClass* NewClass)
    {
        FScopedTransaction Transaction(LOCTEXT("SetTileActorClass", "Set Tile Actor Class"));
        SelectedLayer->Modify();
        Metadata->ActorClass = NewClass;
        SelectedLayer->SetTileMetadata(SelectedPos.X, SelectedPos.Y, *Metadata);
        
        // Auto-spawn actor if enabled
        if (Metadata->bAutoSpawnActor && NewClass)
        {
            // Spawn actor at tile position
            // ...
        }
        
        DetailLayout.ForceRefreshDetails();
    })
];

// Actor Instance Display
if (Metadata->ActorInstance.IsValid())
{
    TileDetailsCategory.AddCustomRow(LOCTEXT("ActorInstance", "Actor Instance"))
    .NameContent()
    [
        SNew(STextBlock)
        .Text(LOCTEXT("ActorInstanceLabel", "Actor Instance"))
        .Font(DetailLayout.GetDetailFont())
    ]
    .ValueContent()
    [
        SNew(SObjectPropertyEntryBox)
        .ObjectPath(Metadata->ActorInstance->GetPathName())
        .OnObjectChanged_Lambda([SelectedLayer, SelectedPos, Metadata, &DetailLayout](const FAssetData& AssetData)
        {
            // Update actor reference
        })
    ];
}
```

### Phase 4: Editor Tools

**Add "Place Actor" Tool:**
```cpp
// In EdModeTileMap.h - Add to ETileMapEditorTool enum
enum Type
{
    // ... existing tools ...
    PlaceActor  // New tool
};

// In EdModeTileMap.cpp
bool FEdModeTileMap::UseActiveToolAtLocation(const FViewportCursorLocation& Ray)
{
    switch (GetActiveTool())
    {
    // ... existing cases ...
    case ETileMapEditorTool::PlaceActor:
        return PlaceActorAtLocation(Ray);
    }
}

bool FEdModeTileMap::PlaceActorAtLocation(const FViewportCursorLocation& Ray)
{
    int32 TileX, TileY;
    if (UPaperTileLayer* Layer = GetSelectedLayerUnderCursor(Ray, TileX, TileY))
    {
        // Get selected actor class from editor settings
        TSubclassOf<AActor> SelectedActorClass = GetSelectedActorClass();
        
        if (SelectedActorClass)
        {
            // Spawn actor at tile position
            UPaperTileMapComponent* Component = FindSelectedComponent();
            if (Component)
            {
                FVector TileWorldPos = Component->GetTileCenterPosition(
                    TileX, TileY, Layer->GetLayerIndex(), true);
                
                AActor* SpawnedActor = GetWorld()->SpawnActor(
                    SelectedActorClass,
                    &TileWorldPos);
                
                // Store reference in metadata
                FPaperTileInfo TileInfo = Layer->GetCell(TileX, TileY);
                if (!TileInfo.Metadata.IsSet())
                {
                    FPaperTileLayerMetadata NewMetadata;
                    TileInfo.Metadata = NewMetadata;
                }
                
                FPaperTileLayerMetadata* Metadata = Layer->GetTileMetadata(TileX, TileY);
                Metadata->ActorInstance = SpawnedActor;
                Metadata->ActorClass = SelectedActorClass;
                
                Layer->SetTileMetadata(TileX, TileY, *Metadata);
                
                return true;
            }
        }
    }
    return false;
}
```

## Architecture Comparison

### Height-Based Terrain (Complex)
- ❌ Complex rendering modifications
- ❌ Batching performance issues
- ❌ Limited to height values
- ❌ Hard to extend

### Actor-on-Grid (Simple)
- ✅ Simple metadata extension
- ✅ No rendering changes needed
- ✅ Unlimited flexibility (any actor properties)
- ✅ Easy to extend
- ✅ Better editor integration
- ✅ Uses existing Unreal systems

## Implementation Complexity

### Actor-on-Grid Approach

**Low Complexity:**
1. Extend `FPaperTileMetadata` with actor fields (5 minutes)
2. Add actor placement helper functions (30 minutes)
3. Extend Tile Details panel (1 hour)
4. Add "Place Actor" tool to editor (2 hours)
5. Sync actors to tile positions (1 hour)

**Total:** ~5 hours vs. ~20+ hours for height terrain

## Recommended Workflow

### For Designers

1. **Select Tile** (using Select tool - already implemented)
2. **Choose Actor Class** (dropdown in Tile Details panel)
3. **Actor Auto-Spawns** at tile position
4. **Edit Actor** (normal actor editing in outliner/details)
5. **Actor Position Synced** to tile (if tile moves, actor moves)

### Editor Improvements Needed

1. **Actor Class Selector** in Tile Details panel
2. **Place Actor Tool** in toolbar
3. **Actor Instance Display** in Tile Details
4. **Sync Button** (sync all actors to tile positions)
5. **Visual Indicator** (show which tiles have actors)

## Code Structure

### Minimal Changes Required

1. **Extend Metadata** (1 file)
   - `PaperTileLayer.h` - Add actor fields to `FPaperTileLayerMetadata`

2. **Helper Functions** (1 new file)
   - `TerrainActorManager.h/cpp` - Actor placement utilities

3. **Editor Integration** (2 files)
   - `PaperTileMapDetailsCustomization.cpp` - Add actor UI
   - `EdModeTileMap.cpp` - Add Place Actor tool

4. **Blueprint Library** (extend existing)
   - `TileMapBlueprintLibrary.h/cpp` - Add actor functions

## Benefits Over Height Terrain

1. **No Rendering Changes** - Uses existing Paper2D rendering
2. **No Performance Issues** - Actors are separate from tile rendering
3. **More Flexible** - Actors can have any components
4. **Better Editor UX** - Actors visible in outliner
5. **Easier to Debug** - Can select actors directly
6. **Reuses Systems** - Standard Unreal actor system
7. **Easier to Extend** - Add actor properties as needed

## Potential Issues & Solutions

### Issue 1: Actor Position Sync

**Problem:** If tile map moves/transforms, actors need to update positions.

**Solution:**
- Store relative position in metadata
- Sync on tile map transform changes
- Or use component attachment

### Issue 2: Actor Lifecycle

**Problem:** When to spawn/destroy actors?

**Solution:**
- Spawn on tile placement (if `bAutoSpawnActor = true`)
- Destroy on tile removal
- Or manual spawn/despawn

### Issue 3: Editor vs Runtime

**Problem:** Should actors be visible at runtime?

**Solution:**
- Use `bHideAtRuntime` flag
- Or use `WITH_EDITOR` conditional compilation
- Or use actor visibility settings

## Recommended Implementation Plan

### Phase 1: Metadata Extension (Quick Win)

1. Add actor fields to `FPaperTileLayerMetadata`
2. Add helper methods to get/set actor at tile
3. Test with existing tile selection system

### Phase 2: Basic Placement (Core Functionality)

1. Add actor placement helper functions
2. Extend Tile Details panel with actor class selector
3. Auto-spawn actor when class is selected

### Phase 3: Editor Tools (UX Improvements)

1. Add "Place Actor" tool to toolbar
2. Add actor instance display in details
3. Add visual indicators for tiles with actors

### Phase 4: Advanced Features (Polish)

1. Actor position sync system
2. Batch operations (place actor on multiple tiles)
3. Actor templates/presets

## Conclusion

**This approach is:**
- ✅ **Much Simpler** than height terrain
- ✅ **More Flexible** (any actor properties)
- ✅ **Better Editor Integration** (actors in outliner)
- ✅ **No Performance Issues** (no rendering changes)
- ✅ **Easier to Implement** (~5 hours vs 20+ hours)
- ✅ **Easier to Maintain** (uses standard Unreal systems)

**Recommendation:** ✅ **Use Actor-on-Grid approach instead of height terrain**

This solves the "terrain with objects" problem in a much cleaner way, and you can always add height later if needed (actors can have Z-offset components).

