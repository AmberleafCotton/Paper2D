# Tile Metadata System - Research & Implementation Plan

## Overview
Research document for adding per-tile custom properties/metadata to the Paper2D tile map system. This will allow designers to store custom data per tile (e.g., Type: grass/dirt, walkable/not walkable) and edit it through the editor.

## Current Architecture

### Tile Storage System

#### 1. **FPaperTileInfo** (`Plugins/Paper2D/Source/Paper2D/Classes/PaperTileLayer.h`)
- **Current Structure:**
  ```cpp
  struct FPaperTileInfo
  {
      TObjectPtr<UPaperTileSet> TileSet;  // Which tile set this tile comes from
      int32 PackedTileIndex;              // Tile index + flags (flip/rotate)
  };
  ```
- **Storage:** Tiles are stored in `UPaperTileLayer::AllocatedCells` as `TArray<FPaperTileInfo>`
- **Access:** Via `GetCell(X, Y)` and `SetCell(X, Y, FPaperTileInfo)`
- **Limitation:** Only stores visual tile reference, no custom properties

#### 2. **UPaperTileLayer** (`Plugins/Paper2D/Source/Paper2D/Classes/PaperTileLayer.h`)
- **Storage:** `TArray<FPaperTileInfo> AllocatedCells` (line 175)
- **Dimensions:** `LayerWidth` x `LayerHeight` (stored separately)
- **Layout:** 1D array indexed as `AllocatedCells[Y * AllocatedWidth + X]`
- **Current API:**
  - `FPaperTileInfo GetCell(int32 X, int32 Y) const`
  - `void SetCell(int32 X, int32 Y, const FPaperTileInfo& NewValue)`

#### 3. **UPaperTileMap** (`Plugins/Paper2D/Source/Paper2D/Classes/PaperTileMap.h`)
- **Structure:** Contains `TArray<TObjectPtr<UPaperTileLayer>> TileLayers`
- **Dimensions:** `MapWidth` x `MapHeight` (shared across all layers)
- **No per-tile metadata storage currently**

### Selection System

#### Current Selection (EyeDropper Tool)
- **Location:** `EdModeTileMap.h` lines 170-171
- **Storage:**
  ```cpp
  FIntPoint EyeDropperStart;
  FIntRect LastEyeDropperBounds;
  ```
- **Purpose:** Used for copying tiles, not for editing properties
- **Visualization:** Selection is shown via preview cursor component, not highlighted tiles

#### Viewport Rendering
- **Render Function:** `FEdModeTileMap::Render()` (line 587 in `EdModeTileMap.cpp`)
- **HUD Drawing:** `FEdModeTileMap::DrawHUD()` (line 645)
- **Current Drawing:** Preview cursor, tile grid, but no selected tile highlighting

## Implementation Options

### Option 1: Extend FPaperTileInfo (Recommended)
**Approach:** Add optional metadata struct to `FPaperTileInfo`

**Pros:**
- Minimal changes to existing code
- Metadata travels with tile data
- Easy to serialize
- Backward compatible (can make optional)

**Cons:**
- Increases memory per tile (even if empty)
- Requires modifying core struct

**Implementation:**
```cpp
// In PaperTileLayer.h
USTRUCT(BlueprintType)
struct FPaperTileMetadata
{
    GENERATED_BODY()
    
    // Tile type (grass, dirt, stone, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile Properties")
    FName TileType;
    
    // Is this tile walkable?
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile Properties")
    bool bIsWalkable;
    
    // Custom properties map (for extensibility)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile Properties")
    TMap<FName, FString> CustomProperties;
    
    FPaperTileMetadata()
        : TileType(NAME_None)
        , bIsWalkable(true)
    {}
};

struct FPaperTileInfo
{
    // ... existing fields ...
    
    // Optional per-tile metadata
    UPROPERTY(EditAnywhere, Category = "Metadata")
    TOptional<FPaperTileMetadata> Metadata;
};
```

### Option 2: Separate Metadata Layer
**Approach:** Create parallel storage structure in `UPaperTileLayer`

**Pros:**
- Doesn't modify core `FPaperTileInfo`
- Can be enabled/disabled per layer
- More memory efficient (only store metadata where needed)

**Cons:**
- More complex synchronization
- Need to ensure metadata stays in sync with tiles
- More code changes

**Implementation:**
```cpp
// In PaperTileLayer.h
class UPaperTileLayer : public UObject
{
    // ... existing fields ...
    
    // Optional per-tile metadata (parallel to AllocatedCells)
    UPROPERTY()
    TMap<FIntPoint, FPaperTileMetadata> TileMetadata;
    
    // Get metadata for tile at X, Y
    FPaperTileMetadata* GetTileMetadata(int32 X, int32 Y);
    const FPaperTileMetadata* GetTileMetadata(int32 X, int32 Y) const;
    
    // Set metadata for tile at X, Y
    void SetTileMetadata(int32 X, int32 Y, const FPaperTileMetadata& Metadata);
};
```

