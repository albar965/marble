PROJECT(marblewidget)

INCLUDE_DIRECTORIES(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
 ${CMAKE_CURRENT_SOURCE_DIR}/projections
 ${CMAKE_CURRENT_SOURCE_DIR}/astro
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata/data
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata/graphicsitem
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata/scene
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata/handlers
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata/handlers/kml
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata/handlers/dgml
 ${CMAKE_CURRENT_SOURCE_DIR}/geodata/parser
 ${CMAKE_CURRENT_SOURCE_DIR}/graphicsview
 ${CMAKE_CURRENT_SOURCE_DIR}/layers
 ${ZLIB_INCLUDE_DIRS}
)

INCLUDE(geodata/CMakeLists.txt)
INCLUDE(graphicsview/CMakeLists.txt)
INCLUDE(layers/CMakeLists.txt)

# VERSION_NUMBER_TODO
set(MARBLE_LIB_VERSION "1.0.3")
set(MARBLE_ABI_VERSION "1")

########### next target ###############

set(marblewidget_SRCS
    ${geodata_SRCS}
    ${graphicsview_SRCS}
    ${layers_SRCS}
    blendings/Blending.cpp
    blendings/BlendingAlgorithms.cpp
    blendings/BlendingFactory.cpp
    blendings/SunLightBlending.cpp

    astro/astr2lib.cpp
    astro/astrolib.cpp
    astro/attlib.cpp
    astro/solarsystem.cpp

    DownloadRegion.cpp

    MarbleWidget.cpp
    MarbleAbstractPresenter.cpp
    MarbleModel.cpp
    MarbleMap.cpp
    MarbleColors.cpp
    WaitEditWidget.cpp
    RemoveItemEditWidget.cpp
    MapViewItemDelegate.cpp
    MarbleNavigator.cpp
    MarbleAboutDialog.cpp
    MarbleInputHandler.cpp
    MarbleWidgetInputHandler.cpp
    MarblePlacemarkModel.cpp
    GeoDataTreeModel.cpp
    kdescendantsproxymodel.cpp
    BranchFilterProxyModel.cpp
    TreeViewDecoratorModel.cpp
    MarbleDebug.cpp
    Tile.cpp
    TextureTile.cpp
    TileCoordsPyramid.cpp
    TileLoader.cpp
    ClipPainter.cpp
    DownloadPolicy.cpp
    DownloadQueueSet.cpp
    GeoPainter.cpp
    HttpDownloadManager.cpp
    HttpJob.cpp
    RemoteIconLoader.cpp
    LayerManager.cpp
    PluginManager.cpp
    TimeControlWidget.cpp
    AbstractFloatItem.cpp
    MarbleGlobal.cpp
    MarbleDirs.cpp
    MarbleLocale.cpp
    MarblePhysics.cpp
    DeferredFlag.cpp
    TileCreatorDialog.cpp
    MapThemeManager.cpp
    ViewportParams.cpp
    ViewParams.cpp
    projections/AbstractProjection.cpp
    projections/CylindricalProjection.cpp
    projections/AzimuthalProjection.cpp
    projections/SphericalProjection.cpp
    projections/EquirectProjection.cpp
    projections/MercatorProjection.cpp
    projections/GnomonicProjection.cpp
    projections/StereographicProjection.cpp
    projections/LambertAzimuthalProjection.cpp
    projections/AzimuthalEquidistantProjection.cpp
    projections/VerticalPerspectiveProjection.cpp
    VisiblePlacemark.cpp
    PlacemarkLayout.cpp
    Planet.cpp
    PlanetFactory.cpp
    Quaternion.cpp
    TextureColorizer.cpp
    TextureMapperInterface.cpp
    ScanlineTextureMapperContext.cpp
    SphericalScanlineTextureMapper.cpp
    EquirectScanlineTextureMapper.cpp
    MercatorScanlineTextureMapper.cpp
    TileScalingTextureMapper.cpp
    GenericScanlineTextureMapper.cpp
    VectorTileModel.cpp
    DiscCache.cpp
    ServerLayout.cpp
    StoragePolicy.cpp
    CacheStoragePolicy.cpp
    FileStoragePolicy.cpp
    FileStorageWatcher.cpp
    StackedTile.cpp
    TileId.cpp
    StackedTileLoader.cpp
    TileLoaderHelper.cpp
    TileCreator.cpp
    #jsonparser.cpp
    FileLoader.cpp
    FileManager.cpp
    ImageF.cpp

    AbstractDataPlugin.cpp
    AbstractDataPluginModel.cpp
    AbstractDataPluginItem.cpp
    AbstractWorkerThread.cpp

    PluginInterface.cpp
    DialogConfigurationInterface.cpp
    LayerInterface.cpp
    RenderState.cpp
    RenderPlugin.cpp
    RenderPluginInterface.cpp
    MarblePluginSettingsWidget.cpp
    RenderPluginModel.cpp
    PluginAboutDialog.cpp
    PluginItemDelegate.cpp

    SunLocator.cpp
    MarbleClock.cpp
    MergedLayerDecorator.cpp

    MathHelper.cpp

    ParsingRunnerManager.cpp

    ParseRunnerPlugin.cpp
    ParsingRunner.cpp
    RunnerTask.cpp

    GeoGraphicsScene.cpp
    ElevationModel.cpp
    kineticmodel.cpp
    MarbleZip.cpp

    StyleBuilder.cpp

)


