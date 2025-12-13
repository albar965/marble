/*
    Copyright (C) 2007 Nikolas Zimmermann <zimmermann@kde.org>

    This file is part of the KDE project

    This library is free software you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    aint with this library see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "KmlElementDictionary.h"

#include <QLatin1String>

namespace Marble {

// One static list of all tag names, to avoid string comparisons all-over-the-place
namespace kml {

const QLatin1String kmlTag_nameSpace20("http://earth.google.com/kml/2.0");
const QLatin1String kmlTag_nameSpace21("http://earth.google.com/kml/2.1");
const QLatin1String kmlTag_nameSpace22("http://earth.google.com/kml/2.2");
const QLatin1String kmlTag_nameSpaceOgc22("http://www.opengis.net/kml/2.2");
const QLatin1String kmlTag_nameSpaceGx22("http://www.google.com/kml/ext/2.2");
const QLatin1String kmlTag_nameSpaceMx("http://marble.kde.org");

const QLatin1String kmlTag_address("address");
const QLatin1String kmlTag_AddressDetails("AddressDetails");
const QLatin1String kmlTag_Alias("Alias");
const QLatin1String kmlTag_altitude("altitude");
const QLatin1String kmlTag_altitudeMode("altitudeMode");
const QLatin1String kmlTag_BalloonStyle("BalloonStyle");
const QLatin1String kmlTag_begin("begin");
const QLatin1String kmlTag_bgColor("bgColor");
const QLatin1String kmlTag_bottomFov("bottomFov");
const QLatin1String kmlTag_Camera("Camera");
const QLatin1String kmlTag_Change("Change");
const QLatin1String kmlTag_code("code");
const QLatin1String kmlTag_color("color");
const QLatin1String kmlTag_colorMode("colorMode");
const QLatin1String kmlTag_ColorStyle("ColorStyle");
const QLatin1String kmlTag_Container("Container");
const QLatin1String kmlTag_cookie("cookie");
const QLatin1String kmlTag_coordinates("coordinates");
const QLatin1String kmlTag_Create("Create");
const QLatin1String kmlTag_Data("Data");
const QLatin1String kmlTag_Delete("Delete");
const QLatin1String kmlTag_description("description");
const QLatin1String kmlTag_displayMode("displayMode");
const QLatin1String kmlTag_displayName("displayName");
const QLatin1String kmlTag_Document("Document");
const QLatin1String kmlTag_drawOrder("drawOrder");
const QLatin1String kmlTag_duration("duration");
const QLatin1String kmlTag_east("east");
const QLatin1String kmlTag_end("end");
const QLatin1String kmlTag_expires("expires");
const QLatin1String kmlTag_ExtendedData("ExtendedData");
const QLatin1String kmlTag_extrude("extrude");
const QLatin1String kmlTag_Feature("Feature");
const QLatin1String kmlTag_fill("fill");
const QLatin1String kmlTag_flyToMode("flyToMode");
const QLatin1String kmlTag_flyToView("flyToView");
const QLatin1String kmlTag_Folder("Folder");
const QLatin1String kmlTag_geomColor("geomColor");
const QLatin1String kmlTag_Geometry("Geometry");
const QLatin1String kmlTag_GeometryCollection("GeometryCollection");
const QLatin1String kmlTag_geomScale("geomScale");
const QLatin1String kmlTag_gridOrigin("gridOrigin");
const QLatin1String kmlTag_GroundOverlay("GroundOverlay");
const QLatin1String kmlTag_h("h");
const QLatin1String kmlTag_heading("heading");
const QLatin1String kmlTag_href("href");
const QLatin1String kmlTag_hotSpot("hotSpot");
const QLatin1String kmlTag_httpQuery("httpQuery");
const QLatin1String kmlTag_Icon("Icon");
const QLatin1String kmlTag_IconStyle("IconStyle");
const QLatin1String kmlTag_ImagePyramid("ImagePyramid");
const QLatin1String kmlTag_innerBoundaryIs("innerBoundaryIs");
const QLatin1String kmlTag_ItemIcon("ItemIcon");
const QLatin1String kmlTag_key("key");
const QLatin1String kmlTag_kml("kml");
const QLatin1String kmlTag_labelColor("labelColor");
const QLatin1String kmlTag_LabelStyle("LabelStyle");
const QLatin1String kmlTag_latitude("latitude");
const QLatin1String kmlTag_LatLonAltBox("LatLonAltBox");
const QLatin1String kmlTag_LatLonBox("LatLonBox");
const QLatin1String kmlTag_LatLonQuad("LatLonQuad");
const QLatin1String kmlTag_leftFov("leftFov");
const QLatin1String kmlTag_LinearRing("LinearRing");
const QLatin1String kmlTag_LineString("LineString");
const QLatin1String kmlTag_LineStyle("LineStyle");
const QLatin1String kmlTag_Link("Link");
const QLatin1String kmlTag_linkDescription("linkDescription");
const QLatin1String kmlTag_linkName("linkName");
const QLatin1String kmlTag_linkSnippet("linkSnippet");
const QLatin1String kmlTag_listItemType("listItemType");
const QLatin1String kmlTag_ListStyle("ListStyle");
const QLatin1String kmlTag_Location("Location");
const QLatin1String kmlTag_Lod("Lod");
const QLatin1String kmlTag_longitude("longitude");
const QLatin1String kmlTag_LookAt("LookAt");
const QLatin1String kmlTag_maxAltitude("maxAltitude");
const QLatin1String kmlTag_maxFadeExtent("maxFadeExtent");
const QLatin1String kmlTag_maxHeight("maxHeight");
const QLatin1String kmlTag_maxLodPixels("maxLodPixels");
const QLatin1String kmlTag_maxSessionLength("maxSessionLength");
const QLatin1String kmlTag_maxWidth("maxWidth");
const QLatin1String kmlTag_message("message");
const QLatin1String kmlTag_Metadata("Metadata");
const QLatin1String kmlTag_minAltitude("minAltitude");
const QLatin1String kmlTag_minFadeExtent("minFadeExtent");
const QLatin1String kmlTag_minLodPixels("minLodPixels");
const QLatin1String kmlTag_minRefreshPeriod("minRefreshPeriod");
const QLatin1String kmlTag_Model("Model");
const QLatin1String kmlTag_MultiGeometry("MultiGeometry");
const QLatin1String kmlTag_name("name");
const QLatin1String kmlTag_near("near");
const QLatin1String kmlTag_NetworkLink("NetworkLink");
const QLatin1String kmlTag_NetworkLinkControl("NetworkLinkControl");
const QLatin1String kmlTag_north("north");
const QLatin1String kmlTag_Object("Object");
const QLatin1String kmlTag_ObjArrayField("ObjArrayField");
const QLatin1String kmlTag_ObjField("ObjField");
const QLatin1String kmlTag_open("open");
const QLatin1String kmlTag_Orientation("Orientation");
const QLatin1String kmlTag_OsmPlacemarkData("OsmPlacemarkData");
const QLatin1String kmlTag_member("member");
const QLatin1String kmlTag_nd("nd");
const QLatin1String kmlTag_tag("tag");
const QLatin1String kmlTag_outerBoundaryIs("outerBoundaryIs");
const QLatin1String kmlTag_outline("outline");
const QLatin1String kmlTag_Overlay("Overlay");
const QLatin1String kmlTag_overlayXY("overlayXY");
const QLatin1String kmlTag_Pair("Pair");
const QLatin1String kmlTag_phoneNumber("phoneNumber");
const QLatin1String kmlTag_PhotoOverlay("PhotoOverlay");
const QLatin1String kmlTag_Placemark("Placemark");
const QLatin1String kmlTag_Point("Point");
const QLatin1String kmlTag_Polygon("Polygon");
const QLatin1String kmlTag_PolyStyle("PolyStyle");
const QLatin1String kmlTag_range("range");
const QLatin1String kmlTag_refreshInterval("refreshInterval");
const QLatin1String kmlTag_refreshMode("refreshMode");
const QLatin1String kmlTag_refreshVisibility("refreshVisibility");
const QLatin1String kmlTag_Region("Region");
const QLatin1String kmlTag_request("request");
const QLatin1String kmlTag_ResourceMap("ResourceMap");
const QLatin1String kmlTag_Response("Response");
const QLatin1String kmlTag_rightFov("rightFov");
const QLatin1String kmlTag_roll("roll");
const QLatin1String kmlTag_rotation("rotation");
const QLatin1String kmlTag_rotationXY("rotationXY");
const QLatin1String kmlTag_Scale("Scale");
const QLatin1String kmlTag_scale("scale");
const QLatin1String kmlTag_Schema("Schema");
const QLatin1String kmlTag_SchemaData("SchemaData");
const QLatin1String kmlTag_SchemaField("SchemaField");
const QLatin1String kmlTag_ScreenOverlay("ScreenOverlay");
const QLatin1String kmlTag_screenXY("screenXY");
const QLatin1String kmlTag_shape("shape");
const QLatin1String kmlTag_SimpleArrayData("SimpleArrayData");
const QLatin1String kmlTag_SimpleArrayField("SimpleArrayField");
const QLatin1String kmlTag_SimpleData("SimpleData");
const QLatin1String kmlTag_SimpleField("SimpleField");
const QLatin1String kmlTag_size("size");
const QLatin1String kmlTag_Snippet("Snippet");
const QLatin1String kmlTag_sourceHref("sourceHref");
const QLatin1String kmlTag_south("south");
const QLatin1String kmlTag_state("state");
const QLatin1String kmlTag_Status("Status");
const QLatin1String kmlTag_Style("Style");
const QLatin1String kmlTag_StyleMap("StyleMap");
const QLatin1String kmlTag_StyleSelector("StyleSelector");
const QLatin1String kmlTag_styleUrl("styleUrl");
const QLatin1String kmlTag_targetHref("targetHref");
const QLatin1String kmlTag_tessellate("tessellate");
const QLatin1String kmlTag_text("text");
const QLatin1String kmlTag_textColor("textColor");
const QLatin1String kmlTag_tileSize("tileSize");
const QLatin1String kmlTag_tilt("tilt");
const QLatin1String kmlTag_TimeSpan("TimeSpan");
const QLatin1String kmlTag_TimeStamp("TimeStamp");
const QLatin1String kmlTag_topFov("topFov");
const QLatin1String kmlTag_Update("Update");
const QLatin1String kmlTag_Url("Url");
const QLatin1String kmlTag_value("value");
const QLatin1String kmlTag_viewBoundScale("viewBoundScale");
const QLatin1String kmlTag_viewFormat("viewFormat");
const QLatin1String kmlTag_viewRefreshMode("viewRefreshMode");
const QLatin1String kmlTag_viewRefreshTime("viewRefreshTime");
const QLatin1String kmlTag_ViewVolume("ViewVolume");
const QLatin1String kmlTag_visibility("visibility");
const QLatin1String kmlTag_w("w");
const QLatin1String kmlTag_west("west");
const QLatin1String kmlTag_when("when");
const QLatin1String kmlTag_width("width");
const QLatin1String kmlTag_x("x");
const QLatin1String kmlTag_y("y");
const QLatin1String kmlTag_z("z");

const QLatin1String kmlTag_AnimatedUpdate("AnimatedUpdate");
const QLatin1String kmlTag_FlyTo("FlyTo");
const QLatin1String kmlTag_MultiTrack("MultiTrack");
const QLatin1String kmlTag_Track("Track");
const QLatin1String kmlTag_coord("coord");
const QLatin1String kmlTag_delayedStart("delayedStart");
const QLatin1String kmlTag_SoundCue("SoundCue");
const QLatin1String kmlTag_Tour("Tour");
const QLatin1String kmlTag_TourControl("TourControl");
const QLatin1String kmlTag_Wait("Wait");
const QLatin1String kmlTag_Playlist("Playlist");
const QLatin1String kmlTag_playMode("playMode");
const QLatin1String kmlTag_balloonVisibility("balloonVisibility");

#ifdef KML_LAZY_IMP
const QLatin1String kmlTag_MarblePlacemark("MarblePlacemark");
const QLatin1String kmlTag_area("area");
const QLatin1String kmlTag_pop("pop");
const QLatin1String kmlTag_role("role");
const QLatin1String kmlTag_CountryNameCode("CountryNameCode");
const QLatin1String kmlTag_countrycode("countrycode");
#endif // KML_LAZY_IMP
}

}
