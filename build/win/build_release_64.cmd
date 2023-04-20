if defined APROJECTS ( echo %APROJECTS% ) else ( echo APROJECTS not set && exit /b 1 )

set BUILDDIR=%APROJECTS%\build-marble-release
set DEPLOYDIR=%APROJECTS%\marble-release-win64
set PATH=%PATH%;C:\Qt\5.15.2\mingw81_64\bin\;C:\Qt\Tools\mingw810_64\bin
set BUILDTYPE=Release

call build_base.cmd nopause
IF ERRORLEVEL 1 goto :err

echo ---- Success ----

if not "%1" == "nopause" pause

exit /b 0

:err

echo **** ERROR ****

popd

pause

exit /b 1