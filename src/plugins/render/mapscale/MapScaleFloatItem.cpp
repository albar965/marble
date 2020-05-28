//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2008 Torsten Rahn      <tackat@kde.org>
// Copyright 2012 Illya Kovalevskyy <illya.kovalevskyy@gmail.com>
//

#include "MapScaleFloatItem.h"

#include <QContextMenuEvent>
#include <QDebug>
#include <QHelpEvent>
#include <QRect>
#include <QPainter>
#include <QPushButton>
#include <QMenu>
#include <QToolTip>

#include "ui_MapScaleConfigWidget.h"
#include "MarbleDebug.h"
#include "MarbleGlobal.h"
#include "projections/AbstractProjection.h"
#include "MarbleLocale.h"
#include "MarbleModel.h"
#include "MarbleMath.h"
#include "ViewportParams.h"

namespace Marble
{

MapScaleFloatItem::MapScaleFloatItem( const MarbleModel *marbleModel )
    : AbstractFloatItem( marbleModel, QPointF( 10.5, -10.5 ), QSizeF( 0.0, 40.0 ) ),
      m_configDialog(0),
      m_radius(0),
      m_target(QString()),
      m_leftBarMargin(0),
      m_rightBarMargin(0),
      m_scaleBarWidth(0),
      m_viewportWidth(0),
      m_scaleBarHeight(5),
      m_scaleBarDistance(0.0),
      m_bestDivisor(0),
      m_pixelInterval(0),
      m_valueInterval(0),
      m_scaleInitDone( false ),
      m_contextMenu( 0 ),
      m_minimized(false),
      m_widthScaleFactor(2)
{
#ifdef Q_WS_MAEMO_5
        setPosition( QPointF( 220.0, 10.5 ) );
#endif // Q_WS_MAEMO_5

    m_minimizeAction = new QAction(tr("Minimize"), this);
    m_minimizeAction->setCheckable(true);
    m_minimizeAction->setChecked(m_minimized);
    connect(m_minimizeAction, SIGNAL(triggered()), this, SLOT(toggleMinimized()));
}

MapScaleFloatItem::~MapScaleFloatItem()
{
}

QStringList MapScaleFloatItem::backendTypes() const
{
    return QStringList( "mapscale" );
}

QString MapScaleFloatItem::name() const
{
    return tr("Scale Bar");
}

QString MapScaleFloatItem::guiString() const
{
    return tr("&Scale Bar");
}

QString MapScaleFloatItem::nameId() const
{
    return QString( "scalebar" );
}

QString MapScaleFloatItem::version() const
{
    return "1.1";
}

QString MapScaleFloatItem::description() const
{
    return tr("This is a float item that provides a map scale.");
}

QString MapScaleFloatItem::copyrightYears() const
{
    return "2008, 2010, 2012, 2020";
}

QList<PluginAuthor> MapScaleFloatItem::pluginAuthors() const
{
    return QList<PluginAuthor>()
            << PluginAuthor( "Torsten Rahn", "tackat@kde.org", tr( "Original Developer" ) )
            << PluginAuthor( "Khanh-Nhan Nguyen", "khanh.nhan@wpi.edu" )
            << PluginAuthor( "Illya Kovalevskyy", "illya.kovalevskyy@gmail.com")
            << PluginAuthor( "Alexander Barthel", "alex@littlenavmap.org" );
}

QIcon MapScaleFloatItem::icon () const
{
    return QIcon(":/icons/scalebar.png");
}


void MapScaleFloatItem::initialize ()
{
}

bool MapScaleFloatItem::isInitialized () const
{
    return true;
}

void MapScaleFloatItem::setProjection( const ViewportParams *viewport )
{
    int viewportWidth = viewport->width();

    QString target = marbleModel()->planetId();

    if ( !(    m_radius == viewport->radius()
            && viewportWidth == m_viewportWidth
            && m_target == target
            && m_scaleInitDone ) )
    {
        int fontHeight     = QFontMetrics( font() ).ascent();
            setContentSize( QSizeF( viewport->width() / m_widthScaleFactor,
                                    fontHeight + 3 + m_scaleBarHeight ) );

        m_leftBarMargin  = QFontMetrics( font() ).boundingRect( "0" ).width() / 2;
        m_rightBarMargin = QFontMetrics( font() ).boundingRect( "0000" ).width() / 2;

        m_scaleBarWidth = contentSize().width() - m_leftBarMargin - m_rightBarMargin;
        m_viewportWidth = viewport->width();
        m_radius = viewport->radius();
        m_scaleInitDone = true;

        // Use two points around screen center and measure the ratio between screen and real world distance
        // on a horizontal line
        qreal lon1, lat1, lon2, lat2;
        int distScreen = viewport->width() / 5;
        int center = viewport->width() / 2;
        bool visible1 = viewport->geoCoordinates(center - distScreen / 2, viewport->height() / 2, lon1, lat1);
        bool visible2 = viewport->geoCoordinates(center + distScreen / 2, viewport->height() / 2, lon2, lat2);

        if(visible1 && visible2)
        {
          // Distance between points in meter
          qreal distWorld = EARTH_RADIUS * distanceSphere(GeoDataCoordinates(lon1, lat1, 0., GeoDataCoordinates::Degree),
                                                     GeoDataCoordinates(lon2, lat2, 0., GeoDataCoordinates::Degree));

          // to KM
          distWorld /= 1000.;

          const MarbleLocale::MeasurementSystem measurementSystem =
              MarbleGlobal::getInstance()->locale()->measurementSystem();

          switch (measurementSystem) {
            case Marble::MarbleLocale::MetricSystem:
              break;
            case Marble::MarbleLocale::ImperialSystem:
              distWorld *= KM2MI;
              break;
            case Marble::MarbleLocale::NauticalSystem:
              distWorld *= KM2NM;
              break;
          }

          m_pixel2Length = distWorld / distScreen;
        }
        else
          // Use old inaccurate method as fallback
          m_pixel2Length = marbleModel()->planetRadius() / (qreal)(viewport->radius());

        m_scaleBarDistance = (qreal)(m_scaleBarWidth) * m_pixel2Length;

        calcScaleBar();

        update();
    }

    AbstractFloatItem::setProjection( viewport );
}

void MapScaleFloatItem::paintContent( QPainter *painter )
{
    painter->save();

    painter->setRenderHint( QPainter::Antialiasing, true );

    int fontHeight     = QFontMetrics( font() ).ascent();

    painter->setPen(   QColor( Qt::darkGray ) );
    painter->setBrush( QColor( Qt::darkGray ) );
    painter->drawRect( m_leftBarMargin, fontHeight + 3, m_scaleBarWidth, m_scaleBarHeight );

    if(m_bestDivisor > 0)
    {
      painter->setPen(   QColor( Qt::black ) );
      painter->setBrush( QColor( Qt::white ) );
      painter->drawRect( m_leftBarMargin, fontHeight + 3,
                         m_bestDivisor * m_pixelInterval, m_scaleBarHeight );

      painter->setPen(   QColor( Oxygen::aluminumGray4 ) );
      painter->drawLine( m_leftBarMargin + 1, fontHeight + 2 + m_scaleBarHeight,
                         m_leftBarMargin + m_bestDivisor * m_pixelInterval - 1, fontHeight + 2 + m_scaleBarHeight );
      painter->setPen(   QColor( Qt::black ) );

      painter->setBrush( QColor( Qt::black ) );

      QString  intervalStr;
      int      lastStringEnds     = 0;
      int      currentStringBegin = 0;

      for ( int j = 0; j <= m_bestDivisor; j += 2 ) {
          if ( j < m_bestDivisor ) {
              painter->drawRect( m_leftBarMargin + j * m_pixelInterval,
                                 fontHeight + 3, m_pixelInterval - 1,
                                 m_scaleBarHeight );

        painter->setPen(   QColor( Oxygen::aluminumGray5 ) );
        painter->drawLine( m_leftBarMargin + j * m_pixelInterval + 1, fontHeight + 4,
               m_leftBarMargin + (j + 1) * m_pixelInterval - 1, fontHeight + 4 );
        painter->setPen(   QColor( Qt::black ) );
          }

          MarbleLocale::MeasurementSystem distanceUnit;
          distanceUnit = MarbleGlobal::getInstance()->locale()->measurementSystem();

          QString unit = tr("km");
          switch ( distanceUnit ) {
          case MarbleLocale::MetricSystem:
              if ( m_bestDivisor * m_valueInterval > 10000 ) {
                  unit = tr("km");
                  intervalStr.setNum( j * m_valueInterval / 1000 );
              }
              else {
                  unit = tr("m");
                  intervalStr.setNum( j * m_valueInterval );
              }
              break;
          case MarbleLocale::ImperialSystem:
              unit = tr("mi");
              intervalStr.setNum( j * m_valueInterval / 1000 );

              if ( m_bestDivisor * m_valueInterval > 2000 ) {
                  intervalStr.setNum( j * m_valueInterval / 1000 );
              }
              else {
                  intervalStr.setNum( qreal(j * m_valueInterval ) / 1000.0, 'f', 2 );
              }
              break;
          case MarbleLocale::NauticalSystem:
              unit = tr("nm");
              intervalStr.setNum( j * m_valueInterval / 1000 );

              if ( m_bestDivisor * m_valueInterval > 2000 ) {
                  intervalStr.setNum( j * m_valueInterval / 1000 );
              }
              else {
                  intervalStr.setNum( qreal(j * m_valueInterval) / 1000.0 , 'f', 2 );
              }
              break;
          }

          painter->setFont( font() );

          if ( j == 0 ) {
              painter->drawText( 0, fontHeight, "0 " + unit );
              lastStringEnds = QFontMetrics( font() ).width( "0 " + unit );
              continue;
          }

          if( j == m_bestDivisor ) {
              currentStringBegin = ( j * m_pixelInterval
                                     - QFontMetrics( font() ).boundingRect( intervalStr ).width() );
          }
          else {
              currentStringBegin = ( j * m_pixelInterval
                                     - QFontMetrics( font() ).width( intervalStr ) / 2 );
          }

          if ( lastStringEnds < currentStringBegin ) {
              painter->drawText( currentStringBegin, fontHeight, intervalStr );
              lastStringEnds = currentStringBegin + QFontMetrics( font() ).width( intervalStr );
          }
      }
    }

    painter->restore();
}

void MapScaleFloatItem::calcScaleBar()
{
  static int SCALE_MARKS[] = {1, 2, 4, 5};
  static int MAX_MARKS = 5;

  m_bestDivisor = 0;

  bool done = false;
  qreal laststep;
  // Go through all possible magnitudes eigh times
  for(qreal mag = 0.01; mag < 100000. && !done; mag *= 10.)
  {
    // Find scale marks distance
    for(int scale : SCALE_MARKS)
    {
      qreal unitstep = scale * mag;
      if(unitstep * MAX_MARKS > m_scaleBarDistance)
      {
        // Use the last step which did not overflow
        m_bestDivisor = int(m_scaleBarDistance / laststep);
        m_valueInterval = laststep * 1000.;
        m_pixelInterval = int((m_valueInterval / 1000.) / m_pixel2Length);
        done = true;
        break;
      }
      laststep = unitstep;
    }
  }
}

QDialog *MapScaleFloatItem::configDialog()
{
    if ( !m_configDialog ) {
        // Initializing configuration dialog
        m_configDialog = new QDialog();
        ui_configWidget = new Ui::MapScaleConfigWidget;
        ui_configWidget->setupUi( m_configDialog );

        readSettings();

        connect( ui_configWidget->m_buttonBox, SIGNAL(accepted()),
                                            SLOT(writeSettings()) );
        connect( ui_configWidget->m_buttonBox, SIGNAL(rejected()),
                                            SLOT(readSettings()) );

        QPushButton *applyButton = ui_configWidget->m_buttonBox->button( QDialogButtonBox::Apply );
        connect( applyButton, SIGNAL(clicked()) ,
                this,        SLOT(writeSettings()) );
    }
    return m_configDialog;
}

QHash<QString, QVariant> MapScaleFloatItem::settings() const
{
  QHash<QString, QVariant> settings = AbstractFloatItem::settings();
  settings.insert( "minimized", m_minimized );
  return settings;
}

void MapScaleFloatItem::setSettings(const QHash<QString, QVariant>& settings)
{
  AbstractFloatItem::setSettings( settings );
  m_minimized = settings.value( "minimized", false ).toBool();
  readSettings();
}

void MapScaleFloatItem::contextMenuEvent( QWidget *w, QContextMenuEvent *e )
{
    if ( !m_contextMenu ) {
        m_contextMenu = contextMenu();

        foreach( QAction *action, m_contextMenu->actions() ) {
            if ( action->text() == tr( "&Configure..." ) ) {
                m_contextMenu->removeAction( action );
                break;
            }
        }

        m_contextMenu->addAction(m_minimizeAction);
    }

    Q_ASSERT( m_contextMenu );
    m_contextMenu->exec( w->mapToGlobal( e->pos() ) );
}

void MapScaleFloatItem::readSettings()
{
    if ( !m_configDialog )
        return;

    ui_configWidget->m_minimizeCheckBox->setChecked(m_minimized);
}

void MapScaleFloatItem::writeSettings()
{
    if (m_minimized != ui_configWidget->m_minimizeCheckBox->isChecked()) {
        toggleMinimized();
    }

    emit settingsChanged( nameId() );
}

void MapScaleFloatItem::toggleRatioScaleVisibility()
{
    readSettings();
    emit settingsChanged( nameId() );
}

void MapScaleFloatItem::toggleMinimized()
{
    m_minimized = !m_minimized;
    ui_configWidget->m_minimizeCheckBox->setChecked(m_minimized);
    m_minimizeAction->setChecked(m_minimized);
    readSettings();
    emit settingsChanged( nameId() );

    if (m_minimized == true) {
        m_widthScaleFactor = 4;
    } else {
        m_widthScaleFactor = 2;
    }
}

}

#include "moc_MapScaleFloatItem.cpp"
