# before add_subdirectory() !
if(MSVC)
  add_definitions(-D_USE_MATH_DEFINES=1)
endif(MSVC)

if(NOT MARBLE_NO_DBUS)
  add_definitions(-DMARBLE_DBUS)
endif()


macro_optional_find_package(ZLIB QUIET)
marble_set_package_properties(ZLIB PROPERTIES DESCRIPTION "general-purpose lossless data-compression library")
marble_set_package_properties(ZLIB PROPERTIES URL "http://www.zlib.net/")
marble_set_package_properties(ZLIB PROPERTIES TYPE OPTIONAL PURPOSE "When found, system zlib is used. When not found, a Marble internal zlib is used.")
if(NOT ZLIB_FOUND)
  add_subdirectory( 3rdparty/zlib )
  set(ZLIB_LIBRARIES zlibstatic)
  set(ZLIB_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/zlib" "${CMAKE_CURRENT_BINARY_DIR}/3rdparty/zlib")
endif()

add_subdirectory( 3rdparty/sgp4 )
add_subdirectory( lib/marble )
add_subdirectory( lib/astro )

add_subdirectory( plugins )

option(BUILD_MARBLE_APPS "Build Marble Desktop/Mobile applications" ON)
add_feature_info("Marble Desktop/Mobile applications" BUILD_MARBLE_APPS "Build Marble Desktop/Mobile applications. Toggle with BUILD_MARBLE_APPS=YES/NO.")
if(BUILD_MARBLE_APPS)
  add_subdirectory( apps )
endif()

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/config-marble.h.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/config-marble.h
)

if(APPLE)
  add_subdirectory( mac )
endif(APPLE)