### Option 3: Per-TileMap Metadata Storage
**Approach:** Store metadata at tile map level, keyed by (LayerIndex, X, Y)

**Pros:**
- Centralized storage
- Easy to query across layers
- Can add layer-specific metadata too

**Cons:**
- More indirection
- Need to handle layer deletion/resizing
- Less intuitive API

## Recommended Approach: Option 1 (Extended FPaperTileInfo)

### Rationale
1. **Simplicity:** Metadata travels with tile, no sync issues
2. **Performance:** Direct access, no map lookups
3. **Serialization:** Automatic with tile data
4. **Backward Compatible:** Using `TOptional` means empty tiles don't store metadata

### Implementation Plan

#### Phase 1: Core Data Structure
1. **Create `FPaperTileMetadata` struct**
   - Location: `Plugins/Paper2D/Source/Paper2D/Classes/PaperTileLayer.h`
   - Add common properties (TileType, bIsWalkable, CustomProperties map)
   - Make it `USTRUCT` with `BlueprintType` for Blueprint access

2. **Extend `FPaperTileInfo`**
   - Add `TOptional<FPaperTileMetadata> Metadata` field
   - Keep backward compatible (defaults to empty)

3. **Update Serialization**
   - Ensure `FPaperTileMetadata` serializes correctly
   - Test loading old tile maps (should work fine with `TOptional`)

#### Phase 2: Editor Integration

1. **Selection System**
   - **Location:** `EdModeTileMap.h` / `EdModeTileMap.cpp`
   - **Add:** Single tile selection (click to select)
   - **Storage:**
     ```cpp
     FIntPoint SelectedTilePosition;  // Currently selected tile (X, Y)
     int32 SelectedTileLayerIndex;    // Which layer the selected tile is on
     bool bHasSelectedTile;           // Is a tile currently selected?
     ```

2. **Visual Selection Display**
   - **Location:** `FEdModeTileMap::Render()` (line 587)
   - **Add:** Draw highlight box around selected tile
   - **Implementation:**
     ```cpp
     if (bHasSelectedTile)
     {
         // Get tile position in world space
         UPaperTileMap* TileMap = FindSelectedComponent()->TileMap;
         FVector TilePos = TileMap->GetTilePositionInLocalSpace(
             SelectedTilePosition.X, 
             SelectedTilePosition.Y, 
             SelectedTileLayerIndex
         );
         
         // Draw selection box using PDI (PrimitiveDrawInterface)
         DrawWireBox(PDI, FBox(...), FColor::Yellow, ...);
     }
     ```

3. **Properties Panel**
   - **Location:** Create new file `TileMetadataDetailsCustomization.h/cpp`
   - **Approach:** Use `IDetailCustomization` to create custom details panel
   - **Integration:** Register in `Paper2DEditorModule.cpp` startup
   - **UI:** Show selected tile's metadata properties when tile is selected

4. **Tile Selection Tool**
   - **Location:** `EdModeTileMap.cpp`
   - **Add:** New tool mode or extend existing tools
   - **Behavior:** Click on tile to select it, show in properties panel
   - **Implementation:**
     ```cpp
     // In InputKey() or new SelectTile() function
     if (InKey == EKeys::LeftMouseButton && InEvent == IE_Pressed)
     {
         FViewportCursorLocation Ray = CalculateViewRay(...);
         int32 TileX, TileY;
         if (UPaperTileLayer* Layer = GetSelectedLayerUnderCursor(Ray, TileX, TileY))
         {
             SelectedTilePosition = FIntPoint(TileX, TileY);
             SelectedTileLayerIndex = Layer->GetLayerIndex();
             bHasSelectedTile = true;
             
             // Refresh properties panel
             // ...
         }
     }
     ```

#### Phase 3: API & Blueprint Access

1. **C++ API**
   - **Location:** `PaperTileLayer.h` / `PaperTileLayer.cpp`
   - **Add:**
     ```cpp
     // Get metadata for tile at X, Y
     FPaperTileMetadata* GetTileMetadata(int32 X, int32 Y);
     const FPaperTileMetadata* GetTileMetadata(int32 X, int32 Y) const;
     
     // Set metadata for tile at X, Y
     void SetTileMetadata(int32 X, int32 Y, const FPaperTileMetadata& Metadata);
     
     // Check if tile has metadata
     bool HasTileMetadata(int32 X, int32 Y) const;
     ```

2. **Blueprint Library**
   - **Location:** Create `PaperTileMapBlueprintLibrary.h/cpp` (or extend existing)
   - **Functions:**
     ```cpp
     UFUNCTION(BlueprintCallable, Category = "Paper2D|Tile Map")
     static FPaperTileMetadata GetTileMetadata(UPaperTileLayer* Layer, int32 X, int32 Y);
     
     UFUNCTION(BlueprintCallable, Category = "Paper2D|Tile Map")
     static void SetTileMetadata(UPaperTileLayer* Layer, int32 X, int32 Y, const FPaperTileMetadata& Metadata);
     
     UFUNCTION(BlueprintCallable, Category = "Paper2D|Tile Map")
     static bool HasTileMetadata(UPaperTileLayer* Layer, int32 X, int32 Y);
     ```

