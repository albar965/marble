//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2012 Thibaut Gridel <tgridel@free.fr>

#ifndef GEODATAMULTITRACK_H
#define GEODATAMULTITRACK_H

#include "geodata_export.h"

#include "GeoDataGeometry.h"

#include <QList>

namespace Marble {

class GeoDataMultiTrackPrivate;
class GeoDataTrack;

class GEODATA_EXPORT GeoDataMultiTrack :
  public GeoDataGeometry
{
public:
  GeoDataMultiTrack();
  explicit GeoDataMultiTrack(const GeoDataGeometry& other);

  virtual ~GeoDataMultiTrack();

  bool operator==(const GeoDataMultiTrack& other) const;
  bool operator!=(const GeoDataMultiTrack& other) const;

  virtual const GeoDataLatLonAltBox& latLonAltBox() const;

  int size() const;
  GeoDataTrack& at(int pos);
  const GeoDataTrack& at(int pos) const;
  GeoDataTrack& operator[](int pos);
  const GeoDataTrack& operator[](int pos) const;

  GeoDataTrack& first();
  const GeoDataTrack& first() const;
  GeoDataTrack& last();
  const GeoDataTrack& last() const;

  /**
   * @brief  returns the requested child item
   */
  GeoDataTrack *child(int);

  /**
   * @brief  returns the requested child item
   */
  const GeoDataTrack *child(int) const;

  /**
   * @brief returns the position of an item in the list
   */
  int childPosition(const GeoDataTrack *child) const;

  /**
  * @brief add an element
  */
  void append(GeoDataTrack *other);

  GeoDataMultiTrack& operator<<(const GeoDataTrack& value);

  QList<GeoDataTrack *>::Iterator begin();
  QList<GeoDataTrack *>::Iterator end();
  QList<GeoDataTrack *>::ConstIterator constBegin() const;
  QList<GeoDataTrack *>::ConstIterator constEnd() const;
  void clear();
  QList<GeoDataTrack> vector() const;

  QList<GeoDataTrack *>::Iterator erase(QList<GeoDataTrack *>::Iterator pos);
  QList<GeoDataTrack *>::Iterator erase(QList<GeoDataTrack *>::Iterator begin,
                                          QList<GeoDataTrack *>::Iterator end);

  // Serialize the Placemark to @p stream
  virtual void pack(QDataStream& stream) const;

  // Unserialize the Placemark from @p stream
  virtual void unpack(QDataStream& stream);

private:
  GeoDataMultiTrackPrivate *p();
  const GeoDataMultiTrackPrivate *p() const;

};

}

#endif // GEODATAMULTITRACK_H
