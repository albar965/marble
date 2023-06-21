//
// This file is part of the Marble Virtual Globe.
//
// Copyright 2010 Jens-Michael Hoffmann <jmho@c-xx.com>
// Copyright 2010-2012 Bernhard Beschow <bbeschow@cs.tu-berlin.de>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library. If not, see <http://www.gnu.org/licenses/>.

#ifndef MARBLE_TILELOADER_H
#define MARBLE_TILELOADER_H

#include <QObject>

#include "TileId.h"
#include "GeoDataContainer.h"
#include "PluginManager.h"
#include "MarbleGlobal.h"

class QByteArray;
class QImage;
class QUrl;
class QString;

namespace Marble
{
class HttpDownloadManager;
class GeoDataDocument;
class GeoSceneTileDataset;
class GeoSceneTextureTileDataset;
class GeoSceneVectorTileDataset;
class ParsingRunnerManager;

class TileLoader: public QObject
{
    Q_OBJECT

 public:
    enum TileStatus {
        Missing,
        Expired,
        Available
    };

    explicit TileLoader(HttpDownloadManager * const, const PluginManager * );
    ~TileLoader();

    QImage loadTileImage(GeoSceneTextureTileDataset const *textureData, TileId const & tileId, DownloadUsage const , QHash<QString, QString> keys);
    GeoDataDocument* loadTileVectorData(GeoSceneVectorTileDataset const *vectorData, TileId const & tileId, DownloadUsage const usage , QHash<QString, QString> keys);
    void downloadTile(GeoSceneTileDataset const *tileData, TileId const &, DownloadUsage const , QHash<QString, QString> keys);

    static int maximumTileLevel( GeoSceneTileDataset const & tileData );

    /**
     * Returns whether the mandatory most basic tile level is fully available for
     * the given @p layer.
     */
    static bool baseTilesAvailable(GeoSceneTileDataset const & tileData );

    /**
      * Returns the status of the downloaded tile file:
      * - Missing when it has not been downloaded
      * - Expired when it has been downloaded, but is too old (as per .dgml expiration time)
      * - Available when it has been downloaded and is not expired
      */
    static TileStatus tileStatus( GeoSceneTileDataset const *tileData, const TileId &tileId );

 private Q_SLOTS:
    void updateTile( QByteArray const & imageData, QString const & tileId );
    void updateTile( QString const & fileName, QString const & idStr );

 Q_SIGNALS:
    void downloadTile( QUrl const & sourceUrl, QString const & destinationFileName,
                       QString const & id, DownloadUsage );

    void tileCompleted( TileId const & tileId, QImage const & tileImage );

    void tileCompleted( TileId const & tileId, GeoDataDocument * document );

 private:
    static QString tileFileName(GeoSceneTileDataset const * tileData, TileId const & tileId, bool cache);
    void triggerDownload(GeoSceneTileDataset const *tileData, TileId const &, DownloadUsage const , QHash<QString, QString> keys);
    static QImage scaledLowerLevelTile( GeoSceneTextureTileDataset const * textureData, TileId const & );
    GeoDataDocument* openVectorFile(const QString &filename) const;

    // For vectorTile parsing
    PluginManager const * m_pluginManager;
};

}

#endif
