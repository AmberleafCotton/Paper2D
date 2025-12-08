# Paper2DEditor Module Documentation

## Overview

The Paper2DEditor module provides the editor functionality for the Paper2D plugin in Unreal Engine 5. It handles asset creation, editing, visualization, and integration with the Unreal Editor. This document provides a comprehensive breakdown of all files in the module, their purpose, and core functionality.

---

## Module Structure

### Core Module Files

#### `Paper2DEditor.Build.cs`
**Purpose:** Build configuration file that defines module dependencies and build settings.

**Key Dependencies:**
- Core modules: Core, CoreUObject, Engine, Slate, SlateCore
- Editor modules: UnrealEd, PropertyEditor, AssetTools, ContentBrowser
- Paper2D runtime module
- Specialized: MeshPaint, ToolMenus, ToolWidgets, NavigationSystem
- Public: Json (for JSON import/export functionality)

**Core Functions:**
- Defines private and public dependency modules
- Configures include paths for Settings and LevelEditor modules

---

#### `Public/Paper2DEditorModule.h`
**Purpose:** Public interface for the Paper2DEditor module, providing extensibility managers for sprite and flipbook editors.

**Core Functions:**
- `GetSpriteEditorMenuExtensibilityManager()` - Returns extensibility manager for sprite editor menus
- `GetSpriteEditorToolBarExtensibilityManager()` - Returns extensibility manager for sprite editor toolbars
- `GetFlipbookEditorMenuExtensibilityManager()` - Returns extensibility manager for flipbook editor menus
- `GetFlipbookEditorToolBarExtensibilityManager()` - Returns extensibility manager for flipbook editor toolbars
- `GetPaper2DAssetCategory()` - Returns the asset category bit for Paper2D assets

---

#### `Private/Paper2DEditorModule.cpp`
**Purpose:** Main module implementation that initializes and registers all Paper2D editor functionality.

**Core Functions:**
- `StartupModule()` - Initializes the module, sets up extensibility managers, registers asset types, commands, and settings
- `ShutdownModule()` - Cleans up all registered components, unregisters asset types, commands, and settings
- `OnPostEngineInit()` - Called after engine initialization to set up:
  - Extensibility managers for sprite and flipbook editors
  - Slate style overrides (FPaperStyle)
  - Editor commands (FPaperEditorCommands)
  - Asset type actions (Sprite, Flipbook, TileSet, TileMap, Atlas)
  - Component asset brokers (Sprite, Flipbook, TileMap)
  - Property editor customizations
  - Thumbnail renderers
  - Editor modes (TileMap, SpriteGeometry)
  - Content browser and level editor menu extensions
  - Mesh paint adapter factory
  - Settings registration
- `RegisterAssetTypeAction()` - Helper to register and cache asset type actions
- `OnPropertyChanged()` - Handles property change events (e.g., atlas changes)
- `OnObjectReimported()` - Handles asset reimport events, updates sprites when textures are reimported
- `RegisterSettings()` - Registers all Paper2D-related settings with the settings module
- `UnregisterSettings()` - Unregisters all settings during shutdown

**Key Responsibilities:**
- Asset type registration and management
- Component broker registration
- Editor mode registration
- Thumbnail renderer registration
- Settings management
- Event handling for property changes and reimports

---

## Factory Classes

### Asset Factories

#### `Classes/PaperSpriteFactory.h` & `Private/PaperSpriteFactory.cpp`
**Purpose:** Factory for creating PaperSprite assets from textures.

**Core Functions:**
- `ConfigureProperties()` - Configures factory properties (currently placeholder)
- `FactoryCreateNew()` - Creates a new PaperSprite asset with:
  - Optional initial texture
  - Source region support (UV offset and dimensions)
  - Automatic normal map detection (searches for associated normal maps)
  - Material selection based on importer settings
  - Sprite initialization via `InitializeSprite()`

**Key Features:**
- Supports creating sprites from entire textures or specific regions
- Automatically finds and associates normal maps based on naming conventions
- Applies importer settings for material selection and texture compression

---

#### `Classes/PaperFlipbookFactory.h` & `Private/PaperFlipbookFactory.cpp`
**Purpose:** Factory for creating PaperFlipbook assets.

**Core Functions:**
- `FactoryCreateNew()` - Creates a new PaperFlipbook asset with:
  - Pre-configured keyframes (from `KeyFrames` array)
  - Transactional creation for undo/redo support

