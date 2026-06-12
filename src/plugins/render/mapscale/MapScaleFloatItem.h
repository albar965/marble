//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2008 Torsten Rahn <tackat@kde.org>
//

#ifndef MAPSCALEFLOATITEM_H
#define MAPSCALEFLOATITEM_H

#include "AbstractFloatItem.h"
#include "DialogConfigurationInterface.h"

namespace Marble {

/**
 * @short The class that creates a map scale.
 *
 */

class MapScaleFloatItem :
  public AbstractFloatItem, public DialogConfigurationInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.kde.marble.MapScaleFloatItem")
  Q_INTERFACES(Marble::RenderPluginInterface)
  Q_INTERFACES(Marble::DialogConfigurationInterface)
  MARBLE_PLUGIN(MapScaleFloatItem)

public:
  explicit MapScaleFloatItem(const MarbleModel *marbleModel = 0);
  ~MapScaleFloatItem();

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
  virtual void setProjection(const ViewportParams *viewport)  override;
  virtual void paintContent(QPainter *painter)  override;
  virtual QDialog *configDialog()  override;

  /**
   * @return: The settings of the item.
   */
  virtual QHash<QString, QVariant> settings() const override;

  /**
   * Set the settings of the item.
   */
  virtual void setSettings(const QHash<QString, QVariant>& settings) override;

protected:
  virtual void contextMenuEvent(QWidget *w, QContextMenuEvent *e) override;

private Q_SLOTS:
  void readSettings();
  void writeSettings();
  void toggleRatioScaleVisibility();
  void toggleMinimized(bool checked);

private:
  void calcScaleBar();

private:

  int m_radius;

  QString m_target;

  int m_leftBarMargin;
  int m_rightBarMargin;
  int m_scaleBarWidth;
  int m_viewportWidth;
  int m_scaleBarHeight;
  qreal m_scaleBarDistance;

  qreal m_pixel2Length;
  int m_bestDivisor;
  int m_pixelInterval;
  int m_valueInterval;

  bool m_scaleInitDone;

  QMenu *m_contextMenu;

  QAction *m_minimizeAction;
  bool m_minimized;
  int m_widthScaleFactor; // Width of view port / factor = content size
};

}

#endif // MAPSCALEFLOATITEM_H
