//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2015-2026 Alexander Barthel alex@littlenavmap.org
//

#ifndef COMPASS_FLOAT_ITEM_H
#define COMPASS_FLOAT_ITEM_H

#include <QPixmap>

#include "AbstractFloatItem.h"
#include "DialogConfigurationInterface.h"

class QSvgRenderer;

namespace Ui {

class LabelFloatItemConfigWidget;
class CompassConfigWidget;
}

namespace Marble {

/**
 * @short Shows a HTML label as floating item.
 * Text, tooltip and colors are set in MarbleWidget::setLabelText().
 */

class LabelFloatItem :
  public AbstractFloatItem, public DialogConfigurationInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.kde.marble.LabelFloatItem")
  Q_INTERFACES(Marble::RenderPluginInterface)
  Q_INTERFACES(Marble::DialogConfigurationInterface)
  MARBLE_PLUGIN(LabelFloatItem)

public:
  LabelFloatItem();
  explicit LabelFloatItem(const MarbleModel *marbleModel);
  ~LabelFloatItem();

  /* Set HTML label and tooltip text. Colors are for label. */
  virtual void setText(const QString& textParam, const QString& tooltipTextParam, QColor foregroundParam, QColor backgroundParam) override;

  virtual QStringList backendTypes() const override;
  virtual QString name() const override;
  virtual QString guiString() const override;
  virtual QString nameId() const override;
  virtual QString version() const override;
  virtual QString description() const override;
  virtual QString copyrightYears() const override;
  virtual QList<PluginAuthor> pluginAuthors() const override;
  virtual QIcon icon() const override;

  /* Required to enable installation of event filter. */
  virtual void initialize()  override;
  virtual bool isInitialized() const override;

  virtual void paintContent(QPainter *painter)  override;
  virtual QHash<QString, QVariant> settings() const override;
  virtual void setSettings(const QHash<QString, QVariant>& settings)  override;
  virtual QDialog *configDialog() override;
  virtual void toolTipEvent(QHelpEvent *event) override;

private Q_SLOTS:
  void updateSettings();
  void readSettings();
  void writeSettings();

private:
  Q_DISABLE_COPY(LabelFloatItem)

  QString text, tooltipText;
  QColor foreground, background;

  QSizeF m_defaultSize;
  int m_defaultFontScale;

  bool m_isInitialized;

  Ui::LabelFloatItemConfigWidget *ui_configWidget = nullptr;
  QDialog *m_configDialog = nullptr;

  QHash<QString, QVariant> m_settings;
};
}

#endif
