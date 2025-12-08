# How to Rebuild Engine Plugins

## Quick Summary

When rebuilding an engine plugin, marketplace plugins that depend on it will block the build. The solution:

1. **Remove problematic marketplace plugins temporarily**
2. **Run the build command**
3. **Copy the built plugin back to engine**
4. **Restore marketplace plugins**

---

## For Paper2D Plugin

### Step 1: Remove Conflicting Plugins
Temporarily cut these folders to your Desktop:
- `E:\Unreal Engine\UE_5.6\Engine\Plugins\Marketplace\PaperZD8b0e064aa89dV19`
- `E:\Unreal Engine\UE_5.6\Engine\Plugins\Marketplace\Asepritec187d063b6d7V4`

### Step 2: Run Build Command
```cmd
cd "E:\Unreal Engine\UE_5.6\Engine\Build\BatchFiles"
.\RunUAT.bat BuildPlugin -plugin="E:\Unreal Engine\UE_5.6\Engine\Plugins\2D\Paper2D\Paper2D.uplugin" -package="C:\Users\AmberleafCotton\Desktop\Packaged"
```

### Step 3: Copy Built Plugin
Built plugin location: `C:\Users\AmberleafCotton\Desktop\Packaged\HostProject\Plugins\Paper2D`

Copy the entire `Paper2D` folder to: `E:\Unreal Engine\UE_5.6\Engine\Plugins\2D\Paper2D`

### Step 4: Restore Marketplace Plugins
Move the folders back from Desktop to `E:\Unreal Engine\UE_5.6\Engine\Plugins\Marketplace\`

---

## For Any Plugin

### If Build Fails with Module Validation Errors

Look for errors like:
```
Module 'PluginName' (Marketplace) should not reference module 'YourPlugin' (Plugin)
```

**Fix**: Temporarily remove `PluginName` from the Marketplace folder, rebuild, then restore it.

---

## Automated Scripts

### Paper2D Specific
Run: **`rebuild-paper2d.bat`**

### Universal Plugin Builder  
Run: **`rebuild-plugin.bat`** (prompts for plugin details)

---

## Commands Reference

### Manual Build Command Template
```cmd
cd "E:\Unreal Engine\UE_5.6\Engine\Build\BatchFiles"
.\RunUAT.bat BuildPlugin -plugin="[PATH_TO_UPLUGIN]" -package="[OUTPUT_PATH]"
```

**Output always goes to**: `[OUTPUT_PATH]\HostProject\Plugins\[PluginName]`
