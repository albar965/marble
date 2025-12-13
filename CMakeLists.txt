cmake_minimum_required(VERSION 3.5)

project(marble)

####################################################
# CMake Settings

add_compile_definitions(QT_DISABLE_DEPRECATED_UP_TO=0x050F00)

add_compile_options(-Wno-deprecated-copy -Wno-deprecated-declarations, -Wno-unknown-warning-option)

# add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x050F00)

SET(CMAKE_COLOR_MAKEFILE ON)

if( WIN32 )
  SET(CMAKE_COLOR_MAKEFILE OFF)
  SET(CMAKE_COLOR_DIAGNOSTICS OFF)
  add_compile_options(-fdiagnostics-color=never)
endif()

# SET(CMAKE_SKIP_RPATH ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Let CMake find the correct library dir instead of
# relying on the obsolete LIB_SUFFIX parameter
include(GNUInstallDirs)

# Taken from KDECompilerSettings.cmake:
# Pick sensible versions of the C and C++ standards.
# Note that MSVC does not have equivalent flags; the features are either
# supported or they are not.
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
    # We use the C89 standard because that is what is common to all our
    # compilers (in particular, MSVC 2010 does not support C99)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -std=iso9899:1990")
endif()
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel" AND NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()
# Default to hidden visibility for symbols
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
if (POLICY CMP0063)
    cmake_policy(SET CMP0063 NEW)
endif()

