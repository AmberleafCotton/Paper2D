# Tile Map Drawing Tools Documentation

## Overview

This document describes the implementation of tile map drawing tools (Paint, Eraser, PaintBucket) and how to add a new Rectangle drawing tool.

---

## Tool System Architecture

### 1. Tool Enum Definition

**Location:** `EdModeTileMap.h` (Lines 18-28)

```cpp
namespace ETileMapEditorTool
{
	enum Type
	{
		Paintbrush,      // Paint tool [B]
		Eraser,          // Eraser tool [E]
		PaintBucket,     // Fill tool [G]
		EyeDropper,      // Select tool [S]
		TerrainBrush     // Terrain tool
	};
}
```

**Purpose:** Defines all available tools as an enum. This is the central definition point for tools.

---

### 2. Command Registration

**Location:** `TileMapEditorCommands.cpp` (Lines 14-18)

```cpp
UI_COMMAND(SelectPaintTool, "Paint", "Paint", EUserInterfaceActionType::RadioButton, FInputChord(EKeys::B));
UI_COMMAND(SelectEraserTool, "Eraser", "Eraser", EUserInterfaceActionType::RadioButton, FInputChord(EKeys::E));
UI_COMMAND(SelectFillTool, "Fill", "Paint Bucket", EUserInterfaceActionType::RadioButton, FInputChord(EKeys::G));
UI_COMMAND(SelectEyeDropperTool, "Select", "Select already-painted tiles", EUserInterfaceActionType::RadioButton, FInputChord());
UI_COMMAND(SelectTerrainTool, "Terrain", "Terrain", EUserInterfaceActionType::RadioButton, FInputChord());
```

**Purpose:** 
- Registers keyboard shortcuts for each tool
- Defines tool names and tooltips
- Uses `RadioButton` type so only one tool can be active at a time

**Key Parameters:**
- `EUserInterfaceActionType::RadioButton` - Makes tools mutually exclusive
- `FInputChord(EKeys::B)` - Defines keyboard shortcut (B for Paint, E for Eraser, G for Fill)

---

### 3. Command Declaration

**Location:** `TileMapEditorCommands.h` (Lines 31-35)

```cpp
TSharedPtr<FUICommandInfo> SelectPaintTool;
TSharedPtr<FUICommandInfo> SelectEraserTool;
TSharedPtr<FUICommandInfo> SelectFillTool;
TSharedPtr<FUICommandInfo> SelectEyeDropperTool;
TSharedPtr<FUICommandInfo> SelectTerrainTool;
```

**Purpose:** Declares command info objects that will be populated during registration.

---

### 4. Command Binding

**Location:** `TileMapEdModeToolkit.cpp` (Lines 224-250)

```cpp
void FTileMapEdModeToolkit::BindCommands()
{
	FTileMapEditorCommands::Register();
	const FTileMapEditorCommands& Commands = FTileMapEditorCommands::Get();

	ToolkitCommands->MapAction(
		Commands.SelectPaintTool,
		FExecuteAction::CreateSP(this, &FTileMapEdModeToolkit::OnSelectTool, ETileMapEditorTool::Paintbrush),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FTileMapEdModeToolkit::IsToolSelected, ETileMapEditorTool::Paintbrush) );
	// ... similar for other tools
}
```

**Purpose:** 
- Binds commands to action handlers
- `OnSelectTool()` - Called when tool is selected
- `IsToolSelected()` - Used to show which tool is currently active (for UI highlighting)

---

### 5. Toolbar Button Creation

**Location:** `TileMapEdModeToolkit.cpp` (Lines 305-311)

```cpp
FToolBarBuilder ToolsToolbar(ToolkitCommands, FMultiBoxCustomization::None);
{
	ToolsToolbar.AddToolBarButton(Commands.SelectEyeDropperTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectPaintTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectEraserTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectFillTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectTerrainTool);
	// ...
}
```

**Purpose:** Creates toolbar buttons for each tool. The order here determines button order in the UI.

