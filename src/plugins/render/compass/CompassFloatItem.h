//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2008 Torsten Rahn <tackat@kde.org>
//

#ifndef COMPASS_FLOAT_ITEM_H
#define COMPASS_FLOAT_ITEM_H

#include <QPixmap>

#include "AbstractFloatItem.h"
#include "DialogConfigurationInterface.h"

class QSvgRenderer;

namespace Ui {
class CompassConfigWidget;
}

namespace Marble {

/**
 * @short The class that creates a compass
 *
 */

class CompassFloatItem :
  public AbstractFloatItem, public DialogConfigurationInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.kde.marble.CompassFloatItem")
  Q_INTERFACES(Marble::RenderPluginInterface)
  Q_INTERFACES(Marble::DialogConfigurationInterface)
  MARBLE_PLUGIN(CompassFloatItem)

public:
  CompassFloatItem();
  explicit CompassFloatItem(const MarbleModel *marbleModel);
  ~CompassFloatItem();

  virtual QStringList backendTypes() const override;
  virtual QString name() const override;
  virtual QString guiString() const override;
  virtual QString nameId() const override;
  virtual QString version() const override;
  virtual QString description() const override;
  virtual QString copyrightYears() const override;
  virtual QList<PluginAuthor> pluginAuthors() const override;
  virtual QIcon icon() const override;
  virtual void initialize()  override;
  virtual bool isInitialized() const override;
  virtual QPainterPath backgroundShape() const override;
  virtual void setProjection(const ViewportParams *viewport)  override;
  virtual void paintContent(QPainter *painter)  override;
  virtual QDialog *configDialog()  override;
  virtual QHash<QString, QVariant> settings() const override;
  virtual void setSettings(const QHash<QString, QVariant>& settings)  override;

private Q_SLOTS:
  void readSettings();

  void writeSettings();

private:
  Q_DISABLE_COPY(CompassFloatItem)

  bool m_isInitialized;

  QSvgRenderer *m_svgobj;
  QPixmap m_compass;

  /// allowed values: -1, 0, 1; default here: 0. FIXME: Declare enum
  int m_polarity;
};
}

#endif
