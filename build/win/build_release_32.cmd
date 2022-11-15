set BUILDDIR=%APROJECTS%\build-marble-release
set DEPLOYDIR=%APROJECTS%\marble-release-win32
set PATH=%PATH%;C:\Qt\5.15.2\mingw81_32\bin;C:\Qt\Tools\mingw810_32\bin
set BUILDTYPE=Release

call build_base.cmd nopause

pause