---

### 6. Tool Selection Handler

**Location:** `TileMapEdModeToolkit.cpp` (Lines 271-279)

```cpp
void FTileMapEdModeToolkit::OnSelectTool(ETileMapEditorTool::Type NewTool)
{
	TileMapEditor->SetActiveTool(NewTool);
}

bool FTileMapEdModeToolkit::IsToolSelected(ETileMapEditorTool::Type QueryTool) const
{
	return (TileMapEditor->GetActiveTool() == QueryTool);
}
```

**Purpose:**
- `OnSelectTool()` - Sets the active tool in the editor mode
- `IsToolSelected()` - Checks if a specific tool is currently active (for UI state)

---

### 7. Tool Execution

**Location:** `EdModeTileMap.cpp` (Lines 737-755)

```cpp
bool FEdModeTileMap::UseActiveToolAtLocation(const FViewportCursorLocation& Ray)
{
	switch (GetActiveTool())
	{
	case ETileMapEditorTool::EyeDropper:
		return SelectTiles(Ray);
	case ETileMapEditorTool::Paintbrush:
		return PaintTiles(Ray);
	case ETileMapEditorTool::Eraser:
		return EraseTiles(Ray);
	case ETileMapEditorTool::PaintBucket:
		return FloodFillTiles(Ray);
	case ETileMapEditorTool::TerrainBrush:
		return PaintTilesWithTerrain(Ray);
	default:
		check(false);
		return false;
	};
}
```

**Purpose:** Routes tool execution to the appropriate function based on active tool. This is called when the user clicks or drags in the viewport.

---

## Paint Tool Implementation

### Core Paint Function

**Location:** `EdModeTileMap.cpp` (Lines 848-873)

```cpp
bool FEdModeTileMap::PaintTiles(const FViewportCursorLocation& Ray)
{
	bool bPaintedOnSomething = false;

	// If we are using an ink source, validate that it exists
	if (!HasValidSelection())
	{
		return false;
	}

	int32 DestTileX;
	int32 DestTileY;

	if (UPaperTileLayer* TargetLayer = GetSelectedLayerUnderCursor(Ray, /*out*/ DestTileX, /*out*/ DestTileY))
	{
		FBox DirtyRect(ForceInitToZero);
		bPaintedOnSomething = BlitLayer(GetSourceInkLayer(), TargetLayer, /*out*/ DirtyRect, DestTileX, DestTileY);

		if (DirtyRect.IsValid)
		{
			new (PendingDirtyRegions) FTileMapDirtyRegion(FindSelectedComponent(), DirtyRect);
		}
	}

	return bPaintedOnSomething;
}
```

**How It Works:**
1. **Validates Selection** - Checks if there's a valid tile selection to paint with (`HasValidSelection()`)
2. **Gets Cursor Position** - Calculates which tile the cursor is over (`GetSelectedLayerUnderCursor()`)
3. **Blits Layer** - Copies tiles from source ink layer to target layer at cursor position (`BlitLayer()`)
4. **Tracks Dirty Region** - Records which area was modified for navigation mesh updates

---

### BlitLayer Function

**Location:** `EdModeTileMap.cpp` (Lines 757-814)

