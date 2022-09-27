mkdir %APROJECTS%\build-marble-debug

cd %APROJECTS%\build-marble-debug

set PATH=%PATH%;C:\Qt\5.15.2\mingw81_32\bin;C:\Qt\Tools\mingw810_32\bin

cmake -Wno-dev -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug -DSTATIC_BUILD=TRUE -DQTONLY=TRUE -DBUILD_MARBLE_EXAMPLES=NO -DBUILD_INHIBIT_SCREENSAVER_PLUGIN=NO -DBUILD_MARBLE_APPS=NO -DBUILD_MARBLE_EXAMPLES=NO -DBUILD_MARBLE_TESTS=NO -DBUILD_MARBLE_TOOLS=NO -DBUILD_TESTING=NO -DBUILD_WITH_DBUS=NO -DMARBLE_EMPTY_MAPTHEME=YES -DMOBILE=NO -DWITH_DESIGNER_PLUGIN=NO -DWITH_Phonon=NO -DWITH_Qt5Location=NO -DWITH_Qt5Positioning=NO -DWITH_Qt5SerialPort=NO -DWITH_ZLIB=NO -DWITH_libgps=NO -DWITH_libshp=NO -DWITH_libwlocate=NO -DCMAKE_INSTALL_PREFIX=%APROJECTS%\Marble-debug ..\marble\

mingw32-make -j4

mingw32-make install

rem Copy all headers into the C:\Projekte\marble-debug\include\marble|astro dir flat. Also from build-marble-debug\src\lib\astro|marble.

mkdir %APROJECTS%\Marble-debug\include\astro
xcopy /I /F /Y %APROJECTS%\build-marble-debug\src\lib\astro\astrolib_export.h %APROJECTS%\Marble-debug\include\astro
xcopy /I /F /Y %%APROJECTS%\marble\src\lib\astro\*.h %APROJECTS%\Marble-debug\include\astro

mkdir %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\build-marble-debug\src\lib\marble\marble_export.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\*\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\blendings\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\cloudsync\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\declarative\*.h %APROJECTS%\Marble-debug\include\marble

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\data\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\graphicsitem\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\handlers\kml\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\handlers\dgml\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\parser\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\scene\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writer\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writers\kml\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\geodata\writers\dgml\*.h %APROJECTS%\Marble-debug\include\marble

xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\graphicsview\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\htmlfeatures\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\layers\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\osm\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\projections\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\routing\*.h %APROJECTS%\Marble-debug\include\marble
xcopy /I /F /Y %APROJECTS%\marble\src\lib\marble\webpopup\*.h %APROJECTS%\Marble-debug\include\marble

pause