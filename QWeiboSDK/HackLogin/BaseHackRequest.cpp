#include "BaseHackRequest.h"

#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "CookieJarBaseHackRequest.h"
#include "HackRequestCookieJar.h"
#include "TokenProvider.h"

namespace QWeiboSDK {
namespace HackLogin {
BaseHackRequest::BaseHackRequest(QObject *parent)
    : BaseRequest(parent)
    , m_reply(nullptr)
    , m_cookieJar(nullptr)
{
    setBaseUrl (QString(HACK_LOGIN_HOST));
    appendExtraRequestCookie (new CookieJarBaseHackRequest(this));
    setTimerInterval (10000);
}

BaseHackRequest::~BaseHackRequest()
{

}

void BaseHackRequest::appendExtraRequestCookie(HackRequestCookieJar *cookieJar)
{
    if (m_cookieJar != cookieJar)
        m_cookieJar = cookieJar;
    if (m_cookieJar) {
        curNetworkAccessMgr ()->setCookieJar (m_cookieJar);
    }
}

void BaseHackRequest::resetBaseUrl(const QString &newUrl)
{
    if (newUrl.isEmpty ()) {
        qWarning()<<Q_FUNC_INFO<<"Invalid empty newUrl";
        return;
    }
    setBaseUrl (newUrl);
}

QNetworkReply *BaseHackRequest::curNetworkReply()
{
    return m_reply;
}

void BaseHackRequest::postRequest()
{
    setRequestAborted (false);
    QUrl url = initUrl ();
    QByteArray data(url.query(QUrl::FullyEncoded).toLatin1());

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9)Gecko/20100101 Firefox/44.0");

    QString cookies = TokenProvider::instance ()->hackLoginCookies ();
    if (m_cookieJar) {
        QString extra = m_cookieJar->cookies ();
        if (!extra.isEmpty () && extra != cookies) {
            if (!cookies.endsWith (";"))
                cookies.append (";");
            cookies.append (extra);
        }
    }
    request.setRawHeader ("Cookie", cookies.toUtf8 ());
    request.setAttribute (QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferNetwork);

    if (curNetworkReply ()) {
        setRequestAborted (true);
        curNetworkReply ()->abort ();
    }
    //post data may need a long time, we don't use timeout killer
    stopTimeout ();

    m_reply = curNetworkAccessMgr ()->post (request, data);

    if (m_reply) {
        connect (m_reply, &QNetworkReply::finished,
                 [&](){
            //post data may need a long time, we don't use timeout killer
            stopTimeout ();

            if (m_reply)
                m_reply->disconnect ();

            if (requestAborted ()) {
                setRequestAborted (false);
                if (m_reply) {
                    m_reply->deleteLater ();
                    m_reply = nullptr;
                }
                emit requestAbort ();
                emit requestResult (BaseRequest::RET_ABORT, QString());
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                qDebug()<<Q_FUNC_INFO<<"Request error ["<<str<<"]";
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestFailure (str);
                emit requestResult (BaseRequest::RET_FAILURE, str);
            } else {
                QByteArray qba = m_reply->readAll ();
//                foreach (QByteArray ar, m_reply->rawHeaderList ()) {
//                    qDebug()<<Q_FUNC_INFO<<ar;

//                }
//                foreach (QNetworkReply::RawHeaderPair p, m_reply->rawHeaderPairs ()) {
//                    qDebug()<<Q_FUNC_INFO<<p.first<<"||"<<p.second;
//                }
                m_reply->deleteLater ();
                m_reply = nullptr;

                qDebug()<<Q_FUNC_INFO<<"Request success size "<<qba.length ();
                qDebug()<<Q_FUNC_INFO<<"Request success ["<<QString::fromUtf8 (qba)<<"]";

                emit requestSuccess (QString(qba));
                emit requestResult (BaseRequest::RET_SUCCESS, QString(qba));
            }
        });
    }
}

void BaseHackRequest::getRequest()
{
    setRequestAborted (false);
    QUrl url = initUrl ();

    QNetworkRequest request(url);
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
//    request.setRawHeader ("Host", "weibo.cn");
    //Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:44.0) Gecko/20100101 Firefox/44.0
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9)Gecko/20100101 Firefox/44.0");
//    request.setRawHeader ("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
//    request.setRawHeader ("Accept-Language", "en-US,zh-CN;q=0.8,zh;q=0.5,en;q=0.3");
//    request.setRawHeader ("Accept-Encoding", "gzip, deflate");
//    request.setRawHeader ("Referer", "http://weibo.cn/");
//    request.setRawHeader ("Connection",	"keep-alive");
    QString cookies = TokenProvider::instance ()->hackLoginCookies ();
    if (m_cookieJar) {
        QString extra = m_cookieJar->cookies ();
        if (!extra.isEmpty () && extra != cookies) {
            if (!cookies.endsWith (";"))
                cookies.append (";");
            cookies.append (extra);
        }
    }
    request.setRawHeader ("Cookie", cookies.toUtf8 ());
    request.setAttribute (QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferNetwork);

    qDebug()<<Q_FUNC_INFO<<"create request for url: "<<url;
    foreach (QByteArray ba, request.rawHeaderList ()) {
        qDebug()<<Q_FUNC_INFO<<"request rawheader ["<<ba<<"="<<request.rawHeader (ba)<<"]";
    }

    if (curNetworkReply ()) {
        setRequestAborted (true);
        curNetworkReply ()->abort ();
    }

    m_reply = curNetworkAccessMgr ()->get (request);

    startTimeout ();

    if (m_reply) {
        connect (m_reply, &QNetworkReply::finished,
                 [&](){
            stopTimeout ();

            if (m_reply)
                m_reply->disconnect ();

            if (requestAborted ()) {
                setRequestAborted (false);
                if (m_reply) {
                    m_reply->deleteLater ();
                    m_reply = nullptr;
                }
                emit requestAbort ();
                emit requestResult (BaseRequest::RET_ABORT, QString());
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                qDebug()<<Q_FUNC_INFO<<"Request error ["<<str<<"]";
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestFailure (str);
                emit requestResult (BaseRequest::RET_FAILURE, str);
            } else {
                QByteArray qba = m_reply->readAll ();
                foreach (QByteArray ar, m_reply->rawHeaderList ()) {
                    qDebug()<<Q_FUNC_INFO<<ar;

                }
                foreach (QNetworkReply::RawHeaderPair p, m_reply->rawHeaderPairs ()) {
                    qDebug()<<Q_FUNC_INFO<<p.first<<"||"<<p.second;
                }
                m_reply->deleteLater ();
                m_reply = nullptr;

                qDebug()<<Q_FUNC_INFO<<"Request success size "<<qba.length ();
                qDebug()<<Q_FUNC_INFO<<"Request success ["<<QString::fromUtf8 (qba)<<"]";

                emit requestSuccess (QString(qba));
                emit requestResult (BaseRequest::RET_SUCCESS, QString(qba));
            }
        });
    }
}

} //HackLogin
} //QWeiboSDK