```cpp
bool FEdModeTileMap::BlitLayer(UPaperTileLayer* SourceLayer, UPaperTileLayer* TargetLayer, FBox& OutDirtyRect, int32 OffsetX, int32 OffsetY, bool bBlitEmptyTiles)
{
	FScopedTransaction Transaction(LOCTEXT("TileMapPaintActionTransaction", "Tile Painting"));

	const int32 LayerCoord = TargetLayer->GetLayerIndex();

	bool bPaintedOnSomething = false;
	bool bChangedSomething = false;

	for (int32 SourceY = 0; SourceY < SourceLayer->GetLayerHeight(); ++SourceY)
	{
		const int32 TargetY = OffsetY + SourceY;
		if ((TargetY < 0) || (TargetY >= TargetLayer->GetLayerHeight()))
		{
			continue;
		}

		for (int32 SourceX = 0; SourceX < SourceLayer->GetLayerWidth(); ++SourceX)
		{
			const int32 TargetX = OffsetX + SourceX;
			if ((TargetX < 0) || (TargetX >= TargetLayer->GetLayerWidth()))
			{
				continue;
			}

			const FPaperTileInfo Ink = SourceLayer->GetCell(SourceX, SourceY);

			if ((Ink.IsValid() || bBlitEmptyTiles) && (TargetLayer->GetCell(TargetX, TargetY) != Ink))
			{
				if (!bChangedSomething)
				{
					TargetLayer->SetFlags(RF_Transactional);
					TargetLayer->Modify();
					bChangedSomething = true;
				}

				OutDirtyRect += FVector(TargetX, TargetY, LayerCoord);
				TargetLayer->SetCell(TargetX, TargetY, Ink);
			}

			bPaintedOnSomething = true;
		}
	}

	if (bChangedSomething)
	{
		TargetLayer->GetTileMap()->PostEditChange();
	}

	if (!bChangedSomething)
	{
		Transaction.Cancel();
	}

	return bPaintedOnSomething;
}
```

**How It Works:**
1. **Creates Transaction** - Wraps operation in undo/redo transaction
2. **Iterates Source Tiles** - Loops through all tiles in the source layer (brush/selection)
3. **Calculates Target Position** - Maps source coordinates to target coordinates with offset
4. **Bounds Checking** - Skips tiles outside the target layer bounds
5. **Copies Tile Data** - Sets target cell to source cell value if different
6. **Tracks Changes** - Records dirty region and marks layer as modified
7. **Commits or Cancels** - Commits transaction if changes made, cancels if not

---

### Continuous Painting (Drag Support)

**Location:** `EdModeTileMap.cpp` (Lines 315-348)

```cpp
if (bIsPainting)
{
	// Only paint with paintbrush tool using preview system
	if (GetActiveTool() == ETileMapEditorTool::Paintbrush)
	{
		int32 CurrentTileX, CurrentTileY;
		if (UPaperTileLayer* Layer = GetSelectedLayerUnderCursor(Ray, /*out*/ CurrentTileX, /*out*/ CurrentTileY))
		{
			FIntPoint CurrentTile(CurrentTileX, CurrentTileY);
			
			if (!bIsStrokeActive)
			{
				// Starting new stroke
				bIsStrokeActive = true;
				PreviewStrokeTiles.Empty();
				OriginalStrokeTiles.Empty();
				PreviewStrokeLayer = Layer;
				bHasLastPaintedPosition = false;
			}
			
			if (bHasLastPaintedPosition)
			{
				// Paint along the line from last position to current (Bresenham interpolation)
				PaintAlongLineToPreview(LastPaintedTilePosition, CurrentTile, Layer);
			}
			else
			{
				// First tile of stroke
				PaintTileToPreview(CurrentTile, Layer);
			}
			
			LastPaintedTilePosition = CurrentTile;
			bHasLastPaintedPosition = true;
		}
	}
}
```

**How It Works:**
1. **Stroke Tracking** - Maintains state for continuous painting during mouse drag
2. **Bresenham Line** - Uses line interpolation to fill gaps when dragging quickly
3. **Preview System** - Paints to preview first, commits on mouse release
4. **Undo Support** - Stores original tiles for undo functionality

---

### Preview Stroke System

**Location:** `EdModeTileMap.cpp` (Lines 1670-1750)

**Key Functions:**
- `PaintTileToPreview()` - Paints a single tile to preview
- `PaintAlongLineToPreview()` - Paints along a line using Bresenham algorithm
- `CommitPreviewStroke()` - Commits all preview tiles to the actual layer
- `CancelPreviewStroke()` - Discards preview changes

**Purpose:** Allows users to see painting results before committing, and supports undo/redo.

---

## Adding a Rectangle Tool

### Step 1: Add Tool Enum

