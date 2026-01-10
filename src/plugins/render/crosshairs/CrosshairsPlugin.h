//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2008 Torsten Rahn <tackat@kde.org>
// Copyright 2010 Cezar Mocan <mocancezar@gmail.com>
//

//
// This class is a crosshairs plugin.
//

#ifndef MARBLE_CROSSHAIRSPLUGIN_H
#define MARBLE_CROSSHAIRSPLUGIN_H

#include <QPixmap>

#include "RenderPlugin.h"
#include "DialogConfigurationInterface.h"

class QSvgRenderer;

namespace Ui {
class CrosshairsConfigWidget;
}

namespace Marble {

/**
 * @short The class that specifies the Marble layer interface of a plugin.
 *
 */

class CrosshairsPlugin :
  public RenderPlugin, public DialogConfigurationInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.kde.marble.CrosshairsPlugin")
  Q_INTERFACES(Marble::RenderPluginInterface)
  Q_INTERFACES(Marble::DialogConfigurationInterface)
  MARBLE_PLUGIN(CrosshairsPlugin)

public:
  CrosshairsPlugin();

  explicit CrosshairsPlugin(const MarbleModel *marbleModel);

  ~CrosshairsPlugin();

  virtual QStringList backendTypes() const override;
  virtual QString renderPolicy() const override;
  virtual QStringList renderPosition() const override;
  virtual RenderType renderType() const override;
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
  virtual bool render(GeoPainter *painter, ViewportParams *viewport, const QString& renderPos, GeoSceneLayer *layer = 0)  override;
  virtual QDialog *configDialog()  override;
  virtual QHash<QString, QVariant> settings() const override;
  virtual void setSettings(const QHash<QString, QVariant>& settings)  override;

private Q_SLOTS:
  void readSettings();

  void writeSettings();

private:
  Q_DISABLE_COPY(CrosshairsPlugin)

  bool m_isInitialized;

  QSvgRenderer *m_svgobj;
  QPixmap m_crosshairs;
  int m_themeIndex;

  QString m_theme;

  QDialog *m_configDialog;
  Ui::CrosshairsConfigWidget *m_uiConfigWidget;
};

}

#endif // MARBLE_CROSSHAIRSPLUGIN_H
