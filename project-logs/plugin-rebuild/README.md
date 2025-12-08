# Plugin Rebuild Tools

This folder contains tools for rebuilding the Paper2D engine plugin after making code changes.

## 📁 Files

### 📄 rebuild-documentation.md
Complete guide explaining the rebuild process and how to handle marketplace plugin conflicts.

### 🔧 rebuild-paper2d.bat
**One-click rebuild for Paper2D plugin**
- Automatically handles marketplace plugin conflicts
- Colored console output
- Double-click to run!

### 🔧 rebuild-plugin.bat
**Universal plugin rebuilder**
- Works with any engine plugin
- Prompts for plugin paths
- Handles marketplace conflicts

## 🚀 Quick Start

**To rebuild Paper2D:**
```
Double-click: rebuild-paper2d.bat
```

**To rebuild another plugin:**
```
Double-click: rebuild-plugin.bat
Then follow the prompts
```

## ⚠️ Important Notes

- Scripts automatically backup and restore marketplace plugins that conflict
- Built plugins are in: `C:\Users\AmberleafCotton\Desktop\Packaged\HostProject\Plugins\`
- Scripts auto-copy to engine directory after build
- Always check console for colored status messages

## 🎯 The Process

1. 🔒 Backup conflicting marketplace plugins (PaperZD, Aseprite)
2. 🔨 Run BuildPlugin command
3. 📋 Copy built plugin to engine directory
4. 🔓 Restore marketplace plugins

All automated! ✨