**File:** `EdModeTileMap.h` (Line 22-27)

```cpp
namespace ETileMapEditorTool
{
	enum Type
	{
		Paintbrush,
		Eraser,
		PaintBucket,
		EyeDropper,
		TerrainBrush,
		Rectangle  // ADD THIS
	};
}
```

---

### Step 2: Register Command

**File:** `TileMapEditorCommands.h` (Line 35)

```cpp
TSharedPtr<FUICommandInfo> SelectRectangleTool;  // ADD THIS
```

**File:** `TileMapEditorCommands.cpp` (Line 18)

```cpp
UI_COMMAND(SelectRectangleTool, "Rectangle", "Rectangle Fill", EUserInterfaceActionType::RadioButton, FInputChord(EKeys::R));  // ADD THIS
```

**Note:** Using `R` key as shortcut. Change if it conflicts with other shortcuts.

---

### Step 3: Bind Command

**File:** `TileMapEdModeToolkit.cpp` (Line 250)

```cpp
ToolkitCommands->MapAction(
	Commands.SelectRectangleTool,
	FExecuteAction::CreateSP(this, &FTileMapEdModeToolkit::OnSelectTool, ETileMapEditorTool::Rectangle),
	FCanExecuteAction(),
	FIsActionChecked::CreateSP(this, &FTileMapEdModeToolkit::IsToolSelected, ETileMapEditorTool::Rectangle) );
```

**Add after line 250** (after TerrainTool binding).

---

### Step 4: Add Toolbar Button

**File:** `TileMapEdModeToolkit.cpp` (Line 311)

```cpp
FToolBarBuilder ToolsToolbar(ToolkitCommands, FMultiBoxCustomization::None);
{
	ToolsToolbar.AddToolBarButton(Commands.SelectEyeDropperTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectPaintTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectEraserTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectFillTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectTerrainTool);
	ToolsToolbar.AddToolBarButton(Commands.SelectRectangleTool);  // ADD THIS
	// ...
}
```

**Add after line 311** (after TerrainTool button).

---

### Step 5: Add Tool Execution Case

**File:** `EdModeTileMap.cpp` (Line 750)

```cpp
bool FEdModeTileMap::UseActiveToolAtLocation(const FViewportCursorLocation& Ray)
{
	switch (GetActiveTool())
	{
	case ETileMapEditorTool::EyeDropper:
		return SelectTiles(Ray);
	case ETileMapEditorTool::Paintbrush:
		return PaintTiles(Ray);
	case ETileMapEditorTool::Eraser:
		return EraseTiles(Ray);
	case ETileMapEditorTool::PaintBucket:
		return FloodFillTiles(Ray);
	case ETileMapEditorTool::TerrainBrush:
		return PaintTilesWithTerrain(Ray);
	case ETileMapEditorTool::Rectangle:
		return DrawRectangleTiles(Ray);  // ADD THIS - placeholder function
	default:
		check(false);
		return false;
	};
}
```

---

### Step 6: Add Placeholder Function

**File:** `EdModeTileMap.h` (Line 114)

```cpp
bool PaintTilesWithTerrain(const FViewportCursorLocation& Ray);
bool DrawRectangleTiles(const FViewportCursorLocation& Ray);  // ADD THIS
```

**File:** `EdModeTileMap.cpp` (After line 1153)

```cpp
bool FEdModeTileMap::DrawRectangleTiles(const FViewportCursorLocation& Ray)
{
	// Placeholder - does nothing for now
	return false;
}
```

---

### Step 7: Add Brush Size Support (Optional)

**File:** `EdModeTileMap.cpp` (Lines 1539-1591)

Add cases in `GetBrushWidth()` and `GetBrushHeight()`:

```cpp
case ETileMapEditorTool::Rectangle:
	BrushWidth = 1;  // Or use selection width
	break;
```

```cpp
case ETileMapEditorTool::Rectangle:
	BrushHeight = 1;  // Or use selection height
	break;
```

---

