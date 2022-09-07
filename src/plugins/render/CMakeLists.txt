# Example
# add_subdirectory( test )

# Display a control or a screen box
add_subdirectory( compass )
add_subdirectory( elevationprofilefloatitem )
# add_subdirectory( fileview )
add_subdirectory( license )
add_subdirectory( mapscale )
add_subdirectory( navigation )
add_subdirectory( overviewmap )
add_subdirectory( progress )

# Display geographical information on the map
add_subdirectory( annotate )
add_subdirectory( crosshairs )
add_subdirectory( elevationprofilemarker )
add_subdirectory( graticule )
add_subdirectory( measure )
add_subdirectory( atmosphere )
add_subdirectory( stars )
add_subdirectory( sun )

find_package( Perl )
marble_set_package_properties( Perl PROPERTIES URL "http://www.perl.org" )
marble_set_package_properties( Perl PROPERTIES TYPE OPTIONAL PURPOSE "generation of sources in the APRS plugin" )
if( PERL_FOUND AND NOT CMAKE_SYSTEM_NAME STREQUAL Android)
    add_subdirectory( aprs )
endif()