**Key Features:**
- Simple factory that creates flipbooks from a list of keyframes
- Used when creating flipbooks from sprite selections

---

#### `Classes/PaperTileSetFactory.h` & `Private/PaperTileSetFactory.cpp`
**Purpose:** Factory for creating PaperTileSet assets.

**Core Functions:**
- `FactoryCreateNew()` - Creates a new PaperTileSet asset with:
  - Optional initial texture (tile sheet)
  - Default background color from editor settings
  - Calls `PostEditChange()` to update the asset

**Key Features:**
- Sets up tile sets with default editor settings
- Configures background color from TileSetEditorSettings

---

#### `Classes/PaperTileMapFactory.h` & `Private/PaperTileMapFactory.cpp`
**Purpose:** Factory for creating PaperTileMap assets.

**Core Functions:**
- `FactoryCreateNew()` - Creates a new PaperTileMap asset with:
  - Optional initial tile set
  - Applies importer settings via `ApplySettingsForTileMapInit()`
  - Configures tile dimensions, materials, and default colors

**Key Features:**
- Integrates with PaperImporterSettings for material selection
- Sets up default tile map properties from editor settings

---

#### `Classes/PaperTileMapPromotionFactory.h` & `Private/PaperTileMapPromotionFactory.cpp`
**Purpose:** Factory for promoting legacy tile map assets to the new format.

**Core Functions:**
- Handles conversion of old tile map formats to the current format
- Migration logic for backward compatibility

---

### Actor Factories

#### `Classes/PaperSpriteActorFactory.h` & `Private/PaperSpriteActorFactory.cpp`
**Purpose:** Factory for creating PaperSpriteActor instances in the level.

**Core Functions:**
- `PostSpawnActor()` - Configures the spawned actor:
  - Sets the sprite on the render component
  - Copies body instance properties from sprite's BodySetup
  - Registers the component
- `CanCreateActorFrom()` - Validates that the asset is a PaperSprite

**Key Features:**
- Enables drag-and-drop sprite creation in the level
- Properly configures physics properties from sprite data

---

#### `Classes/PaperFlipbookActorFactory.h` & `Private/PaperFlipbookActorFactory.cpp`
**Purpose:** Factory for creating PaperFlipbookActor instances in the level.

**Core Functions:**
- `PostSpawnActor()` - Configures the spawned actor:
  - Sets the flipbook on the render component
  - Registers the component
- `CanCreateActorFrom()` - Validates that the asset is a PaperFlipbook

**Key Features:**
- Enables drag-and-drop flipbook creation in the level
- Sets up animated sprite actors

---

#### `Classes/TileMapActorFactory.h` & `Private/TileMapActorFactory.cpp`
**Purpose:** Factory for creating TileMapActor instances in the level.

**Core Functions:**
- Similar to other actor factories, configures tile map actors when dragged into the level

---

#### `Classes/TerrainSplineActorFactory.h` & `Private/TerrainSplineEditing/TerrainSplineActorFactory.cpp`
**Purpose:** Factory for creating terrain spline actors (legacy/experimental feature).

---

## Thumbnail Renderers

### `Classes/PaperSpriteThumbnailRenderer.h` & `Private/PaperSpriteThumbnailRenderer.cpp`
**Purpose:** Renders thumbnails for PaperSprite assets in the content browser.

**Core Functions:**
- `Draw()` - Main rendering function that draws the sprite thumbnail
- `DrawFrame()` - Renders a sprite frame with:
  - Baked render data support (handles rotations, overlapping sprites)
  - Proper scaling and centering
  - Alpha channel detection for grid background
  - Triangle-based rendering using canvas UV triangles
- `DrawGrid()` - Draws checkerboard background for transparent sprites

**Key Features:**
- Uses baked render data for accurate representation
- Handles sprite transformations and rotations
- Shows grid background for transparency visualization
- Supports override render bounds for custom display

---

### `Classes/PaperFlipbookThumbnailRenderer.h` & `Private/PaperFlipbookThumbnailRenderer.cpp`
**Purpose:** Renders animated thumbnails for PaperFlipbook assets.

**Core Functions:**
- `Draw()` - Renders the current frame of the flipbook animation:
  - Calculates playback time based on elapsed time
  - Gets sprite at current time using `GetSpriteAtTime()`
  - Uses flipbook bounds for proper scaling
  - Shows warning text if flipbook has no frames