### Step 8: Add Tool Description (Optional)

**File:** `EdModeTileMap.cpp` (Lines 537-550)

Add case in tool description switch:

```cpp
case ETileMapEditorTool::Rectangle:
	ToolDescription = bHasValidInkSource ? LOCTEXT("RectangleTool", "Rectangle") : NoTilesForTool;
	break;
```

---

## Summary of Changes for Rectangle Tool

### Files to Modify:

1. **EdModeTileMap.h**
   - Add `Rectangle` to enum (Line 27)
   - Add `DrawRectangleTiles()` declaration (Line 114)

2. **EdModeTileMap.cpp**
   - Add case in `UseActiveToolAtLocation()` (Line 750)
   - Add `DrawRectangleTiles()` implementation (placeholder)
   - Add cases in `GetBrushWidth()` and `GetBrushHeight()` (Lines 1553-1584)
   - Add case in tool description switch (Line 550)

3. **TileMapEditorCommands.h**
   - Add `SelectRectangleTool` declaration (Line 35)

4. **TileMapEditorCommands.cpp**
   - Add `UI_COMMAND` registration (Line 18)

5. **TileMapEdModeToolkit.cpp**
   - Add command binding (Line 250)
   - Add toolbar button (Line 311)

---

## Tool Execution Flow

```
User Action (Click/Key Press)
    ↓
Command Triggered (SelectPaintTool, etc.)
    ↓
OnSelectTool() Called
    ↓
SetActiveTool() Called
    ↓
Tool State Updated
    ↓
User Clicks/Drags in Viewport
    ↓
UseActiveToolAtLocation() Called
    ↓
Switch Statement Routes to Tool Function
    ↓
Tool Function Executes (PaintTiles, EraseTiles, etc.)
    ↓
Changes Applied to Tile Layer
    ↓
Dirty Region Recorded
    ↓
Navigation Mesh Updated (if needed)
```

---

## Key Data Structures

### Active Tool State
- **Location:** `EdModeTileMap.h` (Line 208)
- **Type:** `ETileMapEditorTool::Type ActiveTool`
- **Purpose:** Stores currently selected tool

### Painting State
- **Location:** `EdModeTileMap.h` (Lines 160-163)
- **Variables:**
  - `bool bWasPainting` - Previous frame painting state
  - `bool bIsPainting` - Current frame painting state
  - `bool bIsStrokeActive` - Whether a continuous stroke is in progress

### Preview Stroke System
- **Location:** `EdModeTileMap.h` (Lines 199-205)
- **Variables:**
  - `TMap<FIntPoint, FPaperTileInfo> PreviewStrokeTiles` - Tiles painted in current stroke
  - `TMap<FIntPoint, FPaperTileInfo> OriginalStrokeTiles` - Original tiles for undo
  - `FIntPoint LastPaintedTilePosition` - Last tile position in stroke
  - `UPaperTileLayer* PreviewStrokeLayer` - Target layer for stroke

---

## Notes

1. **Tool Selection:** Tools are mutually exclusive (RadioButton type)
2. **Keyboard Shortcuts:** Defined in `TileMapEditorCommands.cpp` using `FInputChord`
3. **Tool Execution:** All tools go through `UseActiveToolAtLocation()` switch statement
4. **Preview System:** Paint tool uses preview system for smooth dragging, other tools paint immediately
5. **Undo/Redo:** All painting operations use `FScopedTransaction` for undo support
6. **Dirty Regions:** Modified areas are tracked for navigation mesh updates

---

## Next Steps for Rectangle Tool Implementation

Once the placeholder is in place, implement:

1. **Mouse Down** - Store start position
2. **Mouse Drag** - Calculate rectangle bounds, show preview
3. **Mouse Up** - Fill rectangle with selected tiles
4. **Preview Rendering** - Show rectangle outline during drag
5. **Bounds Checking** - Ensure rectangle stays within layer bounds

The rectangle tool will need to track mouse down/up events separately from the continuous painting system used by the paintbrush tool.

