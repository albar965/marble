


if defined APROJECTS ( echo %APROJECTS% ) else ( echo APROJECTS not set && exit /b 1 )
if defined DEPLOYDIR ( echo %DEPLOYDIR% ) else ( echo DEPLOYDIR not set && exit /b 1 )
if defined BUILDDIR ( echo %BUILDDIR% ) else ( echo BUILDDIR not set && exit /b 1 )

rmdir /s/q "%DEPLOYDIR%"
mkdir "%DEPLOYDIR%"

rmdir /s/q "%BUILDDIR%"
mkdir "%BUILDDIR%"

pushd "%BUILDDIR%"
IF ERRORLEVEL 1 goto :err

cmake -Wno-dev -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=%BUILDTYPE% -DSTATIC_BUILD=TRUE -DQTONLY=TRUE -DBUILD_MARBLE_EXAMPLES=NO -DBUILD_INHIBIT_SCREENSAVER_PLUGIN=NO -DBUILD_MARBLE_APPS=NO -DBUILD_MARBLE_EXAMPLES=NO -DBUILD_MARBLE_TESTS=NO -DBUILD_MARBLE_TOOLS=NO -DBUILD_TESTING=NO -DBUILD_WITH_DBUS=NO -DMARBLE_EMPTY_MAPTHEME=YES -DMOBILE=NO -DWITH_DESIGNER_PLUGIN=NO -DWITH_Phonon=NO -DWITH_Qt5Location=NO -DWITH_Qt5Positioning=NO -DWITH_Qt5SerialPort=NO -DWITH_ZLIB=NO -DWITH_libgps=NO -DWITH_libshp=NO -DWITH_libwlocate=NO -DCMAKE_INSTALL_PREFIX=%DEPLOYDIR% ..\marble\
IF ERRORLEVEL 1 goto :err

mingw32-make -j4
IF ERRORLEVEL 1 goto :err

mingw32-make install
IF ERRORLEVEL 1 goto :err

rem Copy all headers into the C:\Projekte\marble-release\include\marble|astro dir flat. Also from build-marble-release\src\lib\astro|marble.

mkdir %DEPLOYDIR%\include\astro
xcopy /I /F /Y %BUILDDIR%\src\lib\astro\astrolib_export.h %DEPLOYDIR%\include\astro
xcopy /I /F /Y %%APROJECTS%\marble\src\lib\astro\*.h %DEPLOYDIR%\include\astro

mkdir %DEPLOYDIR%\include\marble
xcopy /I /F /Y %BUILDDIR%\src\lib\marble\marble_export.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\*\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\blendings\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\cloudsync\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\declarative\*.h %DEPLOYDIR%\include\marble

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\data\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\graphicsitem\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\handlers\kml\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\handlers\dgml\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\parser\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\scene\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writer\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writers\kml\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writers\dgml\*.h %DEPLOYDIR%\include\marble

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\graphicsview\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\htmlfeatures\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\layers\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\osm\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\projections\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\routing\*.h %DEPLOYDIR%\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\webpopup\*.h %DEPLOYDIR%\include\marble

popd

echo ---- Success ----

if not "%1" == "nopause" pause

exit /b 0

:err

echo **** ERROR ****

popd

pause

exit /b 1
