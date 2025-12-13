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

#ifndef MARBLE_DGML_ELEMENTDICTIONARY_H
#define MARBLE_DGML_ELEMENTDICTIONARY_H

#include <QLatin1String>
#include <geodata_export.h>

namespace Marble {

// Lists all known DGML 2.0 tags
// http://edu.kde.org/marble/apis/dgml/documentation/dgmltags.html)
namespace dgml {
GEODATA_EXPORT extern const QLatin1String dgmlTag_nameSpace20;

extern const QLatin1String dgmlTag_Available;
extern const QLatin1String dgmlTag_Blending;
extern const QLatin1String dgmlTag_Brush;
extern const QLatin1String dgmlTag_Color;
extern const QLatin1String dgmlTag_CustomPlugin;
extern const QLatin1String dgmlTag_Dem;
extern const QLatin1String dgmlTag_Description;
extern const QLatin1String dgmlTag_Discrete;
extern const QLatin1String dgmlTag_Dgml;
extern const QLatin1String dgmlTag_Document;
extern const QLatin1String dgmlTag_DownloadPolicy;
extern const QLatin1String dgmlTag_DownloadUrl;
extern const QLatin1String dgmlTag_Filter;
extern const QLatin1String dgmlTag_Geodata;
extern const QLatin1String dgmlTag_Group;
extern const QLatin1String dgmlTag_Head;
extern const QLatin1String dgmlTag_Heading;
extern const QLatin1String dgmlTag_Icon;
extern const QLatin1String dgmlTag_InstallMap;
extern const QLatin1String dgmlTag_Item;
extern const QLatin1String dgmlTag_Layer;
extern const QLatin1String dgmlTag_Legend;
extern const QLatin1String dgmlTag_License;
extern const QLatin1String dgmlTag_Map;
extern const QLatin1String dgmlTag_Maximum;
extern const QLatin1String dgmlTag_Minimum;
extern const QLatin1String dgmlTag_Name;
extern const QLatin1String dgmlTag_Palette;
extern const QLatin1String dgmlTag_Pen;
extern const QLatin1String dgmlTag_Projection;
extern const QLatin1String dgmlTag_Property;
extern const QLatin1String dgmlTag_Section;
extern const QLatin1String dgmlTag_Settings;
extern const QLatin1String dgmlTag_SourceDir;
extern const QLatin1String dgmlTag_SourceFile;
extern const QLatin1String dgmlTag_StorageLayout;
extern const QLatin1String dgmlTag_Target;
extern const QLatin1String dgmlTag_Text;
extern const QLatin1String dgmlTag_Texture;
extern const QLatin1String dgmlTag_TileSize;
extern const QLatin1String dgmlTag_Theme;
extern const QLatin1String dgmlTag_Value;
extern const QLatin1String dgmlTag_Vector;
extern const QLatin1String dgmlTag_Vectortile;
extern const QLatin1String dgmlTag_Visible;
extern const QLatin1String dgmlTag_Zoom;
extern const QLatin1String dgmlTag_RenderOrder;
}

// Helper macro
#define DGML_DEFINE_TAG_HANDLER(Name) GEODATA_DEFINE_TAG_HANDLER(dgml, Dgml, Name, dgmlTag_nameSpace20)

}

#endif