**Key Features:**
- Animated thumbnails that play the flipbook animation
- Time-based frame selection
- Fallback to grid if no frames available

---

### `Classes/PaperTileSetThumbnailRenderer.h` & `Private/PaperTileSetThumbnailRenderer.cpp`
**Purpose:** Renders thumbnails for PaperTileSet assets.

**Core Functions:**
- `Draw()` - Renders the tile set thumbnail:
  - Shows the tile sheet texture
  - Accounts for margins
  - Maintains aspect ratio with letterboxing (black bars)
  - Draws grid background for transparency

**Key Features:**
- Displays the full tile sheet texture
- Proper aspect ratio handling
- Margin-aware rendering

---

## Asset Type Actions

### `Private/SpriteAssetTypeActions.h` & `Private/SpriteAssetTypeActions.cpp`
**Purpose:** Defines asset browser actions for PaperSprite assets.

**Core Functions:**
- `GetName()` - Returns "Sprite" as the display name
- `GetTypeColor()` - Returns cyan color for sprite assets
- `GetSupportedClass()` - Returns UPaperSprite class
- `OpenAssetEditor()` - Opens the sprite editor for selected sprites
- `GetCategories()` - Returns Paper2D asset category
- `GetActions()` - Adds context menu actions:
  - "Create Flipbook" - Creates flipbooks from selected sprites
- `ExecuteCreateFlipbook()` - Implementation of flipbook creation:
  - Groups sprites by name patterns
  - Creates flipbook assets using PaperFlipbookFactory
  - Handles progress reporting for large selections

**Key Features:**
- Context menu integration
- Batch flipbook creation from sprite selection
- Automatic sprite grouping by naming patterns

---

### `Private/FlipbookAssetTypeActions.h` & `Private/FlipbookAssetTypeActions.cpp`
**Purpose:** Defines asset browser actions for PaperFlipbook assets.

**Core Functions:**
- `GetName()` - Returns "Paper Flipbook" as display name
- `GetTypeColor()` - Returns green color (129, 196, 115)
- `GetSupportedClass()` - Returns UPaperFlipbook class
- `OpenAssetEditor()` - Opens the flipbook editor for selected flipbooks
- `GetCategories()` - Returns Paper2D asset category

**Key Features:**
- Simple asset type action for flipbook editing

---

### `Private/TileSetAssetTypeActions.h` & `Private/TileSetAssetTypeActions.cpp`
**Purpose:** Defines asset browser actions for PaperTileSet assets.

**Core Functions:**
- Similar structure to other asset type actions
- Opens tile set editor when assets are double-clicked

---

### `Private/TileMapEditing/TileMapAssetTypeActions.h` & `Private/TileMapEditing/TileMapAssetTypeActions.cpp`
**Purpose:** Defines asset browser actions for PaperTileMap assets.

**Core Functions:**
- Opens tile map editor for tile map assets
- Integrates with tile map editing system

---

### `Private/Atlasing/AtlasAssetTypeActions.h` & `Private/Atlasing/AtlasAssetTypeActions.cpp`
**Purpose:** Defines asset browser actions for PaperSpriteAtlas assets.

**Core Functions:**
- Handles atlas asset operations
- Integrates with atlas generation system

---

## Editor Classes

### Sprite Editor

#### `Private/SpriteEditor/SpriteEditor.h` & `Private/SpriteEditor/SpriteEditor.cpp`
**Purpose:** Main sprite editor toolkit for editing PaperSprite assets.

**Core Functions:**
- `InitSpriteEditor()` - Initializes the editor with a sprite asset
- `GetSpriteBeingEdited()` - Returns the currently edited sprite
- `SetSpriteBeingEdited()` - Changes the sprite being edited
- `GetCurrentMode()` - Returns current editor mode (View, EditSourceRegion, EditCollision, EditRenderingGeom)
- `GetSourceTexture()` - Gets the source texture for the sprite
- `RegisterTabSpawners()` - Registers viewport, details, and sprite list tabs
- `BindCommands()` - Binds keyboard shortcuts
- `ExtendMenu()` - Extends the editor menu
- `ExtendToolbar()` - Extends the editor toolbar
- `CreateEditorModeManager()` - Creates the mode manager for geometry editing
- `SpawnTab_Viewport()` - Creates the viewport tab
- `SpawnTab_Details()` - Creates the details panel tab
- `SpawnTab_SpriteList()` - Creates the sprite list tab (for atlases)

