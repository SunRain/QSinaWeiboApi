#include "BaseHackRequest.h"

#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "TokenProvider.h"

namespace QWeiboSDK {
namespace HackLogin {
BaseHackRequest::BaseHackRequest(QObject *parent)
    : BaseRequest(parent)
    , m_reply(nullptr)
{
    setBaseUrl (QString(HACK_LOGIN_HOST));
}

BaseHackRequest::~BaseHackRequest()
{

}

//void BaseHackRequest::initParameters()
//{
//    qDebug()<<Q_FUNC_INFO;
//}

QNetworkReply *BaseHackRequest::curNetworkReply()
{
    return m_reply;
}

void BaseHackRequest::postRequest()
{

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
    request.setRawHeader ("Cookie", TokenProvider::instance ()->hackLoginCookies ().toUtf8 ());

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

            if (requestAborted ()) {
                setRequestAborted (false);
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestAbort ();
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
            } else {
                QByteArray qba = m_reply->readAll ();
                qDebug()<<Q_FUNC_INFO<<"Request success size "<<qba.length ();
                qDebug()<<Q_FUNC_INFO<<"Request success ["<<QString::fromUtf8 (qba)<<"]";
//                qDebug()<<Q_FUNC_INFO<<m_reply->rawHeaderList ();
//                qDebug()<<Q_FUNC_INFO<<m_reply->rawHeaderPairs ();
                foreach (QByteArray ar, m_reply->rawHeaderList ()) {
                    qDebug()<<Q_FUNC_INFO<<ar;

                }
                foreach (QNetworkReply::RawHeaderPair p, m_reply->rawHeaderPairs ()) {
                    qDebug()<<Q_FUNC_INFO<<p.first<<"||"<<p.second;
                }
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit requestSuccess (QString(qba));
            }
        });
    }
}

} //HackLogin
} //QWeiboSDK
