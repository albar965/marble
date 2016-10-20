//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2010      Bastian Holst <bastianholst@gmx.de>
//

// Self
#include "LegendWidget.h"

// Marble
#include "MarbleModel.h"

using namespace Marble;
// Ui
#ifdef MARBLE_NO_WEBKITWIDGETS
#include "ui_NullLegendWidget.h"
#else
#include "ui_LegendWidget.h"
#endif

#include "MarbleLegendBrowser.h"

namespace Marble
{

class LegendWidgetPrivate : public Ui::LegendWidget
{
 public:
    LegendWidgetPrivate();
};

LegendWidgetPrivate::LegendWidgetPrivate()
{
}

LegendWidget::LegendWidget( QWidget *parent, Qt::WindowFlags f )
    : QWidget( parent, f ),
      d( new LegendWidgetPrivate )
{
  d->setupUi( this );
}

LegendWidget::~LegendWidget()
{
    delete d;
}

void LegendWidget::setMarbleModel( MarbleModel *model )
{
    // Initialize the MarbleLegendBrowser
    d->m_marbleLegendBrowser->setMarbleModel( model );
}

QString LegendWidget::getHtml(QString& basePath)
{
  return d->m_marbleLegendBrowser->getHtml(basePath);
}

}

#include "moc_LegendWidget.cpp"