**Editor Modes:**
- `ViewMode` - View-only mode
- `EditSourceRegionMode` - Edit the source region in the texture
- `EditCollisionMode` - Edit collision geometry
- `EditRenderingGeomMode` - Edit rendering geometry

**Key Features:**
- Multi-tab interface (viewport, details, sprite list)
- Multiple editing modes
- Geometry editing support
- Integration with sprite atlas editing

---

#### `Private/SpriteEditor/SpriteEditorViewportClient.h` & `Private/SpriteEditor/SpriteEditorViewportClient.cpp`
**Purpose:** Viewport client for the sprite editor viewport.

**Core Functions:**
- Handles viewport rendering
- Manages camera and view controls
- Renders sprite with grid background
- Handles selection visualization
- Supports zoom and pan operations

---

#### `Private/SpriteEditor/SpriteEditorCommands.h` & `Private/SpriteEditor/SpriteEditorCommands.cpp`
**Purpose:** Defines keyboard commands for the sprite editor.

**Core Functions:**
- Registers keyboard shortcuts for sprite editing operations
- Mode switching commands
- Geometry editing commands

---

#### `Private/SpriteEditor/SpriteDetailsCustomization.h` & `Private/SpriteEditor/SpriteDetailsCustomization.cpp`
**Purpose:** Customizes the details panel for PaperSprite assets.

**Core Functions:**
- Custom property layout for sprite properties
- Enhanced UI for sprite-specific settings
- Integration with sprite editing tools

---

#### `Private/SpriteEditor/SpriteComponentDetailsCustomization.h` & `Private/SpriteEditor/SpriteComponentDetailsCustomization.cpp`
**Purpose:** Customizes the details panel for PaperSpriteComponent.

**Core Functions:**
- Custom property layout for sprite component
- Enhanced UI for component-specific settings

---

#### `Private/SpriteEditor/SpriteEditorSettings.h` & `Private/SpriteEditor/SpriteEditorSettings.cpp`
**Purpose:** Settings class for sprite editor preferences.

**Core Functions:**
- Stores editor preferences (colors, grid settings, etc.)
- Configurable via settings menu

---

### Flipbook Editor

#### `Private/FlipbookEditor/FlipbookEditor.h` & `Private/FlipbookEditor/FlipbookEditor.cpp`
**Purpose:** Main flipbook editor toolkit for editing PaperFlipbook assets.

**Core Functions:**
- `InitFlipbookEditor()` - Initializes the editor with a flipbook asset
- `GetFlipbookBeingEdited()` - Returns the currently edited flipbook
- `GetPreviewComponent()` - Gets the preview component for animation playback
- `GetFramesPerSecond()` - Gets FPS from flipbook
- `GetCurrentFrame()` - Gets current frame index based on playback position
- `SetCurrentFrame()` - Sets playback position based on frame index
- `GetTotalFrameCount()` - Gets total number of frames
- `GetPlaybackPosition()` - Gets current playback time
- `SetPlaybackPosition()` - Sets playback time
- `RegisterTabSpawners()` - Registers viewport and timeline tabs
- `BindCommands()` - Binds keyboard shortcuts
- `ExtendMenu()` - Extends the editor menu
- `ExtendToolbar()` - Extends the editor toolbar

**Key Features:**
- Timeline-based animation editing
- Frame-by-frame navigation
- Playback controls
- Keyframe editing

---

#### `Private/FlipbookEditor/FlipbookEditorViewportClient.h` & `Private/FlipbookEditor/FlipbookEditorViewportClient.cpp`
**Purpose:** Viewport client for the flipbook editor.

**Core Functions:**
- Renders animated flipbook preview
- Handles playback visualization
- Manages camera and view controls

---

#### `Private/FlipbookEditor/FlipbookEditorCommands.h` & `Private/FlipbookEditor/FlipbookEditorCommands.cpp`
**Purpose:** Defines keyboard commands for the flipbook editor.

**Core Functions:**
- Playback control commands (play, pause, stop)
- Frame navigation commands (next frame, previous frame)
- Timeline manipulation commands

---

#### `Private/FlipbookEditor/SFlipbookTimeline.h` & `Private/FlipbookEditor/SFlipbookTimeline.cpp`
**Purpose:** Timeline widget for flipbook editing.

