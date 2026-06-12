@echo off

setlocal enableextensions

if defined APROJECTS ( echo %APROJECTS% ) else ( echo APROJECTS not set && exit /b 1 )
if defined DEPLOYDIR ( echo %DEPLOYDIR% ) else ( echo DEPLOYDIR not set && exit /b 1 )
if defined BUILDDIR ( echo %BUILDDIR% ) else ( echo BUILDDIR not set && exit /b 1 )
if defined BUILDTYPE ( echo %BUILDTYPE% ) else ( echo BUILDTYPE not set && exit /b 1 )

pushd %APROJECTS%\marble

git pull

popd

rmdir /s/q "%DEPLOYDIR%"
mkdir "%DEPLOYDIR%"

rmdir /s/q "%BUILDDIR%"
mkdir "%BUILDDIR%"

pushd "%BUILDDIR%"
IF ERRORLEVEL 1 goto :err

cmake -Wno-dev -G "MinGW Makefiles" -DWITH_ZLIB=NO -DCMAKE_BUILD_TYPE=%BUILDTYPE% -DCMAKE_INSTALL_PREFIX=%DEPLOYDIR% ..\marble\
IF ERRORLEVEL 1 goto :err

cmake --build .
IF ERRORLEVEL 1 goto :err

cmake --install .
IF ERRORLEVEL 1 goto :err

mkdir %DEPLOYDIR%\translations
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %BUILDDIR%\translations\*.qm %DEPLOYDIR%\translations
IF ERRORLEVEL 1 goto :err

mkdir %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %BUILDDIR%\src\lib\marble\marble_export.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\blendings\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\data\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\graphicsitem\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\handlers\kml\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\handlers\dgml\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\parser\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\scene\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writer\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writers\kml\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writers\dgml\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\graphicsview\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\layers\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\projections\*.h %DEPLOYDIR%\include\marble
IF ERRORLEVEL 1 goto :err

popd

echo ---- Success ----

if not "%1" == "nopause" pause

exit /b 0

:err

echo **** ERROR ****

popd

pause

exit /b 1
