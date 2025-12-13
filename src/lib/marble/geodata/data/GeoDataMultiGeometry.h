//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2008      Patrick Spendrin <ps_ml@gmx.de>
//

#ifndef MARBLE_GEODATAMULTIGEOMETRY_H
#define MARBLE_GEODATAMULTIGEOMETRY_H

#include "geodata_export.h"

#include "GeoDataGeometry.h"
#include <QList>

namespace Marble {

/**
 * @short A class that can contain other GeoDataGeometry objects
 *
 * GeoDataMultiGeometry is a collection of other GeoDataGeometry objects.
 * As one can add GeoDataMultiGeometry to itself, you can make up a collection
 * of different objects to form one Placemark.
 */
class GeoDataMultiGeometryPrivate;

class GEODATA_EXPORT GeoDataMultiGeometry :
  public GeoDataGeometry
{
public:
  GeoDataMultiGeometry();
  explicit GeoDataMultiGeometry(const GeoDataGeometry& other);

  virtual ~GeoDataMultiGeometry();

  virtual const GeoDataLatLonAltBox& latLonAltBox() const;

  int size() const;
  GeoDataGeometry& at(int pos);
  const GeoDataGeometry& at(int pos) const;
  GeoDataGeometry& operator[](int pos);
  const GeoDataGeometry& operator[](int pos) const;

  GeoDataGeometry& first();
  const GeoDataGeometry& first() const;
  GeoDataGeometry& last();
  const GeoDataGeometry& last() const;

  /**
   * @brief  returns the requested child item
   */
  GeoDataGeometry *child(int);

  /**
   * @brief  returns the requested child item
   */
  const GeoDataGeometry *child(int) const;

  /**
   * @brief returns the position of an item in the list
   */
  int childPosition(const GeoDataGeometry *child) const;

  /**
  * @brief add an element
  */
  void append(GeoDataGeometry *other);

  GeoDataMultiGeometry& operator<<(const GeoDataGeometry& value);

  QList<GeoDataGeometry *>::Iterator begin();
  QList<GeoDataGeometry *>::Iterator end();
  QList<GeoDataGeometry *>::ConstIterator constBegin() const;
  QList<GeoDataGeometry *>::ConstIterator constEnd() const;
  void clear();
  QList<GeoDataGeometry> vector() const;

  QList<GeoDataGeometry *>::Iterator erase(QList<GeoDataGeometry *>::Iterator pos);
  QList<GeoDataGeometry *>::Iterator erase(QList<GeoDataGeometry *>::Iterator begin,
                                             QList<GeoDataGeometry *>::Iterator end);

  // Serialize the Placemark to @p stream
  virtual void pack(QDataStream& stream) const;

  // Unserialize the Placemark from @p stream
  virtual void unpack(QDataStream& stream);

private:
  GeoDataMultiGeometryPrivate *p();
  const GeoDataMultiGeometryPrivate *p() const;

};

}

#endif
