#!/bin/bash

set -e

export CONF_TYPE=release
export CONF_BUILD_TYPE=Release
export QT_PATH=${QT_PATH:-"$HOME/Qt"}
export QT_PREFIX_PATH="${QT_PATH}/$QT_VERSION/macos"

rm -rf ${APROJECTS}/build-marble-${CONF_TYPE}
mkdir -p ${APROJECTS}/build-marble-${CONF_TYPE}

rm -rf ${APROJECTS}/Marble-${CONF_TYPE}
mkdir -p ${APROJECTS}/Marble-${CONF_TYPE}

(
  cd ${APROJECTS}/build-marble-${CONF_TYPE}
  ${QT_PATH}/Tools/CMake/CMake.app/Contents/bin/cmake -DCMAKE_BUILD_TYPE=${CONF_BUILD_TYPE} -DCMAKE_PREFIX_PATH=${QT_PREFIX_PATH} -DCMAKE_INSTALL_PREFIX=${APROJECTS}/Marble-${CONF_TYPE} -DEXEC_INSTALL_PREFIX=${APROJECTS}/Marble-${CONF_TYPE} ../marble/
  ${QT_PATH}/Tools/CMake/CMake.app/Contents/bin/cmake --build .
  ${QT_PATH}/Tools/CMake/CMake.app/Contents/bin/cmake --install .
)

bash copy_lib_mac_${CONF_TYPE}.sh

rm -rf ${APROJECTS}/Marble-${CONF_TYPE}/Marble.app