**Core Functions:**
- Displays keyframes on a timeline
- Handles frame selection
- Supports drag-and-drop frame reordering
- Visual representation of frame durations

---

#### `Private/FlipbookEditor/SFlipbookEditorViewportToolbar.h` & `Private/FlipbookEditor/SFlipbookEditorViewportToolbar.cpp`
**Purpose:** Toolbar widget for flipbook editor viewport.

**Core Functions:**
- Playback controls (play, pause, stop, loop)
- Frame navigation buttons
- Zoom controls
- Settings buttons

---

#### `Private/FlipbookEditor/FlipbookComponentDetailsCustomization.h` & `Private/FlipbookEditor/FlipbookComponentDetailsCustomization.cpp`
**Purpose:** Customizes the details panel for PaperFlipbookComponent.

**Core Functions:**
- Custom property layout for flipbook component
- Enhanced UI for component-specific settings

---

#### `Private/FlipbookEditor/FlipbookEditorSettings.h` & `Private/FlipbookEditor/FlipbookEditorSettings.cpp`
**Purpose:** Settings class for flipbook editor preferences.

**Core Functions:**
- Stores editor preferences
- Configurable via settings menu

---

### Tile Set Editor

#### `Private/TileSetEditor/TileSetEditor.h` & `Private/TileSetEditor/TileSetEditor.cpp`
**Purpose:** Main tile set editor toolkit.

**Core Functions:**
- Tile set editing interface
- Tile definition and collision editing
- Integration with tile map editor

---

#### `Private/TileSetEditor/TileSetDetailsCustomization.h` & `Private/TileSetEditor/TileSetDetailsCustomization.cpp`
**Purpose:** Customizes the details panel for PaperTileSet assets.

**Core Functions:**
- Custom property layout for tile set
- Enhanced UI for tile-specific settings

---

#### `Private/TileSetEditor/TileSetEditorSettings.h` & `Private/TileSetEditor/TileSetEditorSettings.cpp`
**Purpose:** Settings class for tile set editor preferences.

**Core Functions:**
- Default background color
- Grid settings
- Other editor preferences

---

### Tile Map Editor

#### `Private/TileMapEditing/EdModeTileMap.h` & `Private/TileMapEditing/EdModeTileMap.cpp`
**Purpose:** Editor mode for tile map editing in the level viewport.

**Core Functions:**
- Tile painting tools
- Layer management
- Tile selection and placement
- Integration with level editor

---

#### `Private/TileMapEditing/PaperTileMapDetailsCustomization.h` & `Private/TileMapEditing/PaperTileMapDetailsCustomization.cpp`
**Purpose:** Customizes the details panel for PaperTileMap assets and components.

**Core Functions:**
- Custom property layout for tile maps
- Layer management UI
- Tile set selection UI

---

#### `Private/TileMapEditing/TileMapEditorSettings.h` & `Private/TileMapEditing/TileMapEditorSettings.cpp`
**Purpose:** Settings class for tile map editor preferences.

**Core Functions:**
- Default colors (background, grid, layer grid)
- Multi-tile grid settings
- Other editor preferences

---

## Helper Classes

### `Public/PaperFlipbookHelpers.h` & `Private/PaperFlipbookHelpers.cpp`
**Purpose:** Utility functions for working with flipbooks and sprites.

**Core Functions:**
- `ExtractFlipbooksFromSprites()` - Groups sprites into flipbooks based on naming patterns:
  - Extracts numbers from sprite names (e.g., "Walk01", "Walk02" -> "Walk" flipbook)
  - Natural sorting of sprites
  - Handles ungrouped sprites
- `GetCleanerSpriteName()` - Removes suffixes like "_Sprite" and punctuation
- `ExtractSpriteNumber()` - Extracts numeric suffix from sprite name

**Key Features:**
- Intelligent sprite grouping for flipbook creation
- Pattern recognition for numbered sequences
- Natural sorting algorithm

---

### `Public/PaperJSONHelpers.h` & `Private/PaperJSONHelpers.cpp`
**Purpose:** Utility functions for reading JSON data (used for importing sprite data from external tools).

