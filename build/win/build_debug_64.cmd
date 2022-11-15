set BUILDDIR=%APROJECTS%\build-marble-debug
set DEPLOYDIR=%APROJECTS%\marble-debug-win64
set PATH=%PATH%;C:\Qt\5.15.2\mingw81_64\bin\;C:\Qt\Tools\mingw810_64\bin
set BUILDTYPE=Debug

call build_base.cmd nopause

pause