####################################################
# Where to look first for cmake modules,
# before ${CMAKE_ROOT}/Modules/ is checked
set ( CMAKE_MODULE_PATH
     ${CMAKE_SOURCE_DIR}/cmake/modules
     ${CMAKE_CURRENT_SOURCE_DIR}
     ${CMAKE_CURRENT_SOURCE_DIR}/src
     ${CMAKE_CURRENT_SOURCE_DIR}/cmake_find_rules
     ${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts
     ${CMAKE_MODULE_PATH}
     )

# add cmake macros
include(GenerateExportHeader)
include( MarbleMacros )

#######################################################
# Specific options for building for different platforms

if(CMAKE_SYSTEM_NAME STREQUAL Android)
   add_definitions(-DANDROID)
endif()


#######################################################
# Find Qt dependencies

# Minimum Qt version
set(REQUIRED_QT_VERSION 5.3.0)

if(CMAKE_SYSTEM_NAME STREQUAL Android)
   # TODO: still needed with ECM toolchain?
   SET(QT_QMAKE_EXECUTABLE "$ENV{Qt6_android}/bin/qmake")
endif()

find_package(Qt6Core ${REQUIRED_QT_VERSION} REQUIRED)
find_package(Qt6Xml ${REQUIRED_QT_VERSION} REQUIRED)
find_package(Qt6Network ${REQUIRED_QT_VERSION} REQUIRED)
find_package(Qt6Widgets ${REQUIRED_QT_VERSION} REQUIRED)
find_package(Qt6Svg ${REQUIRED_QT_VERSION} REQUIRED)
find_package(Qt6Sql ${REQUIRED_QT_VERSION} REQUIRED)
find_package(Qt6Concurrent ${REQUIRED_QT_VERSION} REQUIRED)

SET(CMAKE_AUTOMOC TRUE)

# Use M_PI under Windows
if( WIN32 )
    add_definitions( -D_USE_MATH_DEFINES )
endif( WIN32 )

set(EXEC_INSTALL_PREFIX  ${CMAKE_INSTALL_PREFIX} CACHE PATH  "Base directory for executables and libraries" FORCE)
if (NOT QT_PLUGINS_DIR)
   set(QT_PLUGINS_DIR ${CMAKE_INSTALL_LIBDIR}/plugins)
endif()

####################################################
# Detect default for the user configurable MARBLE_DATA_PATH option

if(WIN32)
    set(data_dir data)
    set(plugin_dir plugins)
elseif(APPLE)
#    set(CMAKE_OSX_DEPLOYMENT_TARGET 10.13)
    # needed for finding bundle path in e.g. katlasdir.h
    FIND_LIBRARY(APP_SERVICES_LIBRARY ApplicationServices )
    MARK_AS_ADVANCED (APP_SERVICES_LIBRARY)
    SET(MAC_EXTRA_LIBS ${APP_SERVICES_LIBRARY})
      # for Mac OS X, everything is put inside an application bundle
      SET (CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/)
      # path for library references
      SET (CMAKE_INSTALL_NAME_DIR @executable_path/lib)
      # install the Info.plist file
      install(FILES src/mac/Info.plist DESTINATION ${CMAKE_INSTALL_PREFIX}/Marble.app/Contents)
      #SET (lib_dir ${CMAKE_INSTALL_PREFIX}/Marble.app/Contents/MacOS/lib)
      SET (data_dir   ${CMAKE_INSTALL_PREFIX}/Marble.app/Contents/MacOS/resources/data)
      SET (plugin_dir   ${CMAKE_INSTALL_PREFIX}/Marble.app/Contents/MacOS/resources/plugins)
elseif(CMAKE_SYSTEM_NAME STREQUAL Android)
      set(plugin_dir "${CMAKE_INSTALL_PREFIX}/assets/plugins")
      set(data_dir "${CMAKE_INSTALL_PREFIX}/assets/data")
else() # Linux / bsd etc...
      set(data_dir ${CMAKE_INSTALL_FULL_DATAROOTDIR}/marble/data)
      set(plugin_dir ${CMAKE_INSTALL_FULL_LIBDIR}/marble/plugins)
endif()

if(NOT ICON_INSTALL_DIR)
  set(ICON_INSTALL_DIR ${CMAKE_INSTALL_FULL_DATAROOTDIR}/icons)
endif(NOT ICON_INSTALL_DIR)

if(NOT INCLUDE_INSTALL_DIR)
    set(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include")
endif()

if (NOT MARBLE_DATA_PATH)
  set (MARBLE_DATA_PATH ${data_dir})
endif (NOT MARBLE_DATA_PATH)

if (NOT MARBLE_PLUGIN_PATH)
  set (MARBLE_PLUGIN_PATH ${plugin_dir})
endif (NOT MARBLE_PLUGIN_PATH)

if (NOT MARBLE_DATA_INSTALL_PATH)
  set (MARBLE_DATA_INSTALL_PATH ${MARBLE_DATA_PATH})
endif (NOT MARBLE_DATA_INSTALL_PATH)

if (NOT MARBLE_PLUGIN_INSTALL_PATH)
  set (MARBLE_PLUGIN_INSTALL_PATH ${MARBLE_PLUGIN_PATH})
endif (NOT MARBLE_PLUGIN_INSTALL_PATH)

#MESSAGE( STATUS, "MARBLE_PLUGIN_INSTALL_PATH: ${MARBLE_PLUGIN_INSTALL_PATH}" )

if(WIN32)
  set (STATIC_BUILD FALSE CACHE BOOL "Link to static Qt libs (win32 only)?")
endif(WIN32)

add_definitions(
    -DQT_USE_FAST_CONCATENATION
    -DQT_USE_FAST_OPERATOR_PLUS
    -DQT_NO_SIGNALS_SLOTS_KEYWORDS
    -DQT_NO_URL_CAST_FROM_STRING
)

####################################################
# Options for static build
if(STATIC_BUILD)
  add_definitions(-DSTATIC_BUILD=1)
endif(STATIC_BUILD)

#############################################################
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_C_COMPILER MATCHES "icc")
    # Its good programming practice to build with no warnings...
    add_definitions( -Wall -Wextra -Wundef -Wnon-virtual-dtor -Woverloaded-virtual -Wno-long-long
                     -Wchar-subscripts -Wcast-align -Wpointer-arith -Wformat-security )

endif (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_C_COMPILER MATCHES "icc")

#############################################################
# Add a compiler def so that we can conditionally compile
# code in debug mode only (e.g. extra console messages)
IF (CMAKE_BUILD_TYPE MATCHES Debug)
    IF(NOT MINGW)
        ADD_DEFINITIONS(-DDEBUG)
    ELSE(NOT MINGW)
        REMOVE_DEFINITIONS( -DQT_NO_DEBUG )
    ENDIF(NOT MINGW)
ENDIF (CMAKE_BUILD_TYPE MATCHES Debug)

####################################################
# on Win32 set the debug postfix
if(WIN32)
  # distinguish between debug and release plugin
  SET(CMAKE_DEBUG_POSTFIX "d")
endif(WIN32)
####################################################


####################################################
# Add the include directories

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/astro
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/projections
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/geodata
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/geodata/data
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/geodata/graphicsitem
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/geodata/handlers/dgml
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/geodata/parser
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/geodata/writer
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/geodata/scene
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/marble/graphicsview
  ${CMAKE_CURRENT_BINARY_DIR}/src
  ${CMAKE_CURRENT_BINARY_DIR}/src/lib/marble
)
####################################################
# Descend into subdirectories
add_subdirectory(doc)
add_subdirectory(src)
add_subdirectory(data)

include(DistTarget)

####################################################
# Install extra files
install(FILES LICENSE.txt DESTINATION ${MARBLE_DATA_INSTALL_PATH})

############################################################
# Uninstall stuff
CONFIGURE_FILE(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/templates/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
    "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

include(MarbleCPackOptions)

marble_feature_summary(WHAT ALL)
