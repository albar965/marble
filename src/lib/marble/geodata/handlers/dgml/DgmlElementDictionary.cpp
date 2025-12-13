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

#include "DgmlElementDictionary.h"

#include <QLatin1String>

namespace Marble {

// One static list of all tag names, to avoid string comparisons all-over-the-place
namespace dgml {

const QLatin1String dgmlTag_nameSpace20("http://edu.kde.org/marble/dgml/2.0");

const QLatin1String dgmlTag_Available("available");
const QLatin1String dgmlTag_Blending("blending");
const QLatin1String dgmlTag_Brush("brush");
const QLatin1String dgmlTag_Color("color");
const QLatin1String dgmlTag_CustomPlugin("customplugin");
const QLatin1String dgmlTag_Dem("dem");
const QLatin1String dgmlTag_Description("description");
const QLatin1String dgmlTag_Dgml("dgml");
const QLatin1String dgmlTag_Discrete("discrete");
const QLatin1String dgmlTag_Document("document");
const QLatin1String dgmlTag_DownloadPolicy("downloadPolicy");
const QLatin1String dgmlTag_DownloadUrl("downloadUrl");
const QLatin1String dgmlTag_Filter("filter");
const QLatin1String dgmlTag_Geodata("geodata");
const QLatin1String dgmlTag_Group("group");
const QLatin1String dgmlTag_Head("head");
const QLatin1String dgmlTag_Heading("heading");
const QLatin1String dgmlTag_Icon("icon");
const QLatin1String dgmlTag_InstallMap("installmap");
const QLatin1String dgmlTag_Item("item");
const QLatin1String dgmlTag_Layer("layer");
const QLatin1String dgmlTag_Legend("legend");
const QLatin1String dgmlTag_License("license");
const QLatin1String dgmlTag_Map("map");
const QLatin1String dgmlTag_Maximum("maximum");
const QLatin1String dgmlTag_Minimum("minimum");
const QLatin1String dgmlTag_Name("name");
const QLatin1String dgmlTag_Palette("palette");
const QLatin1String dgmlTag_Pen("pen");
const QLatin1String dgmlTag_Projection("projection");
const QLatin1String dgmlTag_Property("property");
const QLatin1String dgmlTag_Section("section");
const QLatin1String dgmlTag_Settings("settings");
const QLatin1String dgmlTag_SourceDir("sourcedir");
const QLatin1String dgmlTag_SourceFile("sourcefile");
const QLatin1String dgmlTag_StorageLayout("storageLayout");
const QLatin1String dgmlTag_Target("target");
const QLatin1String dgmlTag_Text("text");
const QLatin1String dgmlTag_Texture("texture");
const QLatin1String dgmlTag_Theme("theme");
const QLatin1String dgmlTag_TileSize("tileSize");
const QLatin1String dgmlTag_Value("value");
const QLatin1String dgmlTag_Vector("vector");
const QLatin1String dgmlTag_Vectortile("vectortile");
const QLatin1String dgmlTag_Visible("visible");
const QLatin1String dgmlTag_Zoom("zoom");
const QLatin1String dgmlTag_RenderOrder("renderOrder");
}
}
