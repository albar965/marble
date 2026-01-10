// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2006-2007 Torsten Rahn <tackat@kde.org>
// Copyright 2007      Inge Wallin  <ingwa@kde.org>
// Copyright 2014      Adam Dabrowski <adamdbrw@gmail.com>
//

#include "MarbleWidgetInputHandler.h"

#include <QRubberBand>
#include <QToolTip>
#include <QTimer>
#include <QKeyEvent>

#include "MarbleGlobal.h"
#include "MarbleDebug.h"
#include "MarbleWidget.h"
#include "AbstractDataPluginItem.h"
#include "RenderPlugin.h"

namespace Marble {

class MarbleWidgetInputHandlerPrivate
{
public:
  MarbleWidgetInputHandlerPrivate(MarbleWidgetInputHandler *handler, MarbleWidget *widget)
    : m_inputHandler(handler)
    , m_marbleWidget(widget)
    , m_debugModeEnabled(false)
  {
    foreach(RenderPlugin * renderPlugin, widget->renderPlugins())
    {
      if(renderPlugin->isInitialized())
      {
        installPluginEventFilter(renderPlugin);
      }
    }
    m_marbleWidget->grabGesture(Qt::PinchGesture);
  }

  void setCursor(const QCursor& cursor)
  {
    m_marbleWidget->setCursor(cursor);
  }

  bool layersEventFilter(QObject *, QEvent *)
  {         // FIXME - this should go up in hierarchy to MarbleInputHandler
    return false;
  }

  void installPluginEventFilter(RenderPlugin *renderPlugin)
  {
    m_marbleWidget->installEventFilter(renderPlugin);
  }

  MarbleWidgetInputHandler *m_inputHandler;
  MarbleWidget *m_marbleWidget;
  bool m_debugModeEnabled;
};

void MarbleWidgetInputHandler::setCursor(const QCursor& cursor)
{
  d->setCursor(cursor);
}

bool MarbleWidgetInputHandler::handleKeyPress(QKeyEvent *event)
{
  if(d->m_debugModeEnabled)
  {
    switch(event->key())
    {
      case Qt::Key_I:
        MarbleDebug::setEnabled(!MarbleDebug::isEnabled());
        break;
      case Qt::Key_R:
        d->m_marbleWidget->setShowRuntimeTrace(!d->m_marbleWidget->showRuntimeTrace());
        break;
      case Qt::Key_P:
        d->m_marbleWidget->setShowDebugPolygons(!d->m_marbleWidget->showDebugPolygons());
        break;
    }
  }
  return MarbleDefaultInputHandler::handleKeyPress(event);
}

bool MarbleWidgetInputHandler::layersEventFilter(QObject *o, QEvent *e)
{
  return d->layersEventFilter(o, e);
}

void MarbleWidgetInputHandler::installPluginEventFilter(RenderPlugin *renderPlugin)
{
  d->installPluginEventFilter(renderPlugin);
}

MarbleWidgetInputHandler::MarbleWidgetInputHandler(MarbleAbstractPresenter *marblePresenter, MarbleWidget *widget)
  : MarbleDefaultInputHandler(marblePresenter)
  , d(new MarbleWidgetInputHandlerPrivate(this, widget))
{
}

void MarbleWidgetInputHandler::setDebugModeEnabled(bool enabled)
{
  d->m_debugModeEnabled = enabled;
}

void MarbleWidgetInputHandler::openItemToolTip()
{
  if(!lastToolTipItem().isNull())
  {
    QToolTip::showText(d->m_marbleWidget->mapToGlobal(toolTipPosition()),
                       lastToolTipItem()->toolTip(),
                       d->m_marbleWidget,
                       lastToolTipItem()->containsRect(toolTipPosition()).toRect());
  }
}

}

#include "moc_MarbleWidgetInputHandler.cpp"
