install (FILES
credits_authors.html
credits_data.html
legend.html
legend.css
DESTINATION ${MARBLE_DATA_INSTALL_PATH})

FILE (GLOB LEGEND_FILES *.leg)
install (FILES ${LEGEND_FILES}
DESTINATION ${MARBLE_DATA_INSTALL_PATH})

FILE (GLOB BITMAP_FILES bitmaps/*.png)
install (FILES ${BITMAP_FILES}
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/bitmaps)

INSTALL (DIRECTORY svg/osmcarto/svg
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/svg/osmcarto
FILES_MATCHING PATTERN "*.svg"
PATTERN "svgorig" EXCLUDE)

install (DIRECTORY bitmaps/osmcarto
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/bitmaps
PATTERN "LICENSE.txt" EXCLUDE)

FILE (GLOB BITMAP_FILES bitmaps/*.jpg)
install (FILES ${BITMAP_FILES}
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/bitmaps)

install (FILES
svg/marble-logo.svg
svg/marble-logo.png
svg/marble-logo-32dpi.png
svg/marble-logo-72dpi.png
svg/marble-logo-inverted-32dpi.png
svg/marble-logo-inverted-72dpi.png
svg/application-x-marble.svg
svg/application-x-marble.png
svg/application-x-marble-gray.png
svg/worldmap.svg
svg/coordinate.svg
svg/wikipedia.svg
svg/wikipedia_shadow.svg
svg/sunshine.png
svg/sun.png
svg/moon.png
svg/glow.png
svg/track_turtle.svg
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/svg)

FILE (GLOB SVG_FILES flags/*.svg)
install (FILES ${SVG_FILES}
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/flags)

install (DIRECTORY maps/earth/srtm DESTINATION ${MARBLE_DATA_INSTALL_PATH}/maps/earth)

install (FILES
maps/earth/srtm2/srtm2.dgml
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/maps/earth/srtm2)

install (FILES
maps/earth/srtm2/0/000000/000000_000000.png
maps/earth/srtm2/0/000000/000000_000001.png
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/maps/earth/srtm2/0/000000)


install (FILES
maps/earth/plain/plain.dgml
maps/earth/plain/plain-preview.png
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/maps/earth/plain)

install (DIRECTORY maps/earth/openstreetmap
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/maps/earth
)

install (FILES
maps/earth/hillshading/0/0/0.png
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/maps/earth/hillshading/0/0)

install (FILES
maps/earth/political/political-preview.png
maps/earth/political/political.dgml
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/maps/earth/political)

FILE (GLOB_RECURSE DGML_FILES maps/*.dgml)
MARBLE_ADD_PROJECT_RESOURCES(${DGML_FILES})

install (FILES
mwdbii/DATELINE.PNT
mwdbii/PCOAST.PNT
mwdbii/PDIFFBORDER.PNT
mwdbii/PGLACIER.PNT
mwdbii/PISLAND.PNT
mwdbii/PLAKEISLAND.PNT
mwdbii/PLAKE.PNT
mwdbii/PUSA48.DIFF.PNT
mwdbii/RIVER.PNT
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/mwdbii)

FILE (GLOB PN2_FILES naturalearth/*.pn2)
install (FILES ${PN2_FILES}
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/naturalearth)

FILE (GLOB STAR_FILES stars/*.dat)
install (FILES ${STAR_FILES} stars/deepsky.png stars/names.csv
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/stars)

install (FILES
placemarks/elevplacemarks.cache
placemarks/otherplacemarks.cache
placemarks/baseplacemarks.cache
placemarks/moonlandingsites.cache
placemarks/boundaryplacemarks.cache
placemarks/moonterrain.cache
DESTINATION ${MARBLE_DATA_INSTALL_PATH}/placemarks)

install (FILES placemarks/cityplacemarks.cache DESTINATION ${MARBLE_DATA_INSTALL_PATH}/placemarks)

if(NOT APPLE AND NOT WIN32)
  install (FILES icons/128-apps-marble.png DESTINATION ${ICON_INSTALL_DIR}/hicolor/128x128/apps/ RENAME marble.png)
  install (FILES icons/64-apps-marble.png DESTINATION ${ICON_INSTALL_DIR}/hicolor/64x64/apps/ RENAME marble.png)
  install (FILES icons/48-apps-marble.png DESTINATION ${ICON_INSTALL_DIR}/hicolor/48x48/apps/ RENAME marble.png)
  install (FILES icons/32-apps-marble.png DESTINATION ${ICON_INSTALL_DIR}/hicolor/32x32/apps/ RENAME marble.png)
  install (FILES icons/22-apps-marble.png DESTINATION ${ICON_INSTALL_DIR}/hicolor/22x22/apps/ RENAME marble.png)
  install (FILES icons/16-apps-marble.png DESTINATION ${ICON_INSTALL_DIR}/hicolor/16x16/apps/ RENAME marble.png)
endif(NOT APPLE AND NOT WIN32 )


add_subdirectory(lang)

