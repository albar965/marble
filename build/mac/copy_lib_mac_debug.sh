#!/bin/bash

# This script replaces the broken deploy step in the Marble build
# Run it to copy all required files to $APROJECTS/Marble-debug

mkdir ~/Programme/Marble-debug/include
mkdir ~/Programme/Marble-debug/include/astro
mkdir ~/Programme/Marble-debug/include/marble

mkdir ~/Programme/Marble-debug/lib
mkdir ~/Programme/Marble-debug/lib/plugins


for i in `find  ~/Projekte/marble/src/lib/astro -name *.h` ; do cp -av $i ~/Programme/Marble-debug/include/astro ;done

for i in `find  ~/Projekte/build-marble-debug/src/lib/astro -name *.h` ; do cp -av $i ~/Programme/Marble-debug/include/astro ;done

for i in `find  ~/Projekte/marble/src/lib/marble -name *.h` ; do cp -v $i ~/Programme/Marble-debug/include/marble ;done

for i in `find  ~/Projekte/build-marble-debug/src/lib/marble -name *.h` ; do cp -av $i ~/Programme/Marble-debug/include/marble ;done

for i in `find  ~/Projekte/build-marble-debug/src/plugins -name *.so` ; do cp -av $i ~/Programme/Marble-debug/lib/plugins/ ;done


for i in `find  ~/Projekte/build-marble-debug/src/lib/marble -name *.dylib` ; do cp -av $i ~/Programme/Marble-debug/lib/ ;done

