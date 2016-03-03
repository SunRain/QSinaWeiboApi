#include "BaseRequest.h"

#include <QVariant>
#include <QDebug>
#include <QTimer>
#include <QUrl>
#include <QUrlQuery>
#include <QStandardPaths>

#include <QFileInfo>
#include <QHttpPart>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QNetworkReply>

#include "TokenProvider.h"

namespace QWeiboSDK {

BaseRequest::BaseRequest(QObject *parent)
    :QObject(parent)
    ,m_Editable(false)
    ,m_requestAborted(false)
    ,m_timerInterval(5000)
    ,m_baseUrl(QString(API_HOST))
    ,m_urlPath(QString())
    ,m_networkMgr(new QNetworkAccessManager(this))
    ,m_reply(nullptr)
    ,m_diskCache(new QNetworkDiskCache(m_networkMgr))
    ,m_timeout(new QTimer(this))
{
    m_timeout->setSingleShot (true);
    m_diskCache->setMaximumCacheSize (300*1024*1024);
    m_diskCache->setCacheDirectory (QString("%1/api_request")
                                    .arg (QStandardPaths::writableLocation(QStandardPaths::CacheLocation)));
    m_networkMgr->setCache (m_diskCache);
    connect (m_timeout, &QTimer::timeout,
             [&](){
        m_requestAborted = true;
        if (curNetworkReply ())
            curNetworkReply ()->abort ();
    });
}

BaseRequest::~BaseRequest()
{
    if (m_timeout->isActive ())
        m_timeout->stop ();
    m_timeout->deleteLater ();
    if (m_reply) {
        m_reply->abort ();
        m_reply->deleteLater ();
    }
    if (m_networkMgr)
        m_networkMgr->deleteLater ();
}

void BaseRequest::initiate()
{
    if (m_parameters.isEmpty ()) {
        m_Editable = true;
        initParameters ();
        m_Editable = false;
    }
    //TODO should add access_token and uid here ?
    if (m_parameters.contains ("access_token"))
        m_parameters.insert ("access_token", TokenProvider::instance ()->accessToken ());
    if (m_parameters.contains ("uid"))
        m_parameters.insert ("uid", TokenProvider::instance ()->uid ());

}

void BaseRequest::appendPostDataParameters(const QString &key, const QString &value)
{
    if (key.isEmpty ())
        return;
    m_postDataParameters.insert (key, value);
}

void BaseRequest::setParameters(const QString &key, const QString &value)
{
    (*this)(key, value);
}

BaseRequest &BaseRequest::operator ()(const QString &key, const QVariant &value)
{
    if (m_Editable || m_parameters.contains (key)) {
        m_parameters.insert (key, value.toString ());
    } else {
        qWarning()<<Q_FUNC_INFO<<"Can not set the parameter: "<<key;
    }
    return *this;
}

BaseRequest &BaseRequest::operator ()(const QString &key, const char *value)
{
    return (*this)(key, QString(value));
}

BaseRequest &BaseRequest::operator ()(const QString &key, int value)
{
    return (*this)(key, QString::number (value));
}

void BaseRequest::setTimerInterval(int msec)
{
    m_timerInterval = msec;
}

void BaseRequest::setBaseUrl(const QString &url)
{
    m_baseUrl = url;
}

void BaseRequest::initParameters()
{
    qDebug()<<Q_FUNC_INFO;
}

void BaseRequest::setUrlPath(const QString &urlPath, const QString &tag)
{
    if (!urlPath.isEmpty ()) {
        m_urlPath = urlPath;
        if (!tag.isEmpty ())
            m_urlPath = QString("%1%2").arg (m_urlPath).arg (tag);
    }
}

QUrl BaseRequest::initUrl()
{
    //add url parameters
//    QString str = QString("%1/%2").arg (m_baseUrl).arg (m_urlPath);
    QString str = m_baseUrl;
    if (!m_urlPath.isEmpty ()) {
        if (m_urlPath.startsWith ("/"))
            str = QString("%1%2").arg (m_baseUrl).arg (m_urlPath);
        else
            str = QString("%1/%2").arg (m_baseUrl).arg (m_urlPath);
    }
    QUrl url(str);
    if (!m_parameters.isEmpty ()) {
        QUrlQuery query;
        QMap<QString, QString>::const_iterator it = m_parameters.constBegin ();
        for (; it != m_parameters.constEnd (); ++it) {
             QString value = it.value ();
             query.addQueryItem (it.key (), value.trimmed ());
        }
        url.setQuery (query);
    }
    return url;
}

void BaseRequest::startTimeout()
{
    m_timeout->start (m_timerInterval);
}

void BaseRequest::stopTimeout()
{
    if (m_timeout->isActive ())
        m_timeout->stop ();
}

QNetworkAccessManager *BaseRequest::curNetworkAccessMgr()
{
    return m_networkMgr;
}

QNetworkReply *BaseRequest::curNetworkReply()
{
    return m_reply;
}

bool BaseRequest::requestAborted()
{
    return m_requestAborted;
}

void BaseRequest::setRequestAborted(bool shouldAborted)
{
    m_requestAborted = shouldAborted;
}

void BaseRequest::postRequest()
{
    m_requestAborted = false;

    QUrl url = initUrl ();
    qDebug()<<Q_FUNC_INFO<<"create request for url: "<<url;

//    QByteArray data(url.query(QUrl::FullyEncoded).toLatin1());
    QByteArray data;
    foreach (QString k, m_postDataParameters.keys ()) {
        data.append (QString("%1=%2&").arg (k).arg (m_postDataParameters.value (k)));
    }
    if (data.endsWith ("&"))
        data = data.left (data.length ()-1);

    //create request, if request exists, abort previous
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));

    qDebug()<<Q_FUNC_INFO<<" post data ["<<data<<"] to ["<<url<<"]";

    if (curNetworkReply ()) {
        m_requestAborted = true;
        curNetworkReply ()->abort ();
    }
    //post data may need a long time, we don't use timeout killer