**Core Functions:**
- `ReadString()` - Reads string value with default fallback
- `ReadObject()` - Reads JSON object
- `ReadArray()` - Reads JSON array
- `ReadBoolean()` - Reads boolean value
- `ReadFloatNoDefault()` - Reads float/double value (returns success flag)
- `ReadIntegerNoDefault()` - Reads integer value (returns success flag)
- `ReadRectangle()` - Reads rectangle struct (x, y, w, h)
- `ReadSize()` - Reads size struct (w, h)
- `ReadXY()` - Reads XY coordinate struct (x, y)
- `ReadIntPoint()` - Reads integer point (x, y)

**Key Features:**
- Type-safe JSON reading
- Default value handling
- Structured data extraction (rectangles, points, sizes)

---

### `Private/PaperImporterSettings.h` & `Private/PaperImporterSettings.cpp`
**Purpose:** Settings class for Paper2D asset import and creation.

**Core Functions:**
- `ApplySettingsForSpriteInit()` - Applies default settings when creating sprites:
  - Material selection (masked, translucent, opaque)
  - Lighting mode (lit/unlit)
  - Pixels per unreal unit
  - Texture compression settings
- `ApplySettingsForTileMapInit()` - Applies default settings when creating tile maps
- `AnalyzeTextureForDesiredMaterialType()` - Analyzes texture alpha channel to determine best material type
- `RemoveSuffixFromBaseMapName()` - Removes base map suffixes for normal map lookup
- `GenerateNormalMapNamesToTest()` - Generates possible normal map names to search
- `ApplyTextureSettings()` - Applies texture compression and group settings
- `GetDefaultMaterial()` - Gets default material based on type and lighting mode
- `GetDefaultMaskedMaterial()` - Gets masked material
- `GetDefaultTranslucentMaterial()` - Gets translucent material
- `GetDefaultOpaqueMaterial()` - Gets opaque material

**Key Features:**
- Automatic material selection based on texture analysis
- Normal map auto-detection
- Configurable import defaults
- Texture compression settings

---

## Viewport Classes

### `Private/PaperEditorViewportClient.h` & `Private/PaperEditorViewportClient.cpp`
**Purpose:** Base viewport client for Paper2D editors.

**Core Functions:**
- `Tick()` - Updates viewport, handles deferred zoom
- `GetBackgroundColor()` - Returns viewport background color
- `RequestFocusOnSelection()` - Requests focus on selected objects
- `ModifyCheckerboardTextureColors()` - Updates checkerboard texture colors
- `SetupCheckerboardTexture()` - Creates checkerboard texture for transparency visualization
- `DestroyCheckerboardTexture()` - Cleans up checkerboard texture
- `DrawSelectionRectangles()` - Draws selection rectangles in viewport
- `GetDesiredFocusBounds()` - Returns bounds to focus on (virtual, overridden by subclasses)
- `SetZoomPos()` - Sets zoom position and amount

**Key Features:**
- Checkerboard background for transparency
- Selection rectangle rendering
- Zoom and pan support
- Paper2D axis-aware viewport setup

---

### `Private/SPaperEditorViewport.h` & `Private/SPaperEditorViewport.cpp`
**Purpose:** Slate widget for Paper2D editor viewports.

**Core Functions:**
- `Construct()` - Initializes the viewport widget
- `Tick()` - Updates viewport, handles marquee selection, panning
- `OnMouseButtonDown()` - Handles mouse button press (marquee selection, panning)
- `OnMouseButtonUp()` - Handles mouse button release
- `OnMouseMove()` - Handles mouse movement (marquee dragging, panning)
- `OnMouseWheel()` - Handles mouse wheel (zooming)
- `OnCursorQuery()` - Returns cursor type
- `OnPaint()` - Renders the viewport
- `GetZoomAmount()` - Gets current zoom level
- `GetZoomText()` - Gets zoom level display text
- `GetViewOffset()` - Gets view offset
- `GraphCoordToPanelCoord()` - Converts graph space to panel space
- `PanelCoordToGraphCoord()` - Converts panel space to graph space
- `ComputeEdgePanAmount()` - Calculates edge panning amount
- `UpdateViewOffset()` - Updates view offset based on mouse position
- `PaintSoftwareCursor()` - Renders software cursor during panning

**Key Features:**
- 17 zoom levels (1:32 to 32x)
- Marquee selection with Ctrl/Shift modifiers
- Right-click panning with software cursor
- Mouse wheel zooming
- Edge panning support
- Coordinate space conversion

---

## Asset Brokers

### `Private/PaperSpriteAssetBroker.h` & `Private/PaperSpriteAssetBroker.cpp`
**Purpose:** Component asset broker for PaperSpriteComponent.

