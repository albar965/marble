set BUILDDIR=%APROJECTS%\build-marble-release
set DEPLOYDIR=%APROJECTS%\marble-release-win64
set PATH=%PATH%;C:\Qt\5.15.2\mingw81_64\bin\;C:\Qt\Tools\mingw810_64\bin
set BUILDTYPE=Release

call build_base.cmd nopause

pause
