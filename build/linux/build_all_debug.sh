#!/bin/bash

mkdir -p $APROJECTS/build-marble-debug

cd $APROJECTS/build-marble-debug

cmake -DCMAKE_BUILD_TYPE=Debug -DSTATIC_BUILD=TRUE -DQTONLY=TRUE -DBUILD_MARBLE_EXAMPLES=NO -DBUILD_INHIBIT_SCREENSAVER_PLUGIN=NO -DBUILD_MARBLE_APPS=NO -DBUILD_MARBLE_EXAMPLES=NO -DBUILD_MARBLE_TESTS=NO -DBUILD_MARBLE_TOOLS=NO -DBUILD_TESTING=NO -DBUILD_WITH_DBUS=NO -DMARBLE_EMPTY_MAPTHEME=YES -DMOBILE=NO -DWITH_DESIGNER_PLUGIN=NO -DWITH_Phonon=NO -DWITH_Qt5Location=NO -DWITH_Qt5Positioning=NO -DWITH_Qt5SerialPort=NO -DWITH_ZLIB=NO -DWITH_libgps=NO -DWITH_libshp=NO -DWITH_libwlocate=NO -DCMAKE_INSTALL_PREFIX=$APROJECTS/Marble-debug -DEXEC_INSTALL_PREFIX=$APROJECTS/Marble-debug -DCMAKE_PREFIX_PATH=~/Qt/5.15.2/gcc_64/ ../marble/

make -j8

make install
