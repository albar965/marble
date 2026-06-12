#!/bin/bash

# This script replaces the broken deploy step in the Marble build
# Run it to copy all required files to $APROJECTS/Marble-release

BUILD_TYPE=debug

mkdir $APROJECTS/Marble-${BUILD_TYPE}/translations

mkdir $APROJECTS/Marble-${BUILD_TYPE}/include
mkdir $APROJECTS/Marble-${BUILD_TYPE}/include/marble

mkdir $APROJECTS/Marble-${BUILD_TYPE}/lib
mkdir $APROJECTS/Marble-${BUILD_TYPE}/lib/plugins

cp -av $APROJECTS/marble/translations/*.qm $APROJECTS/Marble-${BUILD_TYPE}/translations

for i in `find $APROJECTS/marble/src/lib/marble -name *.h` ; do cp -v $i $APROJECTS/Marble-${BUILD_TYPE}/include/marble ;done

for i in `find $APROJECTS/build-marble-${BUILD_TYPE}/src/lib/marble -name *.h` ; do cp -av $i $APROJECTS/Marble-${BUILD_TYPE}/include/marble ;done

for i in `find $APROJECTS/build-marble-${BUILD_TYPE}/src/plugins -name *.so` ; do cp -av $i $APROJECTS/Marble-${BUILD_TYPE}/lib/plugins/ ;done


for i in `find $APROJECTS/build-marble-${BUILD_TYPE}/src/lib/marble -name *.dylib` ; do cp -av $i $APROJECTS/Marble-${BUILD_TYPE}/lib/ ;done

