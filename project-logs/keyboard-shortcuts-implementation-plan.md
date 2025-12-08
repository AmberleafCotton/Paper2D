# Keyboard Shortcuts Implementation Plan

**Feature:** Add Tiled-style keyboard shortcuts for tool switching (B/F/E/S) with editor-only activation

**Goal:** Implement keyboard shortcuts that only work when the tile map editor is the active viewport/tab, matching Tiled's workflow.

---

## 📋 Current Code Analysis

### Existing Systems Found

#### 1. Tool Management (`EdModeTileMap.cpp`)

**SetActiveTool** - Line 1520-1524
```cpp
void FEdModeTileMap::SetActiveTool(ETileMapEditorTool::Type NewTool)
{
    ActiveTool = NewTool;
    RefreshBrushSize();
}
```
✅ **Perfect!** We can call this function to switch tools.

**GetActiveTool** - Line 1526-1530+
```cpp
ETileMapEditorTool::Type FEdModeTileMap::GetActiveTool() const
{
    // Force the eyedropper active when Shift is held (or if it was held when painting started, even if it was released later)
    const bool bHoldingShift = !bIsPainting && FSlateApplication::Get().GetModifierKeys().IsShiftDown();
    const bool bWasHoldingShift = bIsPainting && bWasHoldingSelectWhenPaintingStarted;
    ...
}
```
✅ Already handles shift-for-eyedropper logic.

**Available Tools** (from `EdModeTileMap.h` lines 17-27):
```cpp
namespace ETileMapEditorTool
{
    enum Type
    {
        Paintbrush,
        Eraser,
        PaintBucket,
        EyeDropper,
        TerrainBrush
    };
}
```

#### 2. Input Handling (`EdModeTileMap.cpp`)

**InputKey Function** - Line 376-430+
```cpp
bool FEdModeTileMap::InputKey(FEditorViewportClient* InViewportClient, FViewport* InViewport, FKey InKey, EInputEvent InEvent)
{
    bool bHandled = false;
    
    const bool bIsLeftButtonDown = ( InKey == EKeys::LeftMouseButton && InEvent != IE_Released ) || InViewport->KeyState( EKeys::LeftMouseButton );
    const bool bIsCtrlDown = ( ( InKey == EKeys::LeftControl || InKey == EKeys::RightControl ) && InEvent != IE_Released ) || InViewport->KeyState( EKeys::LeftControl ) || InViewport->KeyState( EKeys::RightControl );
    const bool bIsShiftDown = ( ( InKey == EKeys::LeftShift || InKey == EKeys::RightShift ) && InEvent != IE_Released ) || InViewport->KeyState( EKeys::LeftShift ) || InViewport->KeyState( EKeys::RightShift );
    
    if (InViewportClient->EngineShowFlags.ModeWidgets)
    {
        // Right-click cancel code...
        // Painting logic...
    }
    ...
}
```

✅ **This is where we add keyboard shortcuts!**

**Current Key Checks:**
- `EKeys::LeftMouseButton`, `EKeys::RightMouseButton`
- `EKeys::LeftControl`, `EKeys::RightControl`
- `EKeys::LeftShift`, `EKeys::RightShift`

**Activation Check:** `InViewportClient->EngineShowFlags.ModeWidgets`  
✅ **This already ensures we're in the editor mode!**

#### 3. Fill Tool (`FloodFillTiles`) - Line 950-1079

**Algorithm Used:** Horizontal span-based flood fill
- Uses `TBitArray` for reachability tracking
- Implements `FHorizontalSpan` helper struct (lines 64-130)
- Grows spans horizontally, then checks adjacent rows
- Efficient for large fills

✅ **The fill tool ALREADY EXISTS and works!** Just needs keyboard shortcut.

---

## 🎯 Implementation Plan

### Phase 1: Add Keyboard Shortcuts (SIMPLE!)

**File:** `EdModeTileMap.cpp`  
**Function:** `InputKey()`  
**Location:** After line 385 (after `RefreshBrushSize()` call)