set (marblewidget_UI
    MarbleNavigator.ui
    MarbleCacheSettingsWidget.ui
    MarbleViewSettingsWidget.ui
    MarbleNavigationSettingsWidget.ui
    TimeControlWidget.ui
    MarbleTimeSettingsWidget.ui
    MarblePluginSettingsWidget.ui
    TileCreatorDialog.ui
    MarbleAboutDialog.ui
    PrintOptions.ui
    ExternalEditor.ui
    ElevationWidget.ui
)

# FIXME: cleaner approach of src/lib/marblwidget/MarbleControlBox.* vs. marble.qrc
qt_add_resources(marblewidget_SRCS libmarble.qrc ../../apps/marble-ui/marble.qrc)

qt_wrap_ui(marblewidget_SRCS ${marblewidget_UI})

add_library(marblewidget SHARED ${marblewidget_SRCS} ${SOURCES_UI_HDRS})

generate_export_header(marblewidget BASE_NAME marble)


# TODO: use PUBLIC/PRIVATE everywhere instead of LINK_PUBLIC/LINK_PRIVATE
# once SailfishOS has cmake >= 2.8.12

# link against zlib
target_link_libraries(marblewidget LINK_PRIVATE ${ZLIB_LIBRARIES})

# link with release version of Qt libs
target_link_libraries(marblewidget
    LINK_PUBLIC
        Qt6::Xml
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network
    LINK_PRIVATE
        Qt6::Svg
        Qt6::Concurrent
)

if (APPLE)
  # TODO: PUBLIC or can be PRIVATE?
  #defined in top level makefile
  target_link_libraries(marblewidget LINK_PUBLIC ${MAC_EXTRA_LIBS} )
endif (APPLE)

# TODO: still supported?
if (CMAKE_SYSTEM_NAME MATCHES "SunOS")
  target_link_libraries(marblewidget LINK_PUBLIC m)
endif (CMAKE_SYSTEM_NAME MATCHES "SunOS")

if(WIN32)
  # TODO: PUBLIC or can be PRIVATE?
  target_link_libraries(marblewidget LINK_PUBLIC ws2_32 imm32 winmm)
endif(WIN32)

if(NOT CMAKE_SYSTEM_NAME STREQUAL Android)
  set_target_properties(marblewidget  PROPERTIES
    VERSION ${MARBLE_LIB_VERSION}
    SOVERSION ${MARBLE_ABI_VERSION}
  )
endif()

set_target_properties(marblewidget  PROPERTIES
    EXPORT_NAME "Marble"
    OUTPUT_NAME marblewidget-lnm-qt6
    COMPILE_FLAGS "-DKML_LAZY_IMP"
)

target_include_directories(marblewidget
    INTERFACE "$<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>"
)

# choose the correct target install library path
if(WIN32)
  install(TARGETS marblewidget RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX} ARCHIVE DESTINATION lib)
elseif(APPLE)
  install(TARGETS marblewidget LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/Marble.app/Contents/MacOS/lib)
