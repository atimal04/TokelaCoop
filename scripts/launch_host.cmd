@echo off
REM Launch Kenshi as the co-op HOST (authoritative). Listens on UDP 27800.
REM The plugin reads TOKELACOOP_MODE/IP/PORT from the environment at startup.
REM Install dir: scripts\_kenshi_dirs.cmd (override via TOKELACOOP_KENSHI_DIR).
call "%~dp0_kenshi_dirs.cmd"
set "KENSHI_DIR=%TOKELACOOP_KENSHI_DIR%"

set TOKELACOOP_MODE=host
set TOKELACOOP_PORT=27800

REM Optional: auto-load a save by name on launch (skips the menu). Leave blank to
REM pick a save manually. For co-op, set the SAME name here and in launch_join.cmd
REM (after running sync_save.cmd so both installs have that save).
REM IMPORTANT: this must be an EXISTING save FOLDER name under
REM   %LOCALAPPDATA%\kenshi\save\<name>   (e.g. "c", not "current").
REM Auto-loading a save that doesn't exist will crash the game.
set "TOKELACOOP_SAVE="

cd /d "%KENSHI_DIR%"
echo Launching Kenshi as HOST on port %TOKELACOOP_PORT% ...
if defined TOKELACOOP_SAVE if not "%TOKELACOOP_SAVE%"=="" echo   auto-loading save: %TOKELACOOP_SAVE%
start "" "%KENSHI_DIR%\kenshi_x64.exe"
