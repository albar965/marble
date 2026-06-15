PROJECT( LabelFloatItem )

INCLUDE_DIRECTORIES(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
)

set( labelfloatitem_SRCS LabelFloatItem.cpp )
set( labelfloatitem_UI LabelFloatItemConfigWidget.ui )

qt_wrap_ui(labelfloatitem_SRCS ${labelfloatitem_UI})

set( LabelFloatItem_LIBS Qt6::Svg )

marble_add_plugin( LabelFloatItem ${labelfloatitem_SRCS} )
