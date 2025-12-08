# Quick-Win Improvements from Tiled to Paper2D

Based on research into Tiled Map Editor's most successful features, here are improvements prioritized by implementation difficulty and user value.

---

## 🟢 QUICK WINS (Low Effort, High Impact)

### 1. **Right-Click Tile Capture (Eyedropper Enhancement)**
**What Tiled has:** Right-click any tile to instantly "capture" it as the active stamp. Drag to capture areas.

**Current Paper2D:** Has eyedropper tool, but requires tool switching.

**Implementation:**
- Modify `InputKey()` to detect right-click on tile
- Set active paint to clicked tile (already have `SetActivePaintFromLayer()`)
- ~50 lines of code

**Value:** ⭐⭐⭐⭐⭐ - Massive workflow improvement

---

### 2. **Tile Rotation Shortcuts (X, Y, Z)**
**What Tiled has:**
- `X` = Flip horizontal
- `Y` = Flip vertical  
- `Z` = Rotate clockwise
- `Shift+Z` = Rotate counter-clockwise

**Current Paper2D:** Has rotation functions (`FlipSelectionHorizontally()`, etc.) but no keyboard shortcuts.

**Implementation:**
- Add keyboard shortcut bindings in `InputKey()`
- Call existing flip/rotate functions
- ~30 lines of code

**Value:** ⭐⭐⭐⭐⭐ - Super fast tile manipulation

---

### 3. **Random Tile Mode (D key)**
**What Tiled has:** Press `D` to enable random tile placement from selection. Great for organic terrain.

**Current Paper2D:** No random mode.

**Implementation:**
- Add boolean flag `bRandomTileMode`
- When painting, randomly select from current tile selection
- ~80 lines of code

**Value:** ⭐⭐⭐⭐ - Natural-looking terrain becomes trivial

---

### 4. **Tool Keyboard Shortcuts (B, F, E, S)**
**What Tiled has:**
- `B` = Brush tool
- `F` = Fill/Bucket tool
- `E` = Eraser
- `S` = Select

**Current Paper2D:** Must click UI buttons to switch tools.

**Implementation:**
- Modify `InputKey()` to call `SetActiveTool()`
- ~40 lines of code

**Value:** ⭐⭐⭐⭐ - Faster tool switching

---

### 5. **Persistent Brush (Stamp stays after painting)**
**What Tiled has:** After painting, the stamp remains active. Can paint again immediately.

**Current Paper2D:** May lose selection after some operations.

**Implementation:**
- Ensure `SetActivePaint()` doesn't clear after paint commit
- Review and fix selection persistence
- ~20 lines of code

**Value:** ⭐⭐⭐ - Less repetitive selection

---

## 🟡 MEDIUM EFFORT (Moderate Complexity, High Impact)

### 6. **Terrain Brush / Autotiling**
**What Tiled has:** Define tile transition rules, paint automatically handles corners/edges.

**Current Paper2D:** Has `TerrainBrush` stub but not implemented.

**Implementation:**
- Define terrain rules format (JSON/asset)
- Implement matching algorithm (check 8 neighbors)
- Select correct tile variant based on surroundings
- ~300-500 lines of code

**Value:** ⭐⭐⭐⭐⭐ - Huge time saver for organic maps

---

### 7. **Stamp Brush (Multi-Tile Patterns)**
**What Tiled has:** Select multiple tiles, paint them as a pattern/stamp.

**Current Paper2D:** Partially exists (can select multi-tile from eyedropper) but could be enhanced.

**Implementation:**
- Enhance existing brush system
- Add stamp palette/library for saving common patterns
- ~150-200 lines of code

**Value:** ⭐⭐⭐⭐ - Fast repetitive pattern placement

---

### 8. **Tile Animation Editor**
**What Tiled has:** Define animated tiles directly in the tileset.

**Current Paper2D:** No built-in tile animation support in editor.

**Implementation:**
- New UI panel for animation sequences
- Store animation data in tileset asset
- Render animated frames in preview
- ~400-600 lines of code + UI

**Value:** ⭐⭐⭐⭐ - Animated tiles without sprites

---

## 🔴 HIGH EFFORT (Complex, But Valuable)

### 9. **Custom Properties System**
**What Tiled has:** Add key-value pairs to tiles, objects, layers. Export to game logic.

**Current Paper2D:** Limited metadata support.

**Implementation:**
- Create property editor UI
- Add FProp ertyBag or TMap to tile/layer classes
- Export system to blueprint/C++
- ~800+ lines of code + UI

**Value:** ⭐⭐⭐⭐⭐ - Game-specific data integration

---

### 10. **AutoMapping (Rule-Based Tile Placement)**
**What Tiled has:** Define input/output patterns. Automatically replace tiles based on rules.

**Current Paper2D:** Nothing like this exists.

**Implementation:**
- Rule definition system (complex!)
- Pattern matching algorithm
- Apply transformation engine
- ~1000+ lines of code

**Value:** ⭐⭐⭐⭐⭐ - But VERY complex to implement well

---

## 📋 Recommended Implementation Order

### Phase 1 (Within 1-2 days)
1. ✅ Right-click tile capture
2. ✅ Tile rotation shortcuts (X, Y, Z)
3. ✅ Tool keyboard shortcuts (B, F, E, S)

### Phase 2 (Within 1 week)
4. ✅ Random tile mode (D key)
5. ✅ Persistent brush
6. ✅ Stamp brush enhancements

### Phase 3 (Future)
7. Terrain brush / Autotiling
8. Tile animation editor
9. Custom properties
10. AutoMapping

---

## Implementation Notes

### Existing Code Hooks
Most quick wins can hook into existing functions:
- `InputKey()` - For keyboard shortcuts
- `SetActivePaint()` - For tile selection
- `FlipSelectionHorizontally/Vertically()` - Already exist!
- `RotateSelectionCW/CCW()` - Already exist!
- `SetActiveTool()` - For tool switching

### Files to Modify
- `EdModeTileMap.h` - Add member variables
- `EdModeTileMap.cpp` - Input handling and logic
- Minimal UI changes needed for Phase 1 features

---

## Quick Reference: Tiled Shortcuts to Add

| Key | Action | Paper2D Status |
|-----|--------|----------------|
| **B** | Brush tool | ❌ No shortcut |
| **D** | Random mode toggle | ❌ Doesn't exist |
| **E** | Eraser | ❌ No shortcut |
| **F** | Fill/Bucket | ❌ No shortcut |
| **S** | Select | ❌ No shortcut |
| **X** | Flip horizontal | ✅ Function exists, ❌ no shortcut |
| **Y** | Flip vertical | ✅ Function exists, ❌ no shortcut |
| **Z** | Rotate CW | ✅ Function exists, ❌ no shortcut |
| **Shift+Z** | Rotate CCW | ✅ Function exists, ❌ no shortcut |
| **Right-Click** | Capture tile | ⚠️ Has eyedropper, not direct |

---

**Bottom Line:** We could implement features 1-5 (all the quick wins) in probably 2-3 days of work and dramatically improve the Paper2D editor workflow! 🚀
