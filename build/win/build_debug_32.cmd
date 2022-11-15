set BUILDDIR=%APROJECTS%\build-marble-debug
set DEPLOYDIR=%APROJECTS%\marble-debug-win32
set PATH=%PATH%;C:\Qt\5.15.2\mingw81_32\bin;C:\Qt\Tools\mingw810_32\bin
set BUILDTYPE=Debug

call build_base.cmd nopause

pause
