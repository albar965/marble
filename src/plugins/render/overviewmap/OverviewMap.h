//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2008 Torsten Rahn <tackat@kde.org>
//

#ifndef MARBLEOVERVIEWMAP_H
#define MARBLEOVERVIEWMAP_H

#include <QHash>
#include <QColor>
#include <QPixmap>
#include <QSvgRenderer>
#include <QtSvgWidgets/QSvgWidget>

#include "GeoDataLatLonAltBox.h"
#include "AbstractFloatItem.h"
#include "DialogConfigurationInterface.h"

namespace Ui {
class OverviewMapConfigWidget;
}

namespace Marble {

/**
 * @short The class that creates an overview map.
 *
 */

class OverviewMap :
  public AbstractFloatItem, public DialogConfigurationInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.kde.marble.OverviewMap")
  Q_INTERFACES(Marble::RenderPluginInterface)
  Q_INTERFACES(Marble::DialogConfigurationInterface)
  MARBLE_PLUGIN(OverviewMap)

public:
  OverviewMap();
  explicit OverviewMap(const MarbleModel *marbleModel);
  virtual ~OverviewMap();

  virtual QStringList backendTypes() const override;
  virtual QString name() const override;
  virtual QString guiString() const override;
  virtual QString nameId() const override;
  virtual QString version() const override;
  virtual QString description() const override;
  virtual QString copyrightYears() const override;
  virtual QList<PluginAuthor> pluginAuthors() const override;
  virtual QIcon icon() const override;
  virtual QDialog *configDialog() override;
  virtual void initialize() override;
  virtual bool isInitialized() const override;
  virtual void setProjection(const ViewportParams *viewport) override;
  virtual void paintContent(QPainter *painter) override;

  /**
   * @return: The settings of the item.
   */
  virtual QHash<QString, QVariant> settings() const override;

  /**
   * Set the settings of the item.
   */
  virtual void setSettings(const QHash<QString, QVariant>& settings) override;

public Q_SLOTS:
  void readSettings();
  void writeSettings();
  void updateSettings();

private:
  void changeBackground(const QString& target);

  QString m_target;
  QSvgRenderer m_svgobj;
  QHash<QString, QSvgWidget *> m_svgWidgets;
  QString m_planetID;
  QString svgPath;
  QPixmap m_worldmap;
  QHash<QString, QVariant> m_settings;
  QColor m_posColor;
  QSizeF m_defaultSize;

  Ui::OverviewMapConfigWidget *ui_configWidget;
  QDialog *m_configDialog;

  GeoDataLatLonAltBox m_latLonAltBox;
  qreal m_centerLat;
  qreal m_centerLon;
  bool m_mapChanged;

private Q_SLOTS:
  void synchronizeSpinboxes();
  void choosePositionIndicatorColor();

};

}

#endif