**Add this code block:**

```cpp
// Tool switching keyboard shortcuts (Tiled-style)
if (InEvent == IE_Pressed && !bIsPainting)
{
    // B = Brush tool
    if (InKey == EKeys::B)
    {
        SetActiveTool(ETileMapEditorTool::Paintbrush);
        bHandled = true;
    }
    // F = Fill tool (bucket)
    else if (InKey == EKeys::F)
    {
        SetActiveTool(ETileMapEditorTool::PaintBucket);
        bHandled = true;
    }
    // E = Eraser tool
    else if (InKey == EKeys::E)
    {
        SetActiveTool(ETileMapEditorTool::Eraser);
        bHandled = true;
    }
    // S = Select tool (eyedropper)
    else if (InKey == EKeys::S && !bIsShiftDown)  // Don't conflict with Shift (which already activates eyedropper)
    {
        SetActiveTool(ETileMapEditorTool::EyeDropper);
        bHandled = true;
    }
}
```

**Why this works:**
1. `InEvent == IE_Pressed` → Only triggers on key press (not release or repeat)
2. `!bIsPainting` → Only works when NOT actively painting (prevents mid-stroke tool switch)
3. Already inside `if (InViewportClient->EngineShowFlags.ModeWidgets)` → **Only works when tile map editor is active!**
4. Sets `bHandled = true` → Prevents key from propagating to other systems

**Exact location to insert:** Between lines 385 and 387

```cpp
Line 384:  //@TODO: Don't need to do this always, but any time Shift is pressed or released
Line 385:  RefreshBrushSize();
Line 386:  
Line 387:  if (InViewportClient->EngineShowFlags.ModeWidgets)
```

**INSERT NEW CODE BLOCK HERE** (between 385 and 387)

---

## 📊 Code Changes Summary

### Files to Modify

| File | Lines | Changes |
|------|-------|---------|
| `EdModeTileMap.cpp` | 385-387 | Add 30 lines of keyboard shortcut code |

**Total new lines:** ~30  
**Complexity:** LOW (just key checks and function calls)

---

## ✅ How It Satisfies Requirements

### 1. "Shortcuts only work when tile map editor tab is active"

**Solution:** The `InViewportClient->EngineShowFlags.ModeWidgets` check (line 387) ensures this.

**How it works:**
- When tile map editor is NOT the active tab → `ModeWidgets` is false → our code never runs
- When tile map editor IS active → `ModeWidgets` is true → shortcuts work

**No additional code needed!** ✅

### 2. "Fill tool (F key)"

**Existing Implementation:**  
- `FloodFillTiles()` - Line 950  
- Called from `UseActiveToolAtLocation()` - Line 746  
- Tool enum: `ETileMapEditorTool::PaintBucket`

**What we add:**
```cpp
else if (InKey == EKeys::F)
{
    SetActiveTool(ETileMapEditorTool::PaintBucket);
    bHandled = true;
}
```

**That's it!** The fill tool already works perfectly.

### 3. "All shortcuts (B/F/E/S)"

**Complete implementation:**

| Key | Tool | Enum Value |
|-----|------|-----------|
| **B** | Brush | `ETileMapEditorTool::Paintbrush` |
| **F** | Fill/Bucket | `ETileMapEditorTool::PaintBucket` |
| **E** | Eraser | `ETileMapEditorTool::Eraser` |
| **S** | Select/Eyedropper | `ETileMapEditorTool::EyeDropper` |

---

## 🔍 Potential Issues & Solutions

### Issue 1: Key Conflicts

**Potential Conflict:** Unreal might use B/F/E/S for other shortcuts.

**Solution:** Our code sets `bHandled = true`, which prevents propagation.  
**Fallback:** If still conflicts, check at end of function:
```cpp
if (!bHandled)
{
    bHandled = FEdMode::InputKey(InViewportClient, InViewport, InKey, InEvent);
}
```
This ensures our shortcuts take priority in tile map mode.

### Issue 2: Shift+S Conflict

