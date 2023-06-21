PROJECT(marblewidget)

macro_optional_find_package(Phonon)
marble_set_package_properties( Phonon PROPERTIES DESCRIPTION "cross-platform multimedia framework that enables the use of audio and video content" )
marble_set_package_properties( Phonon PROPERTIES URL "http://qt.digia.com/" )
marble_set_package_properties( Phonon PROPERTIES TYPE OPTIONAL PURPOSE "Support for playback of soundcue elements" )
if(PHONON_FOUND)
    set(HAVE_PHONON TRUE)
endif()
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config-phonon.h.cmake
               ${CMAKE_CURRENT_BINARY_DIR}/config-phonon.h)

INCLUDE_DIRECTORIES(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
 ${CMAKE_CURRENT_SOURCE_DIR}/projections
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
 ${CMAKE_CURRENT_SOURCE_DIR}/osm
 ${CMAKE_SOURCE_DIR}/src/lib/astro
 ${ZLIB_INCLUDE_DIRS}
 ${PHONON_INCLUDES}
)

INCLUDE(geodata/CMakeLists.txt)
INCLUDE(graphicsview/CMakeLists.txt)
INCLUDE(layers/CMakeLists.txt)
INCLUDE(osm/CMakeLists.txt)

set(MARBLE_LIB_VERSION "0.25.4")
set(MARBLE_ABI_VERSION "25")

########### next target ###############

if(MARBLE_NO_WEBKITWIDGETS)
add_definitions(-DMARBLE_NO_WEBKITWIDGETS)
endif()

set(marblewidget_SRCS
    ${geodata_SRCS}
    ${graphicsview_SRCS}
    ${layers_SRCS}
    ${osm_SRCS}
    blendings/Blending.cpp
    blendings/BlendingAlgorithms.cpp
    blendings/BlendingFactory.cpp
    blendings/SunLightBlending.cpp
    DownloadRegion.cpp
    LatLonBoxWidget.cpp
    MarbleWidget.cpp
    MarbleAbstractPresenter.cpp
    MarbleModel.cpp
    MarbleMap.cpp
    MarbleColors.cpp
    MapViewWidget.cpp
    CelestialSortFilterProxyModel.cpp
    FileViewWidget.cpp
    FlyToEditWidget.cpp
    WaitEditWidget.cpp
    RemoveItemEditWidget.cpp
    MapViewItemDelegate.cpp
    LegendWidget.cpp
    MarbleNavigator.cpp
    MarbleLegendBrowser.cpp
    MarbleAboutDialog.cpp
    MarbleInputHandler.cpp
    MarbleWidgetInputHandler.cpp
    MarblePlacemarkModel.cpp
    GeoDataTreeModel.cpp
    GeoUriParser.cpp
    kdescendantsproxymodel.cpp
    BranchFilterProxyModel.cpp
    TreeViewDecoratorModel.cpp
    MarbleDebug.cpp
    Tile.cpp
    TextureTile.cpp
    TileCoordsPyramid.cpp
    TileLevelRangeWidget.cpp
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
    PopupItem.cpp
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
    PositionTracking.cpp
    DataMigration.cpp
    ImageF.cpp
    EditPlacemarkDialog.cpp
    AddLinkDialog.cpp
    FormattedTextWidget.cpp

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
    PositionProviderPlugin.cpp
    PositionProviderPluginInterface.cpp
    PlacemarkPositionProviderPlugin.cpp
    MarblePluginSettingsWidget.cpp
    RenderPluginModel.cpp
    PluginAboutDialog.cpp
    PluginItemDelegate.cpp

    SunLocator.cpp
    MarbleClock.cpp
    SunControlWidget.cpp
    MergedLayerDecorator.cpp

    MathHelper.cpp

    LatLonEdit.cpp
    PlacemarkEditHeader.cpp

    MapThemeSortFilterProxyModel.cpp

    TemplateDocument.cpp

    ParsingRunnerManager.cpp
    SearchRunnerManager.cpp

    AutoNavigation.cpp

    SearchRunnerPlugin.cpp
    ParseRunnerPlugin.cpp
    SearchRunner.cpp
    ParsingRunner.cpp
    RunnerTask.cpp

    PrintOptionsWidget.cpp
    ExternalEditorDialog.cpp

    MapWizard.cpp
    MapThemeDownloadDialog.cpp
    GeoGraphicsScene.cpp
    ElevationModel.cpp
    MarbleLineEdit.cpp
    SearchInputWidget.cpp
    SearchWidget.cpp
    kineticmodel.cpp
    NewstuffModel.cpp
    MarbleZip.cpp

    StyleBuilder.cpp

)


if (MARBLE_NO_WEBKITWIDGETS)
    LIST(APPEND marblewidget_SRCS
        NullMarbleWebView.cpp
        NullTinyWebBrowser.cpp
        )
else()
    LIST(APPEND marblewidget_SRCS
        MarbleWebView.cpp
        TinyWebBrowser.cpp
        )
