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
    aint with this library see the file COPYING.LIB.  If not, write
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef MARBLE_KML_KMLELEMENTDICTIONARY_H
#define MARBLE_KML_KMLELEMENTDICTIONARY_H

#include "geodata_export.h"

#include <QLatin1String>

namespace Marble {

// Lists all known KML 2.1 tags (http://code.google.com/apis/kml/documentation/kmlTag_tags_21.html)
namespace kml {
GEODATA_EXPORT extern const QLatin1String kmlTag_nameSpace20;
GEODATA_EXPORT extern const QLatin1String kmlTag_nameSpace21;
GEODATA_EXPORT extern const QLatin1String kmlTag_nameSpace22;
GEODATA_EXPORT extern const QLatin1String kmlTag_nameSpaceOgc22;
GEODATA_EXPORT extern const QLatin1String kmlTag_nameSpaceGx22;
GEODATA_EXPORT extern const QLatin1String kmlTag_nameSpaceMx;

GEODATA_EXPORT extern const QLatin1String kmlTag_address;
GEODATA_EXPORT extern const QLatin1String kmlTag_AddressDetails;
GEODATA_EXPORT extern const QLatin1String kmlTag_Alias;
GEODATA_EXPORT extern const QLatin1String kmlTag_altitude;
GEODATA_EXPORT extern const QLatin1String kmlTag_altitudeMode;
GEODATA_EXPORT extern const QLatin1String kmlTag_BalloonStyle;
GEODATA_EXPORT extern const QLatin1String kmlTag_begin;
GEODATA_EXPORT extern const QLatin1String kmlTag_bgColor;
GEODATA_EXPORT extern const QLatin1String kmlTag_bottomFov;
GEODATA_EXPORT extern const QLatin1String kmlTag_Camera;
GEODATA_EXPORT extern const QLatin1String kmlTag_Change;
GEODATA_EXPORT extern const QLatin1String kmlTag_code;
GEODATA_EXPORT extern const QLatin1String kmlTag_color;
GEODATA_EXPORT extern const QLatin1String kmlTag_colorMode;
GEODATA_EXPORT extern const QLatin1String kmlTag_ColorStyle;
GEODATA_EXPORT extern const QLatin1String kmlTag_Container;
GEODATA_EXPORT extern const QLatin1String kmlTag_cookie;
GEODATA_EXPORT extern const QLatin1String kmlTag_coordinates;
GEODATA_EXPORT extern const QLatin1String kmlTag_Create;
GEODATA_EXPORT extern const QLatin1String kmlTag_Data;
GEODATA_EXPORT extern const QLatin1String kmlTag_Delete;
GEODATA_EXPORT extern const QLatin1String kmlTag_description;
GEODATA_EXPORT extern const QLatin1String kmlTag_displayMode;
GEODATA_EXPORT extern const QLatin1String kmlTag_displayName;
GEODATA_EXPORT extern const QLatin1String kmlTag_Document;
GEODATA_EXPORT extern const QLatin1String kmlTag_drawOrder;
GEODATA_EXPORT extern const QLatin1String kmlTag_duration;
GEODATA_EXPORT extern const QLatin1String kmlTag_east;
GEODATA_EXPORT extern const QLatin1String kmlTag_end;
GEODATA_EXPORT extern const QLatin1String kmlTag_expires;
GEODATA_EXPORT extern const QLatin1String kmlTag_ExtendedData;
GEODATA_EXPORT extern const QLatin1String kmlTag_extrude;
GEODATA_EXPORT extern const QLatin1String kmlTag_Feature;
GEODATA_EXPORT extern const QLatin1String kmlTag_fill;
GEODATA_EXPORT extern const QLatin1String kmlTag_flyToMode;
GEODATA_EXPORT extern const QLatin1String kmlTag_flyToView;
GEODATA_EXPORT extern const QLatin1String kmlTag_Folder;
GEODATA_EXPORT extern const QLatin1String kmlTag_geomColor;
GEODATA_EXPORT extern const QLatin1String kmlTag_Geometry;
GEODATA_EXPORT extern const QLatin1String kmlTag_GeometryCollection;
GEODATA_EXPORT extern const QLatin1String kmlTag_geomScale;
GEODATA_EXPORT extern const QLatin1String kmlTag_gridOrigin;
GEODATA_EXPORT extern const QLatin1String kmlTag_GroundOverlay;
GEODATA_EXPORT extern const QLatin1String kmlTag_h;
GEODATA_EXPORT extern const QLatin1String kmlTag_heading;
GEODATA_EXPORT extern const QLatin1String kmlTag_href;
GEODATA_EXPORT extern const QLatin1String kmlTag_hotSpot;
GEODATA_EXPORT extern const QLatin1String kmlTag_httpQuery;
GEODATA_EXPORT extern const QLatin1String kmlTag_Icon;
GEODATA_EXPORT extern const QLatin1String kmlTag_IconStyle;
GEODATA_EXPORT extern const QLatin1String kmlTag_ImagePyramid;
GEODATA_EXPORT extern const QLatin1String kmlTag_innerBoundaryIs;
GEODATA_EXPORT extern const QLatin1String kmlTag_ItemIcon;
GEODATA_EXPORT extern const QLatin1String kmlTag_key;
GEODATA_EXPORT extern const QLatin1String kmlTag_kml;
GEODATA_EXPORT extern const QLatin1String kmlTag_labelColor;
GEODATA_EXPORT extern const QLatin1String kmlTag_LabelStyle;
GEODATA_EXPORT extern const QLatin1String kmlTag_latitude;
GEODATA_EXPORT extern const QLatin1String kmlTag_LatLonAltBox;
GEODATA_EXPORT extern const QLatin1String kmlTag_LatLonBox;
GEODATA_EXPORT extern const QLatin1String kmlTag_LatLonQuad;
GEODATA_EXPORT extern const QLatin1String kmlTag_leftFov;
GEODATA_EXPORT extern const QLatin1String kmlTag_LinearRing;
GEODATA_EXPORT extern const QLatin1String kmlTag_LineString;
GEODATA_EXPORT extern const QLatin1String kmlTag_LineStyle;
GEODATA_EXPORT extern const QLatin1String kmlTag_Link;
GEODATA_EXPORT extern const QLatin1String kmlTag_linkDescription;
GEODATA_EXPORT extern const QLatin1String kmlTag_linkName;
GEODATA_EXPORT extern const QLatin1String kmlTag_linkSnippet;
GEODATA_EXPORT extern const QLatin1String kmlTag_listItemType;
GEODATA_EXPORT extern const QLatin1String kmlTag_ListStyle;
GEODATA_EXPORT extern const QLatin1String kmlTag_Location;
GEODATA_EXPORT extern const QLatin1String kmlTag_Lod;
GEODATA_EXPORT extern const QLatin1String kmlTag_longitude;
GEODATA_EXPORT extern const QLatin1String kmlTag_LookAt;
GEODATA_EXPORT extern const QLatin1String kmlTag_maxAltitude;
GEODATA_EXPORT extern const QLatin1String kmlTag_maxFadeExtent;
GEODATA_EXPORT extern const QLatin1String kmlTag_maxHeight;
GEODATA_EXPORT extern const QLatin1String kmlTag_maxLodPixels;
GEODATA_EXPORT extern const QLatin1String kmlTag_maxSessionLength;
GEODATA_EXPORT extern const QLatin1String kmlTag_maxWidth;
GEODATA_EXPORT extern const QLatin1String kmlTag_message;
GEODATA_EXPORT extern const QLatin1String kmlTag_Metadata;
GEODATA_EXPORT extern const QLatin1String kmlTag_minAltitude;
GEODATA_EXPORT extern const QLatin1String kmlTag_minFadeExtent;
GEODATA_EXPORT extern const QLatin1String kmlTag_minLodPixels;
GEODATA_EXPORT extern const QLatin1String kmlTag_minRefreshPeriod;
GEODATA_EXPORT extern const QLatin1String kmlTag_Model;
GEODATA_EXPORT extern const QLatin1String kmlTag_MultiGeometry;
GEODATA_EXPORT extern const QLatin1String kmlTag_name;
GEODATA_EXPORT extern const QLatin1String kmlTag_near;
GEODATA_EXPORT extern const QLatin1String kmlTag_NetworkLink;
GEODATA_EXPORT extern const QLatin1String kmlTag_NetworkLinkControl;
GEODATA_EXPORT extern const QLatin1String kmlTag_north;
GEODATA_EXPORT extern const QLatin1String kmlTag_Object;
GEODATA_EXPORT extern const QLatin1String kmlTag_ObjArrayField;
GEODATA_EXPORT extern const QLatin1String kmlTag_ObjField;
GEODATA_EXPORT extern const QLatin1String kmlTag_open;
GEODATA_EXPORT extern const QLatin1String kmlTag_Orientation;
GEODATA_EXPORT extern const QLatin1String kmlTag_OsmPlacemarkData;
GEODATA_EXPORT extern const QLatin1String kmlTag_member;
GEODATA_EXPORT extern const QLatin1String kmlTag_nd;
GEODATA_EXPORT extern const QLatin1String kmlTag_tag;
GEODATA_EXPORT extern const QLatin1String kmlTag_outerBoundaryIs;
GEODATA_EXPORT extern const QLatin1String kmlTag_outline;
GEODATA_EXPORT extern const QLatin1String kmlTag_Overlay;
GEODATA_EXPORT extern const QLatin1String kmlTag_overlayXY;
GEODATA_EXPORT extern const QLatin1String kmlTag_Pair;
GEODATA_EXPORT extern const QLatin1String kmlTag_phoneNumber;
GEODATA_EXPORT extern const QLatin1String kmlTag_PhotoOverlay;
GEODATA_EXPORT extern const QLatin1String kmlTag_Placemark;
GEODATA_EXPORT extern const QLatin1String kmlTag_Point;
GEODATA_EXPORT extern const QLatin1String kmlTag_Polygon;
GEODATA_EXPORT extern const QLatin1String kmlTag_PolyStyle;
GEODATA_EXPORT extern const QLatin1String kmlTag_range;
GEODATA_EXPORT extern const QLatin1String kmlTag_refreshInterval;
GEODATA_EXPORT extern const QLatin1String kmlTag_refreshMode;
GEODATA_EXPORT extern const QLatin1String kmlTag_refreshVisibility;
GEODATA_EXPORT extern const QLatin1String kmlTag_Region;
GEODATA_EXPORT extern const QLatin1String kmlTag_request;
GEODATA_EXPORT extern const QLatin1String kmlTag_ResourceMap;
GEODATA_EXPORT extern const QLatin1String kmlTag_Response;
GEODATA_EXPORT extern const QLatin1String kmlTag_rightFov;
GEODATA_EXPORT extern const QLatin1String kmlTag_roll;
GEODATA_EXPORT extern const QLatin1String kmlTag_rotation;
GEODATA_EXPORT extern const QLatin1String kmlTag_rotationXY;
GEODATA_EXPORT extern const QLatin1String kmlTag_Scale;
GEODATA_EXPORT extern const QLatin1String kmlTag_scale;
GEODATA_EXPORT extern const QLatin1String kmlTag_Schema;
GEODATA_EXPORT extern const QLatin1String kmlTag_SchemaData;
GEODATA_EXPORT extern const QLatin1String kmlTag_SchemaField;
GEODATA_EXPORT extern const QLatin1String kmlTag_ScreenOverlay;
GEODATA_EXPORT extern const QLatin1String kmlTag_screenXY;
GEODATA_EXPORT extern const QLatin1String kmlTag_shape;
GEODATA_EXPORT extern const QLatin1String kmlTag_SimpleArrayData;
GEODATA_EXPORT extern const QLatin1String kmlTag_SimpleArrayField;
GEODATA_EXPORT extern const QLatin1String kmlTag_SimpleField;
GEODATA_EXPORT extern const QLatin1String kmlTag_SimpleData;
GEODATA_EXPORT extern const QLatin1String kmlTag_size;
GEODATA_EXPORT extern const QLatin1String kmlTag_Snippet;
GEODATA_EXPORT extern const QLatin1String kmlTag_south;
GEODATA_EXPORT extern const QLatin1String kmlTag_sourceHref;
GEODATA_EXPORT extern const QLatin1String kmlTag_state;
GEODATA_EXPORT extern const QLatin1String kmlTag_Status;
GEODATA_EXPORT extern const QLatin1String kmlTag_Style;
GEODATA_EXPORT extern const QLatin1String kmlTag_StyleMap;
GEODATA_EXPORT extern const QLatin1String kmlTag_StyleSelector;
GEODATA_EXPORT extern const QLatin1String kmlTag_styleUrl;
GEODATA_EXPORT extern const QLatin1String kmlTag_targetHref;
GEODATA_EXPORT extern const QLatin1String kmlTag_tessellate;
GEODATA_EXPORT extern const QLatin1String kmlTag_text;
GEODATA_EXPORT extern const QLatin1String kmlTag_textColor;
GEODATA_EXPORT extern const QLatin1String kmlTag_tileSize;
GEODATA_EXPORT extern const QLatin1String kmlTag_tilt;
GEODATA_EXPORT extern const QLatin1String kmlTag_TimeSpan;
GEODATA_EXPORT extern const QLatin1String kmlTag_TimeStamp;
GEODATA_EXPORT extern const QLatin1String kmlTag_topFov;
GEODATA_EXPORT extern const QLatin1String kmlTag_Update;
GEODATA_EXPORT extern const QLatin1String kmlTag_Url;
GEODATA_EXPORT extern const QLatin1String kmlTag_value;
GEODATA_EXPORT extern const QLatin1String kmlTag_viewBoundScale;
GEODATA_EXPORT extern const QLatin1String kmlTag_viewFormat;
GEODATA_EXPORT extern const QLatin1String kmlTag_viewRefreshMode;
GEODATA_EXPORT extern const QLatin1String kmlTag_viewRefreshTime;
GEODATA_EXPORT extern const QLatin1String kmlTag_ViewVolume;
GEODATA_EXPORT extern const QLatin1String kmlTag_visibility;
GEODATA_EXPORT extern const QLatin1String kmlTag_w;
GEODATA_EXPORT extern const QLatin1String kmlTag_west;
GEODATA_EXPORT extern const QLatin1String kmlTag_when;
GEODATA_EXPORT extern const QLatin1String kmlTag_width;
GEODATA_EXPORT extern const QLatin1String kmlTag_x;
GEODATA_EXPORT extern const QLatin1String kmlTag_y;
GEODATA_EXPORT extern const QLatin1String kmlTag_z;

// Google KML Extension Namespace (http://code.google.com/apis/kml/documentation/kmlreference.html#kmlextensions)
GEODATA_EXPORT extern const QLatin1String kmlTag_AnimatedUpdate;
GEODATA_EXPORT extern const QLatin1String kmlTag_FlyTo;
GEODATA_EXPORT extern const QLatin1String kmlTag_MultiTrack;
GEODATA_EXPORT extern const QLatin1String kmlTag_Track;
GEODATA_EXPORT extern const QLatin1String kmlTag_coord;
GEODATA_EXPORT extern const QLatin1String kmlTag_delayedStart;
GEODATA_EXPORT extern const QLatin1String kmlTag_SoundCue;
GEODATA_EXPORT extern const QLatin1String kmlTag_Tour;
GEODATA_EXPORT extern const QLatin1String kmlTag_TourControl;
GEODATA_EXPORT extern const QLatin1String kmlTag_Wait;
GEODATA_EXPORT extern const QLatin1String kmlTag_Playlist;
GEODATA_EXPORT extern const QLatin1String kmlTag_playMode;
GEODATA_EXPORT extern const QLatin1String kmlTag_balloonVisibility;
#ifdef KML_LAZY_IMP
// preliminary implementation for the extra defined Tags
GEODATA_EXPORT extern const QLatin1String kmlTag_MarblePlacemark;
GEODATA_EXPORT extern const QLatin1String kmlTag_area;
GEODATA_EXPORT extern const QLatin1String kmlTag_pop;
GEODATA_EXPORT extern const QLatin1String kmlTag_role;
GEODATA_EXPORT extern const QLatin1String kmlTag_CountryNameCode;
GEODATA_EXPORT extern const QLatin1String kmlTag_countrycode;
#endif // KML_LAZY_IMP
}

// Helper macros
#define KML_DEFINE_TAG_HANDLER_20(Name) GEODATA_DEFINE_TAG_HANDLER(kml, Kml, Name, kmlTag_nameSpace20)
#define KML_DEFINE_TAG_HANDLER_21(Name) GEODATA_DEFINE_TAG_HANDLER(kml, Kml, Name, kmlTag_nameSpace21)
#define KML_DEFINE_TAG_HANDLER_22(Name) GEODATA_DEFINE_TAG_HANDLER(kml, Kml, Name, kmlTag_nameSpace22)
#define KML_DEFINE_TAG_HANDLER_OGC22(Name) GEODATA_DEFINE_TAG_HANDLER(kml, Kml, Name, kmlTag_nameSpaceOgc22)
#define KML_DEFINE_TAG_HANDLER_GX22(Name) GEODATA_DEFINE_TAG_HANDLER(kml, Kml, Name, kmlTag_nameSpaceGx22)
#define KML_DEFINE_TAG_HANDLER_MX(Name) GEODATA_DEFINE_TAG_HANDLER(kml, Kml, Name, kmlTag_nameSpaceMx)

#define KML_DEFINE_TAG_HANDLER(Name) \
        KML_DEFINE_TAG_HANDLER_20(Name) \
        KML_DEFINE_TAG_HANDLER_21(Name) \
        KML_DEFINE_TAG_HANDLER_22(Name) \
        KML_DEFINE_TAG_HANDLER_OGC22(Name)

}

#endif
