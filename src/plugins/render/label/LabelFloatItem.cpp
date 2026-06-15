//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2015-2026 Alexander Barthel alex@littlenavmap.org
//

#include "LabelFloatItem.h"

#include "MarbleDirs.h"
#include "ui_LabelFloatItemConfigWidget.h"

#include <QRect>
#include <QColor>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QSvgRenderer>
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>
#include <QDialog>
#include <QToolTip>

namespace Marble {

LabelFloatItem::LabelFloatItem()
  : AbstractFloatItem(0)
{
}

LabelFloatItem::LabelFloatItem(const MarbleModel *marbleModel)
  : AbstractFloatItem(marbleModel, QPointF(155., 1.), QSizeF(300.0, 70.0)),
  foreground(Qt::black), background(255, 255, 255, 200), m_defaultSize(AbstractFloatItem::size()),
  m_defaultFontScale(100), m_isInitialized(false)
{
  setMargin(0);
  setPadding(0);

  connect(this, SIGNAL(settingsChanged(QString)), this, SLOT(updateSettings()));

  configDialog();
  restoreDefaultSettings();
}

LabelFloatItem::~LabelFloatItem()
{
}

void LabelFloatItem::setText(const QString& textParam, const QString& tooltipTextParam, QColor foregroundParam, QColor backgroundParam)
{
  if(text != textParam || foreground != foregroundParam || background != backgroundParam)
  {
    foreground = foregroundParam;
    background = backgroundParam;
    text = textParam;
    update();
  }

  tooltipText = tooltipTextParam;
}

QStringList LabelFloatItem::backendTypes() const
{
  return QStringList("label");
}

QString LabelFloatItem::name() const
{
  return tr("Label");
}

QString LabelFloatItem::guiString() const
{
  return tr("&Label");
}

QString LabelFloatItem::nameId() const
{
  return QString("label");
}

QString LabelFloatItem::version() const
{
  return "1.0";
}

QString LabelFloatItem::description() const
{
  return tr("This is a float item that provides a label showing HTML text.");
}

QString LabelFloatItem::copyrightYears() const
{
  return "2026";
}

QList<PluginAuthor> LabelFloatItem::pluginAuthors() const
{
  return QList<PluginAuthor>()
         << PluginAuthor("Alexander Barthel", "alex@littlenavmap.org");
}

QIcon LabelFloatItem::icon() const
{
  return QIcon(":/icons/document-import.png");
}

QDialog *LabelFloatItem::configDialog()
{
  if(!m_configDialog)
  {
    // Initializing configuration dialog
    m_configDialog = new QDialog();
    ui_configWidget = new Ui::LabelFloatItemConfigWidget;
    ui_configWidget->setupUi(m_configDialog);
    m_configDialog->setWindowTitle(tr("%1 - Help Label Configuration").arg(QApplication::applicationName()));
    connect(ui_configWidget->m_buttonBox, SIGNAL(accepted()), SLOT(writeSettings()));
    connect(ui_configWidget->m_buttonBox, SIGNAL(rejected()), SLOT(readSettings()));
    connect(ui_configWidget->m_buttonBox->button(QDialogButtonBox::Reset), SIGNAL(clicked()), SLOT(restoreDefaultSettings()));

    QPushButton *applyButton = ui_configWidget->m_buttonBox->button(QDialogButtonBox::Apply);
    connect(applyButton, SIGNAL(clicked()), SLOT(writeSettings()));
  }

  readSettings();

  return m_configDialog;
}

void LabelFloatItem::initialize()
{
  readSettings();
  m_isInitialized = true;
}

bool LabelFloatItem::isInitialized() const
{
  return m_isInitialized;
}

void LabelFloatItem::paintContent(QPainter *painter)
{
  painter->save();

  // Adjust font based on scale and make it a bit smaller
  QFont font = painter->font();
  font.setPointSizeF(font.pointSizeF() * ui_configWidget->m_spinBoxFontSize->value() / 100. * 0.9);

  QTextDocument textDocument;
  textDocument.setDefaultFont(font);
  textDocument.setUndoRedoEnabled(false);
  textDocument.setTextWidth(contentRect().width()); // Needed for word wrap

  // Enable word wrap
  QTextOption textOption = textDocument.defaultTextOption();
  textOption.setWrapMode(QTextOption::WordWrap);
  textDocument.setDefaultTextOption(textOption);

  // Set document text
  textDocument.setHtml(text);

  // QAbstractTextDocumentLayout *layout = textDocument.documentLayout();
  // QRectF rect = layout->frameBoundingRect(textDocument.rootFrame());
  // qDebug() << Q_FUNC_INFO << rect << contentRect().contains(rect);

  // Draw background rectangle a bit smaller than the content rect
  painter->setPen(Qt::transparent);
  painter->setBackground(background);
  painter->setBrush(background);
  painter->setBackgroundMode(Qt::OpaqueMode);
  painter->drawRect(contentRect().marginsRemoved(QMarginsF(2., 2., 2., 2.)));

  // Set document foreground color
  painter->setBackgroundMode(Qt::TransparentMode);
  QAbstractTextDocumentLayout::PaintContext ctx;
  ctx.palette.setColor(QPalette::Text, foreground);

  // Draw to painter
  textDocument.documentLayout()->draw(painter, ctx);

  painter->restore();
}

QHash<QString, QVariant> LabelFloatItem::settings() const
{
  QHash<QString, QVariant> result = AbstractFloatItem::settings();

  typedef QHash<QString, QVariant>::ConstIterator Iterator;
  Iterator end = m_settings.constEnd();
  for( Iterator iter = m_settings.constBegin(); iter != end; ++iter )
    result.insert(iter.key(), iter.value());

  return result;
}

void LabelFloatItem::setSettings(const QHash<QString, QVariant>& settings)
{
  AbstractFloatItem::setSettings(settings);

  m_settings.insert("width", settings.value("width", m_defaultSize.toSize().width()));
  m_settings.insert("height", settings.value("height", m_defaultSize.toSize().height()));
  m_settings.insert("fontscale", settings.value("fontscale", m_defaultFontScale));

  readSettings();
  emit settingsChanged(nameId());
}

void LabelFloatItem::readSettings()
{
  if(!m_configDialog)
    return;

  ui_configWidget->m_widthBox->setValue(m_settings.value("width").toInt());
  ui_configWidget->m_heightBox->setValue(m_settings.value("height").toInt());
  ui_configWidget->m_spinBoxFontSize->setValue(m_settings.value("fontscale").toInt());
}

void LabelFloatItem::writeSettings()
{
  if(!m_configDialog)
    return;

  m_settings.insert("width", ui_configWidget->m_widthBox->value());
  m_settings.insert("height", ui_configWidget->m_heightBox->value());
  m_settings.insert("fontscale", ui_configWidget->m_spinBoxFontSize->value());

  emit settingsChanged(nameId());

  update();
}

void LabelFloatItem::updateSettings()
{
  if(!m_configDialog)
    return;

  setContentSize(QSizeF(ui_configWidget->m_widthBox->value(), ui_configWidget->m_heightBox->value()));
}

void LabelFloatItem::toolTipEvent(QHelpEvent *event)
{
  if(event->type() == QEvent::ToolTip && !tooltipText.isEmpty())
    QToolTip::showText(event->globalPos(), tooltipText);
}

}

#include "moc_LabelFloatItem.cpp"