else()
  install(TARGETS marblewidget
    EXPORT MarbleTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()


########### install headers & cmake config files ###############

if (WIN32 OR APPLE)
    # TODO: find how to install & deploy library, headers and config files as bundle for development
    return()
endif()

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/marble_export.h
    ${graphicsview_HDRS}
    DownloadRegion.h
    MarbleWidget.h
    MarbleMap.h
    MarbleModel.h
    astro/astr2lib.h
    astro/astrolib.h
    astro/attlib.h
    astro/solarsystem.h
    WaitEditWidget.h
    RemoveItemEditWidget.h
    MapViewItemDelegate.h
    MarbleNavigator.h
    AbstractFloatItem.h
    MapThemeManager.h
    MarbleAboutDialog.h
    MarbleInputHandler.h
    MarbleWidgetInputHandler.h
    TileId.h
    TileCoordsPyramid.h
    global.h
    MarbleMath.h
    MarbleColors.h
    MarbleGlobal.h
    MarbleLocale.h
    MarbleDebug.h
    MarbleDirs.h
    GeoPainter.h
    HttpDownloadManager.h
    TileCreatorDialog.h
    ViewportParams.h
    projections/AbstractProjection.h
    Quaternion.h
    SunLocator.h
    ClipPainter.h
    GeoGraphicsScene.h
    GeoDataTreeModel.h
    geodata/data/GeoDataAbstractView.h
    geodata/data/GeoDataAccuracy.h
    geodata/data/GeoDataBalloonStyle.h
    geodata/data/GeoDataColorStyle.h
    geodata/data/GeoDataContainer.h
    geodata/data/GeoDataCoordinates.h
    geodata/data/GeoDataDocument.h
    geodata/data/GeoDataFeature.h
    geodata/data/GeoDataFolder.h
    geodata/data/GeoDataGeometry.h
    geodata/data/GeoDataGroundOverlay.h
    geodata/data/GeoDataHotSpot.h
    geodata/data/GeoDataIconStyle.h
    geodata/data/GeoDataItemIcon.h
    geodata/data/GeoDataLabelStyle.h
    geodata/data/GeoDataLatLonAltBox.h
    geodata/data/GeoDataLatLonBox.h
    geodata/data/GeoDataLatLonQuad.h
    geodata/data/GeoDataLinearRing.h
    geodata/data/GeoDataLineString.h
    geodata/data/GeoDataLineStyle.h
    geodata/data/GeoDataListStyle.h
    geodata/data/GeoDataLod.h
    geodata/data/GeoDataLookAt.h
    geodata/data/GeoDataOverlay.h
    geodata/data/GeoDataMultiGeometry.h
    geodata/data/GeoDataObject.h
    geodata/data/GeoDataPlacemark.h
    geodata/data/GeoDataPoint.h
    geodata/data/GeoDataPolygon.h
    geodata/data/GeoDataPolyStyle.h
    geodata/data/GeoDataRegion.h
    geodata/data/GeoDataSnippet.h
    geodata/data/GeoDataStyle.h
    geodata/data/GeoDataStyleMap.h
    geodata/data/GeoDataStyleSelector.h
    geodata/data/GeoDataTrack.h
    geodata/data/GeoDataTimeSpan.h
    geodata/data/GeoDataTimeStamp.h
    geodata/data/GeoDataTimePrimitive.h
    geodata/data/Serializable.h
    geodata/geodata_export.h
    geodata/parser/GeoDocument.h
    geodata/parser/GeoDataTypes.h
    geodata/writer/GeoWriter.h
    TileCreator.h
    PluginManager.h
    PluginInterface.h
    DialogConfigurationInterface.h
    RenderPlugin.h
    RenderPluginInterface.h
    ParsingRunnerManager.h
    ParsingRunner.h
    ParseRunnerPlugin.h
    LayerInterface.h
    RenderState.h
    PluginAboutDialog.h
    Planet.h
    PlanetFactory.h

    AbstractDataPlugin.h
    AbstractDataPluginModel.h
    AbstractDataPluginItem.h
    AbstractWorkerThread.h

    ElevationModel.h

    DESTINATION ${INCLUDE_INSTALL_DIR}/marble
)


########### CMake Config files ###############

include(CMakePackageConfigHelpers)

set(MARBLE_CMAKECONFIGNAME Marble)
set(MARBLE_INSTALL_CMAKECONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${MARBLE_CMAKECONFIGNAME})

configure_package_config_file(MarbleConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${MARBLE_CMAKECONFIGNAME}Config.cmake
    INSTALL_DESTINATION ${MARBLE_INSTALL_CMAKECONFIGDIR}
)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${MARBLE_CMAKECONFIGNAME}ConfigVersion.cmake
    VERSION ${MARBLE_LIB_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${MARBLE_CMAKECONFIGNAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${MARBLE_CMAKECONFIGNAME}ConfigVersion.cmake

    DESTINATION ${MARBLE_INSTALL_CMAKECONFIGDIR}
)

install(
    EXPORT MarbleTargets
    FILE ${MARBLE_CMAKECONFIGNAME}Targets.cmake
    DESTINATION ${MARBLE_INSTALL_CMAKECONFIGDIR}
)
