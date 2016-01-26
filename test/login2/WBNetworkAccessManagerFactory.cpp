#include "WBNetworkAccessManagerFactory.h"

#include <QDebug>
#include <QNetworkDiskCache>
#include <QStandardPaths>

#include "WBNetworkAccessManager.h"

WBNetworkAccessManagerFactory::WBNetworkAccessManagerFactory() : QQmlNetworkAccessManagerFactory()
{
}

QNetworkAccessManager *WBNetworkAccessManagerFactory::create(QObject *parent)
{
    qDebug()<<Q_FUNC_INFO;
    QNetworkAccessManager *manager = new WBNetworkAccessManager(parent);
    QNetworkDiskCache *cache  = new QNetworkDiskCache(manager);
    cache->setMaximumCacheSize (300*1024*1024);
    cache->setCacheDirectory (QString("%1/network")
                              .arg (QStandardPaths::writableLocation(QStandardPaths::CacheLocation)));
    manager->setCache (cache);
    return manager;
}

