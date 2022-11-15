#!/bin/bash

# This script replaces the broken deploy step in the Marble build
# Run it to copy all required files to $APROJECTS/Marble-debug

mkdir $APROJECTS/Marble-debug/include
mkdir $APROJECTS/Marble-debug/include/astro
mkdir $APROJECTS/Marble-debug/include/marble

mkdir $APROJECTS/Marble-debug/lib
mkdir $APROJECTS/Marble-debug/lib/plugins


for i in `find $APROJECTS/marble/src/lib/astro -name *.h` ; do cp -av $i $APROJECTS/Marble-debug/include/astro ;done

for i in `find $APROJECTS/build-marble-release/src/lib/astro -name *.h` ; do cp -av $i $APROJECTS/Marble-debug/include/astro ;done

for i in `find $APROJECTS/marble/src/lib/marble -name *.h` ; do cp -v $i $APROJECTS/Marble-debug/include/marble ;done

for i in `find $APROJECTS/build-marble-debug/src/lib/marble -name *.h` ; do cp -av $i $APROJECTS/Marble-debug/include/marble ;done

for i in `find $APROJECTS/build-marble-debug/src/plugins -name *.so` ; do cp -av $i $APROJECTS/Marble-debug/lib/plugins/ ;done


for i in `find $APROJECTS/build-marble-debug/src/lib/marble -name *.dylib` ; do cp -av $i $APROJECTS/Marble-debug/lib/ ;done

