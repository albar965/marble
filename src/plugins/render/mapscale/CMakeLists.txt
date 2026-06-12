PROJECT(MapScaleFloatItem)

INCLUDE_DIRECTORIES(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
)

set( mapscale_SRCS MapScaleFloatItem.cpp )

marble_add_plugin( MapScaleFloatItem ${mapscale_SRCS} )
