@echo off
REM ============================================
REM Paper2D Plugin Rebuild Script
REM ============================================
setlocal enabledelayedexpansion

set PLUGIN_PATH=E:\Unreal Engine\UE_5.6\Engine\Plugins\2D\Paper2D\Paper2D.uplugin
set OUTPUT_PATH=C:\Users\AmberleafCotton\Desktop\Packaged
set ENGINE_PLUGIN_DIR=E:\Unreal Engine\UE_5.6\Engine\Plugins\2D\Paper2D
set MARKETPLACE_DIR=E:\Unreal Engine\UE_5.6\Engine\Plugins\Marketplace
set BACKUP_DIR=C:\Users\AmberleafCotton\Desktop\PluginBackup

echo.
echo ================================================
echo  PAPER2D PLUGIN REBUILD
echo ================================================
echo.

REM Step 1: Backup marketplace plugins
echo [1/4] Backing up conflicting marketplace plugins...
if not exist "%BACKUP_DIR%" mkdir "%BACKUP_DIR%"

if exist "%MARKETPLACE_DIR%\PaperZD8b0e064aa89dV19" (
    move "%MARKETPLACE_DIR%\PaperZD8b0e064aa89dV19" "%BACKUP_DIR%\" >nul 2>&1
    echo [92m  √ Moved PaperZD to backup[0m
) else (
    echo [90m  - PaperZD already removed[0m
)

if exist "%MARKETPLACE_DIR%\Asepritec187d063b6d7V4" (
    move "%MARKETPLACE_DIR%\Asepritec187d063b6d7V4" "%BACKUP_DIR%\" >nul 2>&1
    echo [92m  √ Moved Aseprite to backup[0m
) else (
    echo [90m  - Aseprite already removed[0m
)
echo.

REM Step 2: Build plugin
echo [2/4] Building Paper2D plugin...
echo [93m  Running BuildPlugin command...[0m
echo.
cd /d "E:\Unreal Engine\UE_5.6\Engine\Build\BatchFiles"
call RunUAT.bat BuildPlugin -plugin="%PLUGIN_PATH%" -package="%OUTPUT_PATH%"
set BUILD_RESULT=%ERRORLEVEL%
echo.

if %BUILD_RESULT% EQU 0 (
    echo [92m  √ Build completed successfully![0m
) else (
    echo [91m  × Build failed with error code %BUILD_RESULT%[0m
    goto RESTORE_PLUGINS
)
echo.

REM Step 3: Copy to engine
echo [3/4] Copying built plugin to engine...
if exist "%OUTPUT_PATH%\HostProject\Plugins\Paper2D" (
    xcopy "%OUTPUT_PATH%\HostProject\Plugins\Paper2D\*" "%ENGINE_PLUGIN_DIR%\" /E /I /Y >nul 2>&1
    echo [92m  √ Plugin copied to: %ENGINE_PLUGIN_DIR%[0m
) else (
    echo [91m  × Built plugin not found at expected location[0m
)
echo.

REM Step 4: Restore marketplace plugins
:RESTORE_PLUGINS
echo [4/4] Restoring marketplace plugins...
if exist "%BACKUP_DIR%\PaperZD8b0e064aa89dV19" (
    move "%BACKUP_DIR%\PaperZD8b0e064aa89dV19" "%MARKETPLACE_DIR%\" >nul 2>&1
    echo [92m  √ Restored PaperZD[0m
)

if exist "%BACKUP_DIR%\Asepritec187d063b6d7V4" (
    move "%BACKUP_DIR%\Asepritec187d063b6d7V4" "%MARKETPLACE_DIR%\" >nul 2>&1
    echo [92m  √ Restored Aseprite[0m
)
echo.

echo ================================================
if %BUILD_RESULT% EQU 0 (
    echo [92m  REBUILD COMPLETE![0m
) else (
    echo [91m  REBUILD FAILED - See errors above[0m
)
echo ================================================
echo.

pause
