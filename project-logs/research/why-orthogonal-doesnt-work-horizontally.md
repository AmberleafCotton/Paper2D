# Why Orthogonal Doesn't Work Horizontally (Even With Same Math)

## The Coordinate System Issue

### Paper2D's Default Axes

```cpp
PaperAxisX = FVector(1.0f, 0.0f, 0.0f);  // Right
PaperAxisY = FVector(0.0f, 0.0f, 1.0f);  // Up (Z in world space!)
PaperAxisZ = FVector(0.0f, 1.0f, 0.0f);  // Forward (Y in world space!)
```

**Key Point:** Paper2D uses a **non-standard coordinate system**:
- `PaperAxisY` = Z-axis in world (up)
- `PaperAxisZ` = Y-axis in world (forward)
- Designed for **XZ plane rendering** (vertical wall)

### Orthogonal Mode Math

```cpp
// Orthogonal mode
OutStepX = PaperAxisX * TileWidthInUU;        // (1, 0, 0) * width = moves right
OutStepY = -PaperAxisY * TileHeightInUU;     // -(0, 0, 1) * height = moves down in Z
```

**What this means:**
- StepX moves in X direction (right)
- StepY moves in **-Z direction** (down in Z, which is up in world)
- Grid is on **XZ plane** (vertical wall)

## Why It Doesn't Work Horizontally

### Problem 1: Coordinate System Mismatch

When you rotate Orthogonal to horizontal:
1. **Component rotation** transforms the positions
2. But **PaperAxisY = (0, 0, 1)** is still Z-axis
3. After rotation, this might not align with what you expect

**Example:**
- Orthogonal: StepY = -(0, 0, 1) * height = moves in -Z
- After pitch -90° rotation: -Z becomes -Y (or something else)
- The grid might not align correctly

### Problem 2: Editor Assumptions

The editor might assume Orthogonal is vertical:
- **Viewport setup** might be wrong
- **Grid visualization** might be wrong
- **Tool placement** might be wrong
- **Collision building** might have assumptions

### Problem 3: SeparationPerLayer

```cpp
const float TotalSeparation = (SeparationPerLayer * LayerIndex) + 
                              (SeparationPerTileX * TileX) + 
                              (SeparationPerTileY * TileY);
const FVector PartialZ = TotalSeparation * PaperAxisZ;
```

**Issue:** `SeparationPerLayer` uses `PaperAxisZ = (0, 1, 0)` (Y-axis)
- For vertical placement: This is depth (correct)
- For horizontal placement: This might be wrong direction

### Problem 4: Collision Building

```cpp
// PaperTileLayer.cpp - Collision building
case ETileMapProjectionMode::Orthogonal:
    ProjectionOffset.X = TileWidth * CellX;
    ProjectionOffset.Y = TileHeight * -CellY;  // ← Uses Y, but should be Z for horizontal?
```

**Issue:** Collision uses X/Y offsets, but for horizontal you might need X/Z

## The Real Answer

### Orthogonal CAN Work, BUT...

**Technically:** If you rotate the component, the transform should handle it.

**Practically:** There are issues:
1. **Editor UI** assumes vertical placement
2. **Collision building** might use wrong axes
3. **SeparationPerLayer** uses wrong axis
4. **No clear workflow** for horizontal + 45° rotation

### Why LandscapeIsometric is Needed

**Not for different math** - the math IS the same!

**But for:**
1. **Clear intent** - "This is for horizontal + 45° rotation"
2. **Editor support** - UI can assume horizontal placement
3. **Documentation** - Clear workflow
4. **Future fixes** - Can adjust collision/rendering if needed

## The Truth

**Orthogonal math works horizontally** if you rotate the component.

**BUT:**
- Editor might not support it well
- Collision might be wrong
- No clear workflow
- Might have edge cases

**LandscapeIsometric:**
- Same math (Orthogonal)
- But with clear intent and workflow
- Can fix editor/collision issues if needed
- Documents the "horizontal + 45°" use case

## Conclusion

**You're right to question this!** The math IS the same.

**But:** Orthogonal mode has assumptions/edge cases that make it hard to use horizontally.

**Solution:** LandscapeIsometric = Orthogonal math + clear intent + proper workflow documentation.

**Alternative:** We could just document how to use Orthogonal horizontally + 45°, but having a separate mode makes it clearer and allows for future fixes.

