//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2014 Abhinav Gangwar <abhgang@gmail.com>
//

// Qt
#include <QtNetwork>
#include <QDebug>
#include <QString>
#include <QHash>
#include <QUrl>
#include <QImage>
#include <QByteArray>
#include <QFileInfo>
#include <QCryptographicHash>

// Marble
#include "RemoteIconLoader.h"

#include "HttpDownloadManager.h"
#include "FileStoragePolicy.h"
#include "MarbleDirs.h"
#include "MarbleGlobal.h"
#include "MarbleDebug.h"

namespace Marble
{

class RemoteIconLoaderPrivate
{
    public:
        RemoteIconLoaderPrivate()
            : m_storagePolicy( MarbleDirs::localPath().append("/cache/icons/") ),
              m_downloadManager( &m_storagePolicy )
        { 
        }
        QHash<QUrl, QImage> m_iconCache;
        FileStoragePolicy m_storagePolicy;
        HttpDownloadManager m_downloadManager;

        /**
         * Returns true if the icon for Url(=url) is available in cache
         */
        bool isCached( const QString& url ) const;

        /**
         * Returns icon for the url passes in argument
         */
        QImage cachedIcon( const QString& url ) const;

        /**
         * Returns true if icon is locally present on disk
         */
        bool loadFromDiskCache( const QString& url );

        /**
         * Starts downloading icon if it isn't present cache and 
         * could not be found locally on disk
         */
        void initiateDownload( const QString& url );

        /**
         * Returns a name with which downloaded icon will be saved on disk
         */
        QString cacheFileName( const QString& url ) const;
};

bool RemoteIconLoaderPrivate::isCached( const QString& url ) const
{
    return m_iconCache.contains( QUrl(url) );
}

QImage RemoteIconLoaderPrivate::cachedIcon( const QString& url ) const
{
    return m_iconCache.value( QUrl( url ) );
}

bool RemoteIconLoaderPrivate::loadFromDiskCache( const QString& url )
{
    QString path = MarbleDirs::localPath().append("/cache/icons/") + cacheFileName( url );
    QImage icon = QFile::exists( path ) ? QImage( path ) : QImage();
    if ( !icon.isNull() ) {
        m_iconCache.insert( url, icon );
        return true;
    }
    return false;
}

void RemoteIconLoaderPrivate::initiateDownload( const QString& url )
{
    DownloadUsage usage = DownloadBrowse;
    m_downloadManager.setDownloadEnabled(true);
    QString fileName = cacheFileName( url );
    m_downloadManager.addJob( url, fileName, url, usage );
}

QString RemoteIconLoaderPrivate::cacheFileName( const QString& url ) const
{
    QFileInfo fileInfo = QFileInfo( url );
    QByteArray const hash = QCryptographicHash::hash( url.toLatin1(), QCryptographicHash::Md5 ).toHex();
    QString fileName = QString("%1.%2").arg( QString(hash) ).arg( fileInfo.suffix() );
    return fileName;
}

RemoteIconLoader::RemoteIconLoader( QObject *parent )
    : QObject( parent ),
      d ( new RemoteIconLoaderPrivate() )
{
    connect( &d->m_downloadManager, SIGNAL(downloadComplete(QByteArray, QString)), this,
            SLOT(storeIcon(QByteArray, QString)) );
}

RemoteIconLoader::~RemoteIconLoader()
{
    delete d;
}


QImage RemoteIconLoader::load( const QString& url )
{
    /*
     * If image has been downloaded previously then
     * return it from m_iconCache. All the downloaded
     * images in current running marble session are stored
     * in m_iconCache.
     */
    if ( d->isCached( url ) ) {
        return d->cachedIcon( url );
    }

    /*
     * All the downloaded images are saved on disk
     * at location cache/icons/ ( relative location ).
     * If the rquested icon is present at this location then
     * return it.
     */
    else if ( d->loadFromDiskCache( url ) ) {
        return d->cachedIcon( url );
    }

    // Otherwise initiate download
    else {
        d->initiateDownload( url );
    }
    return QImage();
}


void RemoteIconLoader::storeIcon( const QByteArray &data, const QString &fileName)
{
    QImage icon = QImage::fromData( data );
    d->m_iconCache.insert( QUrl(fileName), icon );
    emit iconReady();
}

}

#include "moc_RemoteIconLoader.cpp"
