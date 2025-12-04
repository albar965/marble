#!/bin/bash

BUILDTYPE=debug

mkdir -p $APROJECTS/build-marble-${BUILDTYPE}
rm -rf $APROJECTS/build-marble-${BUILDTYPE}/* $APROJECTS/build-marble-${BUILDTYPE}/.cmake

mkdir -p $APROJECTS/Marble-${BUILDTYPE}
rm -rf $APROJECTS/Marble-${BUILDTYPE}/*

cd $APROJECTS/build-marble-${BUILDTYPE}

cmake -DCMAKE_BUILD_TYPE=${BUILDTYPE} -DCMAKE_INSTALL_PREFIX=$APROJECTS/Marble-${BUILDTYPE} -DEXEC_INSTALL_PREFIX=$APROJECTS/Marble-${BUILDTYPE} -DCMAKE_PREFIX_PATH=~/Qt/5.15.2/gcc_64/ ../marble/

make -j8

make install
