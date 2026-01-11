//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2012 Dennis Nienhüser <nienhueser@kde.org>
// Copyright 2012 Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

#ifndef MARBLELICENSE_H
#define MARBLELICENSE_H

#include "AbstractFloatItem.h"

class QLabel;

namespace Marble {

class GeoDataCoordinates;
class WidgetGraphicsItem;
class MarbleLocale;

/**
 * @short The class that displays copyright info
 *
 */

class License :
  public AbstractFloatItem
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.kde.marble.License")
  Q_INTERFACES(Marble::RenderPluginInterface)
  MARBLE_PLUGIN(License)

public:
  explicit License(const MarbleModel *marbleModel = 0);
  ~License();

  virtual QStringList backendTypes() const override;
  virtual QString name() const override;
  virtual QString guiString() const override;
  virtual QString nameId() const override;
  virtual QString version() const override;
  virtual QString description() const override;
  virtual QString copyrightYears() const override;
  virtual QList<PluginAuthor> pluginAuthors() const override;
  virtual QIcon icon() const override;
  virtual void initialize() override;
  virtual bool isInitialized() const override;

private Q_SLOTS:
  void updateLicenseText();
  void toggleLicenseSize();
  void showAboutDialog();

protected:
  virtual bool eventFilter(QObject *, QEvent *e) override;
  virtual void contextMenuEvent(QWidget *w, QContextMenuEvent *e) override;

private:
  WidgetGraphicsItem *m_widgetItem;
  QLabel *m_label;
  bool m_showFullLicense;
  QMenu *m_contextMenu;
};

}

#endif
