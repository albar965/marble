//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2010-2012 Bernhard Beschow <bbeschow@cs.tu-berlin.de>
// Copyright 2011      Jens-Michael Hoffmann <jmho@c-xx.com>
//

#ifndef MARBLE_ATMOSPHEREPLUGIN_H
#define MARBLE_ATMOSPHEREPLUGIN_H

#include "RenderPlugin.h"

#include <QPixmap>

namespace Marble {

class AtmospherePlugin :
  public RenderPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.kde.marble.AtmospherePlugin")
  Q_INTERFACES(Marble::RenderPluginInterface)
  MARBLE_PLUGIN(AtmospherePlugin)

public:
  AtmospherePlugin();

  explicit AtmospherePlugin(const MarbleModel *marbleModel);

  virtual QStringList backendTypes() const override;
  virtual QString renderPolicy() const override;
  virtual QStringList renderPosition() const override;
  virtual RenderType renderType() const override;
  virtual QString name() const override;
  virtual QString guiString() const override;
  virtual QString nameId() const override;
  virtual QString version() const override;
  virtual QString description() const override;
  virtual QIcon icon() const override;
  virtual QString copyrightYears() const override;
  virtual QList<PluginAuthor> pluginAuthors() const override;
  virtual qreal zValue() const override;
  virtual void initialize() override;
  virtual bool isInitialized() const override;

  virtual bool render(GeoPainter *painter, ViewportParams *viewport, const QString& renderPos, GeoSceneLayer *layer = 0) override;
  void repaintPixmap(const ViewportParams *viewParams);

public Q_SLOTS:
  void updateTheme();

private:
  QPixmap m_renderPixmap;
  QColor m_renderColor;
  int m_renderRadius;
};

}

#endif // MARBLE_ATMOSPHEREPLUGIN_H