endif()

if (NOT MARBLE_NO_DBUS)
    LIST(APPEND marblewidget_SRCS
        MarbleDBusInterface.cpp
        )
endif()

set (marblewidget_UI
    ${osm_UIS}
    LatLonBoxWidget.ui
    MapViewWidget.ui
    FileViewWidget.ui
    MarbleNavigator.ui
    MarbleCacheSettingsWidget.ui
    MarbleViewSettingsWidget.ui
    MarbleNavigationSettingsWidget.ui
    TimeControlWidget.ui
    MarbleTimeSettingsWidget.ui
    MarblePluginSettingsWidget.ui
    TileCreatorDialog.ui
    TileLevelRangeWidget.ui
    MarbleAboutDialog.ui
    SunControlWidget.ui
    LatLonEdit.ui
    PlacemarkEditHeader.ui
    DataMigrationWidget.ui
    PrintOptions.ui
    ExternalEditor.ui
    MapWizard.ui
    MapThemeDownloadDialog.ui
    EditPlacemarkDialog.ui
    AddLinkDialog.ui
    FormattedTextWidget.ui
    ElevationWidget.ui
)
if (MARBLE_NO_WEBKITWIDGETS)
    LIST(APPEND marblewidget_UI
        NullLegendWidget.ui
        NullWebPopupWidget.ui
        )
else()
    LIST(APPEND marblewidget_UI
        LegendWidget.ui
        WebPopupWidget.ui
        )
endif()

# FIXME: cleaner approach of src/lib/marblwidget/MarbleControlBox.* vs. marble.qrc
qt_add_resources(marblewidget_SRCS libmarble.qrc ../../apps/marble-ui/marble.qrc)

qt_wrap_ui(marblewidget_SRCS ${marblewidget_UI})

add_library(marblewidget SHARED ${marblewidget_SRCS} ${SOURCES_UI_HDRS})

generate_export_header(marblewidget BASE_NAME marble)


# TODO: use PUBLIC/PRIVATE everywhere instead of LINK_PUBLIC/LINK_PRIVATE
# once SailfishOS has cmake >= 2.8.12

# link with libastro
target_link_libraries(marblewidget LINK_PRIVATE astro)

# link against zlib
target_link_libraries(marblewidget LINK_PRIVATE ${ZLIB_LIBRARIES})

# link with release version of Qt libs
target_link_libraries(marblewidget
    LINK_PUBLIC
        Qt5::Xml
        Qt5::Gui
        Qt5::Widgets
        Qt5::Quick
        Qt5::Network
    LINK_PRIVATE
        Qt5::Svg
        Qt5::PrintSupport
        Qt5::Concurrent
)
if (NOT MARBLE_NO_WEBKITWIDGETS)
    target_link_libraries(marblewidget
        LINK_PUBLIC
            Qt5::WebKitWidgets
    )
endif ()
if (NOT MARBLE_NO_DBUS)
    target_link_libraries(marblewidget
        LINK_PRIVATE
            Qt5::DBus
    )
endif ()
if (PHONON_FOUND)
    target_link_libraries(marblewidget
        LINK_PRIVATE
            ${PHONON_LIBS}
    )
endif()

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
    OUTPUT_NAME marblewidget-qt5
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

if (MARBLE_NO_WEBKITWIDGETS)
    set(marble_WebKit
        NullMarbleWebView.h
        NullTinyWebBrowser.h
        )
else()
    set(marble_WebKit
        MarbleWebView.h
        TinyWebBrowser.h
        )
endif()

install( FILES
    ${CMAKE_CURRENT_BINARY_DIR}/marble_export.h
    ${graphicsview_HDRS}
    ${marble_WebKit}
    AutoNavigation.h
    DownloadRegion.h
    LatLonBoxWidget.h
    MarbleWidget.h
    MarbleMap.h
    MarbleModel.h
    MapViewWidget.h
    CelestialSortFilterProxyModel.h
    LegendWidget.h
    FileViewWidget.h
    FlyToEditWidget.h
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
    TileLevelRangeWidget.h
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
    PositionTracking.h
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
    PositionProviderPlugin.h
    PositionProviderPluginInterface.h
    RenderPlugin.h
    RenderPluginInterface.h
    ParsingRunnerManager.h
    SearchRunnerManager.h
    ParsingRunner.h
    SearchRunner.h
    SearchRunnerPlugin.h
    ParseRunnerPlugin.h
    LayerInterface.h
    RenderState.h
    PluginAboutDialog.h
    Planet.h
    PlanetFactory.h
    EditPlacemarkDialog.h
    AddLinkDialog.h
    FormattedTextWidget.h

    AbstractDataPlugin.h
    AbstractDataPluginModel.h
    AbstractDataPluginItem.h
    AbstractWorkerThread.h

    LatLonEdit.h
    PlacemarkEditHeader.h
    MapWizard.h
    MapThemeDownloadDialog.h
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