**Core Functions:**
- Enables drag-and-drop of sprites onto components in the level
- Assigns sprite assets to sprite components

---

### `Private/PaperFlipbookAssetBroker.h` & `Private/PaperFlipbookAssetBroker.cpp`
**Purpose:** Component asset broker for PaperFlipbookComponent.

**Core Functions:**
- Enables drag-and-drop of flipbooks onto components in the level
- Assigns flipbook assets to flipbook components

---

### `Private/TileMapEditing/PaperTileMapAssetBroker.h` & `Private/TileMapEditing/PaperTileMapAssetBroker.cpp`
**Purpose:** Component asset broker for PaperTileMapComponent.

**Core Functions:**
- Enables drag-and-drop of tile maps onto components in the level
- Assigns tile map assets to tile map components

---

## Editor Shared

### `Private/PaperEditorShared/SpriteGeometryEditMode.h` & `Private/PaperEditorShared/SpriteGeometryEditMode.cpp`
**Purpose:** Editor mode for editing sprite geometry (collision and rendering polygons).

**Core Functions:**
- Geometry editing tools
- Polygon manipulation
- Vertex editing
- Integration with sprite editor

---

### `Private/PaperEditorShared/SpriteGeometryEditing.h` & `Private/PaperEditorShared/SpriteGeometryEditing.cpp`
**Purpose:** Geometry editing functionality for sprites.

**Core Functions:**
- Polygon creation and editing
- Vertex manipulation
- Collision geometry generation
- Rendering geometry editing

---

### `Private/PaperEditorShared/SpriteGeometryEditCommands.h` & `Private/PaperEditorShared/SpriteGeometryEditCommands.cpp`
**Purpose:** Commands for sprite geometry editing.

**Core Functions:**
- Keyboard shortcuts for geometry editing
- Tool activation commands

---

### `Private/PaperEditorShared/SocketEditing.h` & `Private/PaperEditorShared/SocketEditing.cpp`
**Purpose:** Socket editing functionality for sprites.

**Core Functions:**
- Socket creation and editing
- Socket visualization
- Socket attachment points

---

### `Private/PaperEditorShared/AssetEditorSelectedItem.h`
**Purpose:** Selection management for asset editors.

**Core Functions:**
- Tracks selected items in editors
- Selection change notifications

---

## Atlasing System

### `Private/Atlasing/PaperAtlasGenerator.h` & `Private/Atlasing/PaperAtlasGenerator.cpp`
**Purpose:** Generates sprite atlases from sprite assets.

**Core Functions:**
- Atlas generation from sprite collections
- Texture packing algorithms
- UV coordinate calculation
- Atlas update handling

---

### `Private/Atlasing/PaperAtlasHelpers.h`
**Purpose:** Helper functions for atlas operations.

**Core Functions:**
- Atlas utility functions
- Sprite-to-atlas mapping

---

### `Private/Atlasing/PaperAtlasTextureHelpers.h` & `Private/Atlasing/PaperAtlasTextureHelpers.cpp`
**Purpose:** Texture manipulation helpers for atlas generation.

**Core Functions:**
- Texture copying and compositing
- UV coordinate transformation
- Texture format conversion

---

### `Private/Atlasing/PaperSpriteAtlasFactory.h` & `Private/Atlasing/PaperSpriteAtlasFactory.cpp`
**Purpose:** Factory for creating PaperSpriteAtlas assets.

**Core Functions:**
- Creates atlas assets
- Initializes atlas with sprites

---

## Grouped Sprites

### `Private/GroupedSprites/GroupedSpriteDetailsCustomization.h` & `Private/GroupedSprites/GroupedSpriteDetailsCustomization.cpp`
**Purpose:** Customizes the details panel for PaperGroupedSpriteComponent.

**Core Functions:**
- Custom property layout for grouped sprite component
- Enhanced UI for grouped sprite settings

---

### `Private/GroupedSprites/PaperGroupedSpriteUtilities.h` & `Private/GroupedSprites/PaperGroupedSpriteUtilities.cpp`
**Purpose:** Utility functions for grouped sprites.

**Core Functions:**
- Grouped sprite operations
- Batch manipulation utilities

---

## Extract Sprites

### `Private/ExtractSprites/PaperExtractSpritesSettings.h` & `Private/ExtractSprites/PaperExtractSpritesSettings.cpp`
**Purpose:** Settings for sprite extraction from textures.

