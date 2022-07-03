#!/bin/bash

# This script replaces the broken deploy step in the Marble build
# Run it to copy all required files to $APROJECTS/Marble-release

mkdir $APROJECTS/Marble-release/include
mkdir $APROJECTS/Marble-release/include/astro
mkdir $APROJECTS/Marble-release/include/marble

mkdir $APROJECTS/Marble-release/lib
mkdir $APROJECTS/Marble-release/lib/plugins


for i in `find $APROJECTS/marble/src/lib/astro -name *.h` ; do cp -av $i $APROJECTS/Marble-release/include/astro ;done

for i in `find $APROJECTS/build-marble-release/src/lib/astro -name *.h` ; do cp -av $i $APROJECTS/Marble-release/include/astro ;done

for i in `find $APROJECTS/marble/src/lib/marble -name *.h` ; do cp -v $i $APROJECTS/Marble-release/include/marble ;done

for i in `find $APROJECTS/build-marble-release/src/lib/marble -name *.h` ; do cp -av $i $APROJECTS/Marble-release/include/marble ;done

for i in `find $APROJECTS/build-marble-release/src/plugins -name *.so` ; do cp -av $i $APROJECTS/Marble-release/lib/plugins/ ;done


for i in `find $APROJECTS/build-marble-release/src/lib/marble -name *.dylib` ; do cp -av $i $APROJECTS/Marble-release/lib/ ;done

