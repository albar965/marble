if(NOT CMAKE_SYSTEM_NAME STREQUAL Android)
    add_subdirectory( templates )
endif()

add_subdirectory( render )
add_subdirectory( runner )
