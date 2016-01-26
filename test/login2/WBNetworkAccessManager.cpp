#include "WBNetworkAccessManager.h"

#include <QDebug>
#include <QNetworkRequest>
#include <QSslConfiguration>

const static char *DOMAIN_IMAGE = ".sinaimg.cn/";
WBNetworkAccessManager::WBNetworkAccessManager(QObject *parent)
    : QNetworkAccessManager(parent)
{
}

QNetworkReply *WBNetworkAccessManager::createRequest(QNetworkAccessManager::Operation op,
                                                     const QNetworkRequest &request,
                                                     QIODevice *outgoingData)
{
    qDebug()<<Q_FUNC_INFO;
    QNetworkRequest req(request);
    if (req.url ().toString ().contains (DOMAIN_IMAGE)) {
        req.setAttribute (QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    } else {
        req.setAttribute (QNetworkRequest::CacheSaveControlAttribute, false);
    }
    return QNetworkAccessManager::createRequest (op, req, outgoingData);
}