//    if (m_timeout->isActive ())
//        m_timeout->stop ();
    stopTimeout ();

    //start reply and timeout watch
    m_reply = m_networkMgr->post (request, data);
//    m_timeout->start (m_timerInterval);

    if (m_reply) {
        connect (m_reply, &QNetworkReply::finished,
                 [&](){
//            if (m_timeout->isActive ())
//                m_timeout->stop ();

            if (m_requestAborted) {
                m_requestAborted = false;
//                m_reply->abort ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestAbort ();
                emit requestResult (BaseRequest::RET_ABORT, QString());
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestFailure (str);
                emit requestResult (BaseRequest::RET_FAILURE, str);
            } else {
                QByteArray qba = m_reply->readAll ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestSuccess (QString(qba));
                emit requestResult (BaseRequest::RET_SUCCESS, QString(qba));
            }
        });
    }
}

void BaseRequest::getRequest()
{
    m_requestAborted = false;

//    //add url parameters
//    QString str = QString("%1/%2").arg (m_baseUrl).arg (m_urlPath);
//    QUrl url(str);
//    if (!m_parameters.isEmpty ()) {
////        //TODO should add access_token and uid here ?
////        if (m_parameters.contains ("access_token"))
////            m_parameters.insert ("access_token", TokenProvider::instance ()->accessToken ());
////        if (m_parameters.contains ("uid"))
////            m_parameters.insert ("uid", TokenProvider::instance ()->uid ());

//        QUrlQuery query;
//        QMap<QString, QString>::const_iterator it = m_parameters.constBegin ();
//        for (; it != m_parameters.constEnd (); ++it) {
//             QString value = it.value ();
//             query.addQueryItem (it.key (), value.trimmed ());
//        }
//        url.setQuery (query);
//    }
    QUrl url = initUrl ();
    qDebug()<<Q_FUNC_INFO<<"create request for url: "<<url;
    //create request, if request exists, abort previous
    QNetworkRequest request(url);
    request.setAttribute (QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferNetwork);
    if (curNetworkReply ()) {
        m_requestAborted = true;
        curNetworkReply ()->abort ();
    }
    //start reply and timeout watch
    m_reply = m_networkMgr->get (request);
//    m_timeout->start (m_timerInterval);
    startTimeout ();

    if (m_reply) {
        connect (m_reply, &QNetworkReply::finished,
                 [&](){
            if (m_timeout->isActive ())
                m_timeout->stop ();

            if (m_requestAborted) {
                m_requestAborted = false;
//                m_reply->abort ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestAbort ();
                emit requestResult (BaseRequest::RET_ABORT, QString());
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestFailure (str);
                emit requestResult (BaseRequest::RET_SUCCESS, str);
            } else {
                QByteArray qba = m_reply->readAll ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestSuccess (QString(qba));
                emit requestResult (BaseRequest::RET_SUCCESS, QString(qba));
            }
        });
    }
}

} //QWeiboSDK