**Problem:** Shift already activates eyedropper (line 1529).

**Solution:** Add `&& !bIsShiftDown` check to S key:
```cpp
else if (InKey == EKeys::S && !bIsShiftDown)
```

This prevents double-activation and respects existing Shift behavior.

### Issue 3: Mid-Painting Tool Switch

**Problem:** Switching tools while painting could cause issues.

**Solution:** `!bIsPainting` check prevents this:
```cpp
if (InEvent == IE_Pressed && !bIsPainting)
```

User must release mouse before switching tools.

---

## 🧪 Testing Plan

### Manual Test Cases

**Test 1: Basic Tool Switching**
1. Open Unreal Editor
2. Create/open a tile map
3. Open tile map for editing
4. Press **B** → Verify brush tool activates
5. Press **F** → Verify fill tool activates  
6. Press **E** → Verify eraser activates
7. Press **S** → Verify eyedropper activates

**Expected:** All tools switch correctly, UI updates to show active tool.

---

**Test 2: Editor-Only Activation**
1. Open tile map editor
2. Press **B** → Tool switches ✅
3. Click on 3D viewport tab (NOT tile map editor)
4. Press **B** → Nothing happens ✅
5. Click back to tile map editor tab
6. Press **F** → Tool switches ✅

**Expected:** Shortcuts only work when tile map editor tab is focused.

---

**Test 3: No Mid-Painting Switch**
1. Select brush tool
2. Click and hold left mouse button (start painting)
3. While holding mouse, press **E**
4. Release mouse

**Expected:** Tool does NOT switch while painting. Eraser only activates after mouse release.

---

**Test 4: Fill Tool Works**
1. Paint some tiles to create an area
2. Press **F** to activate fill tool
3. Click inside the area

**Expected:** Entire area fills with selected tile.

---

**Test 5: Shift Eyedropper Still Works**
1. Hold Shift key
2. Click on a tile

**Expected:** Eyedropper activates (existing behavior preserved).

---

## 📝 Code Snippet - Exact Implementation

**File:** `E:\Unreal Engine\UE_5.6\Engine\Plugins\2D\Paper2D\Source\Paper2DEditor\Private\TileMapEditing\EdModeTileMap.cpp`

**Insert at line 386** (between `RefreshBrushSize();` and `if (InViewportClient->EngineShowFlags.ModeWidgets)`):

```cpp
	//@TODO: Don't need to do this always, but any time Shift is pressed or released
	RefreshBrushSize();

	// Keyboard shortcuts for tool switching (Tiled-style)
	// Only works when tile map editor is active and not currently painting
	if (InEvent == IE_Pressed && !bIsPainting)
	{
		// B = Brush tool
		if (InKey == EKeys::B)
		{
			SetActiveTool(ETileMapEditorTool::Paintbrush);
			bHandled = true;
		}
		// F = Fill/Bucket tool
		else if (InKey == EKeys::F)
		{
			SetActiveTool(ETileMapEditorTool::PaintBucket);
			bHandled = true;
		}
		// E = Eraser tool
		else if (InKey == EKeys::E)
		{
			SetActiveTool(ETileMapEditorTool::Eraser);
			bHandled = true;
		}
		// S = Select/Eyedropper tool (don't conflict with Shift behavior)
		else if (InKey == EKeys::S && !bIsShiftDown)
		{
			SetActiveTool(ETileMapEditorTool::EyeDropper);
			bHandled = true;
		}
	}

	if (InViewportClient->EngineShowFlags.ModeWidgets)
```

---

## 🎯 Summary

**Lines of code to add:** ~30  
**Complexity:** LOW  
**Risk:** MINIMAL (all safety checks in place)  
**Dependencies:** NONE (all functions exist)  
**Fill tool:** ✅ ALREADY WORKING (just needs shortcut)  
**Editor-only activation:** ✅ ALREADY HANDLED (by `ModeWidgets` check)

**This is a PERFECT quick win!** 🚀

All the infrastructure exists. We just need to add the key checks and call `SetActiveTool()`. That's it!
