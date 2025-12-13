#!/bin/bash

set -e

export CONF_TYPE=release
export CONF_BUILD_TYPE=Release
export QT_PATH=${QT_PATH:-"$HOME/Qt"}
export QT_PREFIX_PATH="${QT_PATH}/6.5.3/clang_64"

rm -rf ${APROJECTS}/build-marble-${CONF_TYPE}
mkdir -p ${APROJECTS}/build-marble-${CONF_TYPE}

(
  cd ${APROJECTS}/build-marble-${CONF_TYPE}
  ${QT_PATH}/Tools/CMake/CMake.app/Contents/bin/cmake -DCMAKE_BUILD_TYPE=${CONF_BUILD_TYPE} -DCMAKE_PREFIX_PATH=${QT_PREFIX_PATH} -DCMAKE_INSTALL_PREFIX=${APROJECTS}/Marble-${CONF_TYPE} -DEXEC_INSTALL_PREFIX=${APROJECTS}/Marble-${CONF_TYPE} ../marble/
  make -j4
  make install
)

bash copy_lib_mac_${CONF_TYPE}.sh
