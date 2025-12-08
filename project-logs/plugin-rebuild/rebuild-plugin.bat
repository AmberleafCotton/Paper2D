@echo off
REM ============================================
REM Universal Plugin Rebuild Script
REM ============================================
setlocal enabledelayedexpansion

echo.
echo ================================================
echo  UNIVERSAL PLUGIN REBUILD TOOL
echo ================================================
echo.

REM Get plugin path
set /p PLUGIN_PATH="Enter full path to .uplugin file: "
if not exist "%PLUGIN_PATH%" (
    echo [91m× Plugin file not found: %PLUGIN_PATH%[0m
    pause
    exit /b 1
)
echo [92m√ Plugin found[0m
echo.

REM Get output path
set /p OUTPUT_PATH="Enter output directory (e.g., C:\Temp\PluginBuild): "
echo [92m√ Output path set: %OUTPUT_PATH%[0m
echo.

REM Get engine plugin destination
set /p ENGINE_PLUGIN_DIR="Enter engine plugin destination (e.g., E:\UE_5.6\Engine\Plugins\YourPlugin): "
echo [92m√ Destination set[0m
echo.

REM Ask about marketplace plugins
echo.
echo [93mDo you need to temporarily remove marketplace plugins?[0m
echo If build fails with "Module validation" errors, you'll need to.
echo.
set /p REMOVE_MARKETPLACE="Remove marketplace plugins? (y/n): "

if /i "%REMOVE_MARKETPLACE%"=="y" (
    echo.
    echo [93mEnter marketplace plugin folder names to remove (one per line, empty to finish):[0m
    set PLUGIN_COUNT=0
    
    :GET_PLUGIN
    set /p MARKETPLACE_PLUGIN="Plugin %PLUGIN_COUNT%: "
    if "%MARKETPLACE_PLUGIN%"=="" goto BUILD_START
    
    set MARKETPLACE_PLUGINS[!PLUGIN_COUNT!]=%MARKETPLACE_PLUGIN%
    set /a PLUGIN_COUNT+=1
    goto GET_PLUGIN
)

:BUILD_START
echo.
echo ================================================
echo  STARTING BUILD PROCESS
echo ================================================
echo.

REM Backup marketplace plugins if needed
if /i "%REMOVE_MARKETPLACE%"=="y" (
    echo [1/4] Backing up marketplace plugins...
    set BACKUP_DIR=C:\Users\AmberleafCotton\Desktop\PluginBackup
    if not exist "!BACKUP_DIR!" mkdir "!BACKUP_DIR!"
    
    set INDEX=0
    :BACKUP_LOOP
    if defined MARKETPLACE_PLUGINS[!INDEX!] (
        set MARKETPLACE_DIR=E:\Unreal Engine\UE_5.6\Engine\Plugins\Marketplace\!MARKETPLACE_PLUGINS[%INDEX%]!
        if exist "!MARKETPLACE_DIR!" (
            move "!MARKETPLACE_DIR!" "!BACKUP_DIR!\" >nul 2>&1
            echo [92m  √ Backed up: !MARKETPLACE_PLUGINS[%INDEX%]![0m
        )
        set /a INDEX+=1
        goto BACKUP_LOOP
    )
    echo.
)

REM Build plugin
echo [2/4] Building plugin...
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
)
echo.

REM Extract plugin name from path
for %%F in ("%PLUGIN_PATH%") do set PLUGIN_NAME=%%~nF

REM Copy to engine
echo [3/4] Copying built plugin to engine...
if exist "%OUTPUT_PATH%\HostProject\Plugins\%PLUGIN_NAME%" (
    xcopy "%OUTPUT_PATH%\HostProject\Plugins\%PLUGIN_NAME%\*" "%ENGINE_PLUGIN_DIR%\" /E /I /Y >nul 2>&1
    echo [92m  √ Plugin copied to: %ENGINE_PLUGIN_DIR%[0m
) else (
    echo [91m  × Built plugin not found at: %OUTPUT_PATH%\HostProject\Plugins\%PLUGIN_NAME%[0m
)
echo.

REM Restore marketplace plugins
if /i "%REMOVE_MARKETPLACE%"=="y" (
    echo [4/4] Restoring marketplace plugins...
    set INDEX=0
    :RESTORE_LOOP
    if defined MARKETPLACE_PLUGINS[!INDEX!] (
        if exist "!BACKUP_DIR!\!MARKETPLACE_PLUGINS[%INDEX%]!" (
            move "!BACKUP_DIR!\!MARKETPLACE_PLUGINS[%INDEX%]!" "E:\Unreal Engine\UE_5.6\Engine\Plugins\Marketplace\" >nul 2>&1
            echo [92m  √ Restored: !MARKETPLACE_PLUGINS[%INDEX%]![0m
        )
        set /a INDEX+=1
        goto RESTORE_LOOP
    )
    echo.
)

echo ================================================
if %BUILD_RESULT% EQU 0 (
    echo [92m  REBUILD COMPLETE![0m
) else (
    echo [91m  REBUILD FAILED - See errors above[0m
)
echo ================================================
echo.

pause
