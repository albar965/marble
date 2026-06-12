//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009 Henry de Valence <hdevalence@gmail.com>
// Copyright 2009 David Roberts <dvdr18@gmail.com>
// Copyright 2012 Mohammed Nafees <nafees.technocool@gmail.com>
// Copyright 2014 Dennis Nienhüser <nienhueser@kde.org>

#include "PlanetFactory.h"
#include "MarbleColors.h"
#include "Planet.h"
#include "MarbleDebug.h"
#include "MarbleGlobal.h"

#include <QObject>

namespace Marble {

QList<QString> PlanetFactory::planetList()
{
  QStringList planets;

  planets << "earth";

  return planets;
}

Planet PlanetFactory::construct(const QString& id)
{
  Planet planet;
  planet.setId(id);

  // constants taken from http://aa.quae.nl/en/reken/zonpositie.html

  if(id == "earth")
  {
    planet.setM_0(357.5291 * DEG2RAD);
    planet.setM_1(0.98560028 * DEG2RAD);
    planet.setC_1(1.9148 * DEG2RAD);
    planet.setC_2(0.0200 * DEG2RAD);
    planet.setC_3(0.0003 * DEG2RAD);
    planet.setC_4(0);
    planet.setC_5(0);
    planet.setC_6(0);
    planet.setPi(102.9372 * DEG2RAD);
    planet.setEpsilon(23.45 * DEG2RAD);
    planet.setTheta_0(280.1600 * DEG2RAD);
    planet.setTheta_1(360.9856235 * DEG2RAD);
    planet.setRadius(6378137.0);
    planet.setName("Earth");
    planet.setHasAtmosphere(true);
    planet.setAtmosphereColor(Qt::white);
  }

  return planet;
}

QString PlanetFactory::localizedName(const QString& id)
{
  if(id == "earth")
  {
    return QObject::tr("Earth", "the planet");
  }
  else if(id.isEmpty())
  {
    mDebug() << "Warning: empty id";
    return QObject::tr("Unknown Planet", "a planet without data");
  }

  return id;
}

}
