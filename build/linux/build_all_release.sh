#!/bin/bash

# Echo all commands and exit on failure
set -e
set -x

BUILDTYPE=release
export QT_PATH=${QT_PATH:-"$HOME/Qt"}
export QT_PREFIX_PATH="${QT_PATH}/${QT_VERSION}/gcc_64"

echo QT_PREFIX_PATH: ${QT_PREFIX_PATH}

mkdir -p $APROJECTS/build-marble-${BUILDTYPE}
rm -rf $APROJECTS/build-marble-${BUILDTYPE}/* $APROJECTS/build-marble-${BUILDTYPE}/.cmake

mkdir -p $APROJECTS/Marble-${BUILDTYPE}
rm -rf $APROJECTS/Marble-${BUILDTYPE}/*

cd $APROJECTS/build-marble-${BUILDTYPE}

cmake -DCMAKE_BUILD_TYPE=${BUILDTYPE} -DCMAKE_INSTALL_PREFIX=$APROJECTS/Marble-${BUILDTYPE} -DEXEC_INSTALL_PREFIX=$APROJECTS/Marble-${BUILDTYPE} -DCMAKE_PREFIX_PATH=${QT_PREFIX_PATH}/ ../marble/

nice make

make install