**Core Functions:**
- Extraction parameters
- Region detection settings

---

### `Private/ExtractSprites/SPaperExtractSpritesDialog.h` & `Private/ExtractSprites/SPaperExtractSpritesDialog.cpp`
**Purpose:** Dialog widget for sprite extraction.

**Core Functions:**
- UI for sprite extraction
- Preview of extracted sprites
- Extraction parameter configuration

---

## Content Browser Extensions

### `Private/ContentBrowserExtensions/ContentBrowserExtensions.h` & `Private/ContentBrowserExtensions/ContentBrowserExtensions.cpp`
**Purpose:** Extends the content browser with Paper2D-specific actions.

**Core Functions:**
- `InstallHooks()` - Installs content browser menu extensions
- `RemoveHooks()` - Removes content browser extensions
- Adds context menu actions for Paper2D assets

**Key Features:**
- Right-click menu integration
- Asset-specific actions
- Batch operations

---

## Level Editor Extensions

### `Private/LevelEditorMenuExtensions/Paper2DLevelEditorExtensions.h` & `Private/LevelEditorMenuExtensions/Paper2DLevelEditorExtensions.cpp`
**Purpose:** Extends the level editor with Paper2D-specific menu items.

**Core Functions:**
- `InstallHooks()` - Installs level editor menu extensions
- `RemoveHooks()` - Removes level editor extensions
- Adds menu items for Paper2D operations

**Key Features:**
- Level editor menu integration
- Tool access
- Settings access

---

## Mesh Painting

### `Private/MeshPainting/MeshPaintSpriteAdapter.h` & `Private/MeshPainting/MeshPaintSpriteAdapter.cpp`
**Purpose:** Adapter for mesh painting system to work with sprites.

**Core Functions:**
- Enables mesh painting tools to work with sprite geometry
- Geometry extraction for painting
- Integration with mesh paint module

---

## Style and UI

### `Private/PaperStyle.h` & `Private/PaperStyle.cpp`
**Purpose:** Slate style definitions for Paper2D editor UI.

**Core Functions:**
- `Initialize()` - Initializes Paper2D style set
- `Shutdown()` - Cleans up style set
- `Get()` - Returns the style set
- `GetStyleSetName()` - Returns style set name
- `InContent()` - Helper for loading style resources

**Key Features:**
- Custom icons and brushes
- Consistent UI styling
- Theme support

---

### `Private/PaperEditorCommands.h` & `Private/PaperEditorCommands.cpp`
**Purpose:** Global Paper2D editor commands.

**Core Functions:**
- `RegisterCommands()` - Registers global commands (currently empty, commands are in specific editors)

**Key Features:**
- Command registration infrastructure
- Extensible command system

---

## Canvas and Rendering

### `Private/SpriteCanvas.h` & `Private/SpriteCanvas.cpp`
**Purpose:** Canvas widget for sprite rendering in UI.

**Core Functions:**
- Renders sprites in Slate UI
- Supports zoom and pan
- Selection visualization

---

## Import Data

### `Classes/TileMapAssetImportData.h`
**Purpose:** Stores import data for tile map assets.

**Core Functions:**
- Tracks source file information
- Import settings storage
- Reimport support

---

## Logging

### `Private/Paper2DEditorLog.h`
**Purpose:** Log category definition for Paper2DEditor.

**Core Functions:**
- Defines `LogPaper2DEditor` log category
- Used for editor-specific logging

---

## Summary

The Paper2DEditor module is a comprehensive editor system for Paper2D assets in Unreal Engine 5. It provides:

1. **Asset Creation**: Factories for sprites, flipbooks, tile sets, and tile maps
2. **Asset Editing**: Full-featured editors for all asset types with viewports, timelines, and property panels
3. **Visualization**: Thumbnail renderers and viewport clients for asset preview
4. **Integration**: Content browser and level editor extensions for seamless workflow
5. **Utilities**: Helper functions for flipbook creation, JSON import, and atlas generation
6. **Settings**: Comprehensive settings system for import defaults and editor preferences
7. **Geometry Editing**: Tools for editing sprite collision and rendering geometry
8. **Tile Map Tools**: Complete tile map editing system with painting and layer management

The module follows Unreal Engine's standard editor architecture with asset type actions, component brokers, property customizations, and editor modes, providing a professional-grade 2D asset editing experience.

