# Paper2D Plugin - Project Specifications

> [!NOTE]
> This document outlines the project-specific goals and requirements for Paper2D plugin enhancements. These specifications focus on isometric 2D game development needs and will inform future improvement plans.

**Last Updated:** 2025-12-07  
**Project Focus:** Isometric 2D Game Development

---

## Core Focus

### Isometric Diamond Projection Mode
- **Primary projection mode** for the entire project
- All improvements and optimizations should prioritize this mode
- Need full feature parity with orthogonal mode
- Performance optimization specifically for isometric rendering

---

## Tile Editor Enhancements

### Performance Improvements
- **Critical:** Fix lag when drawing/painting tiles in the editor
- Need smooth, responsive tile painting experience
- Performance should scale well with larger maps
- Optimize rendering during edit mode

### Tile Set Management
- Better organization of tile sets within the editor
- Improved tile set browser/selector
- Quick access to frequently used tiles
- Preview improvements for tile selection

### Tile Creation & Editing
- **In-engine tile creation** - create new tiles without leaving Unreal Engine
- Quick tile duplication and modification
- Ability to make small adjustments to existing tiles
- Add duplicated tiles to tile set instantly
- Tile variations and quick iterations

---

## Tile Rules System

### Rule-based Tile Placement
- **New feature:** Tile rules/auto-tiling system (not currently available)
- Automatic tile selection based on neighboring tiles
- Support for corner tiles, edge tiles, transitions
- Rule templates for common patterns
- Visual rule editor

### Use Cases
- Auto-connecting walls/paths
- Terrain transitions (grass to dirt, etc.)
- Platform edges and corners
- Automatic tile variation

---

## Tile Data & Metadata

### Per-Tile Data Storage
- Ability to select individual tiles in the tile map
- Assign custom data/properties to each tile instance
- Support for various data types (int, float, string, bool, custom structs)
- Data visible and editable in editor

### Runtime Tile Data
- Game can read tile data at location (x, y)
- Game can write/modify tile data at runtime
- Game can add/change tiles at specific coordinates
- Events/notifications when tile data changes

### Data Types
- Tile properties (walkable, damage, speed modifier, etc.)
- Gameplay tags
- Custom metadata
- References to other assets
- Scriptable tile behaviors

---

## Terrain & Height Adjustment

### Tile Heights
- Support for different tile heights/elevations
- Smooth transitions between different heights
- Visual representation of height in editor

### Terrain Angles
- Angled tiles for slopes and ramps
- **Question:** Is this a plugin-level feature or game-level implementation?
- Need to determine best approach for isometric height variation

### Considerations
- May need custom implementation outside plugin scope
- Could use layering + sorting for pseudo-height
- Investigate if plugin should handle this or leave to game code

---

## Editor Workflow Improvements

### General Editor UX
- Take inspiration from **Tiled Map Editor** software
- Streamline common workflows
- Keyboard shortcuts and hotkeys
- Better visual feedback during editing

### Isometric Map Preview
- **Better in-level preview** for isometric maps
- Improved gizmos for isometric placement
- Grid overlay that matches isometric perspective
- Easier item placement and adjustment on isometric maps
- Camera helpers for isometric view

### Tile Editor Toolbar
- Quick access to common tools
- Brush size controls
- Fill tool improvements
- Selection tools (rectangle, magic wand, etc.)
- Copy/paste tile regions

---

## Future Considerations

### Areas to Explore
- Layer management improvements
- Collision editing workflow
- Multi-tile stamps/prefabs
- Tile animation support within tile maps
- Export/import improvements

### Inspiration Sources
- Tiled Map Editor features
- Other successful 2D game engines
- Community feedback and requests

---

## Success Criteria

### Performance
- No lag when painting tiles in editor
- Smooth real-time preview
- Fast map loading and saving

### Usability
- Intuitive tile placement in isometric mode
- Quick iteration on tile creation
- Minimal clicks to achieve common tasks

### Features
- Tile rules system working and intuitive
- Per-tile data fully implemented
- In-engine tile editing functional

---

## Notes

- This is a living document - specifications will evolve as development progresses
- Some features may require plugin source modifications
- Balance between plugin improvements vs. game-specific implementations
- Consider backward compatibility with existing Paper2D projects

---

*Related Documents:*
- [documentation.md](file:///e:/Unreal%20Engine/UE_5.6/Engine/Plugins/2D/Paper2D/project-logs/documentation.md) - Complete Paper2D plugin documentation
