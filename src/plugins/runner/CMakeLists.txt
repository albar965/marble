# Search and/or reverse geocoding
add_subdirectory( hostip )
add_subdirectory( geouri )
add_subdirectory( latlon )
add_subdirectory( localdatabase )

# Routing
add_subdirectory( mapquest )
add_subdirectory( monav )
add_subdirectory( yours )
add_subdirectory( cyclestreets )

#Parsing
add_subdirectory( cache )
add_subdirectory( gpx )
add_subdirectory( kml )
add_subdirectory( osm )
add_subdirectory( pn2 )
add_subdirectory( pnt )
add_subdirectory( log )

macro_optional_find_package( libshp )
marble_set_package_properties( libshp PROPERTIES DESCRIPTION "reading and writing of ESRI Shapefiles (.shp)" )
marble_set_package_properties( libshp PROPERTIES URL "http://shapelib.maptools.org/" )
marble_set_package_properties( libshp PROPERTIES TYPE OPTIONAL PURPOSE "reading and displaying .shp files" )
if( LIBSHP_FOUND )
  add_subdirectory( shp )
endif( LIBSHP_FOUND )