## File Locations & Changes

### Core Files to Modify

1. **`Plugins/Paper2D/Source/Paper2D/Classes/PaperTileLayer.h`**
   - Add `FPaperTileMetadata` struct
   - Extend `FPaperTileInfo` with `TOptional<FPaperTileMetadata> Metadata`
   - Add helper methods to `UPaperTileLayer` for metadata access

2. **`Plugins/Paper2D/Source/Paper2D/Private/PaperTileLayer.cpp`**
   - Implement metadata access methods
   - Ensure serialization works correctly

### Editor Files to Modify/Create

3. **`Plugins/Paper2D/Source/Paper2DEditor/Private/TileMapEditing/EdModeTileMap.h`**
   - Add selection state variables:
     ```cpp
     FIntPoint SelectedTilePosition;
     int32 SelectedTileLayerIndex;
     bool bHasSelectedTile;
     ```

4. **`Plugins/Paper2D/Source/Paper2DEditor/Private/TileMapEditing/EdModeTileMap.cpp`**
   - Implement tile selection in `InputKey()` or new `SelectTile()` method
   - Add selection visualization in `Render()` method
   - Handle selection clearing

5. **`Plugins/Paper2D/Source/Paper2DEditor/Private/TileMapEditing/TileMetadataDetailsCustomization.h`** (NEW)
   - Custom details panel for selected tile metadata

6. **`Plugins/Paper2D/Source/Paper2DEditor/Private/TileMapEditing/TileMetadataDetailsCustomization.cpp`** (NEW)
   - Implementation of details customization

7. **`Plugins/Paper2D/Source/Paper2DEditor/Private/Paper2DEditorModule.cpp`**
   - Register details customization in `StartupModule()`

### Blueprint Access Files

8. **`Plugins/Paper2D/Source/Paper2D/Public/PaperTileMapBlueprintLibrary.h`** (NEW or extend existing)
   - Blueprint-accessible functions for tile metadata

9. **`Plugins/Paper2D/Source/Paper2D/Private/PaperTileMapBlueprintLibrary.cpp`** (NEW or extend existing)
   - Implementation of Blueprint functions

## UI/UX Design

### Properties Panel
- **Location:** Details panel (right side of editor)
- **Trigger:** When tile is selected in viewport
- **Content:**
  - Tile Position: (X, Y, Layer)
  - Tile Info: TileSet, TileIndex
  - **Metadata Section:**
    - Tile Type (dropdown or text field)
    - Is Walkable (checkbox)
    - Custom Properties (key-value pairs, expandable)

### Selection Visualization
- **Visual:** Yellow outline box around selected tile
- **Location:** Drawn in `Render()` method using `PrimitiveDrawInterface`
- **Style:** Similar to preview cursor but more prominent

### Selection Tool
- **Option A:** Add new tool button (e.g., "Select" tool)
- **Option B:** Extend EyeDropper tool to also select for editing
- **Option C:** Click on tile while holding modifier key (e.g., Ctrl+Click)

## Testing Considerations

1. **Backward Compatibility:**
   - Old tile maps should load without errors
   - Tiles without metadata should work normally
   - Metadata should be optional

2. **Performance:**
   - Memory overhead of `TOptional` (should be minimal)
   - Selection rendering performance
   - Properties panel refresh performance

3. **Edge Cases:**
   - Selecting tile on different layer
   - Resizing tile map (metadata should be preserved)
   - Copying/pasting tiles (should metadata copy too?)
   - Undo/Redo with metadata changes

## Future Enhancements

1. **Bulk Operations:**
   - Select multiple tiles
   - Batch edit metadata
   - Copy metadata from one tile to another

2. **Metadata Templates:**
   - Predefined metadata sets
   - Apply template to selected tiles

3. **Metadata Validation:**
   - Rules for valid metadata
   - Warnings for invalid combinations

4. **Metadata Search/Filter:**
   - Find all tiles with specific metadata
   - Filter viewport by metadata

5. **Runtime Access:**
   - Query tile metadata at runtime
   - Use for gameplay logic (pathfinding, AI, etc.)

## Questions to Resolve

1. **Selection Behavior:**
   - Should selection persist when switching tools?
   - Should selection clear when clicking empty space?
   - Multi-tile selection or single only?

2. **Metadata Inheritance:**
   - Should tiles inherit metadata from tile set?
   - Should metadata copy when copying tiles?

3. **Default Values:**
   - What are default values for new metadata?
   - Should there be project-wide defaults?

4. **Performance:**
   - How many tiles typically have metadata?
   - Is `TOptional` overhead acceptable?

## Next Steps

1. **Review & Approval:** Get user feedback on approach
2. **Prototype:** Implement `FPaperTileMetadata` and extend `FPaperTileInfo`
3. **Selection System:** Add basic tile selection
4. **Visualization:** Draw selection in viewport
5. **Properties Panel:** Create details customization
6. **Testing:** Test with various tile maps
7. **Documentation:** Update user-facing documentation

