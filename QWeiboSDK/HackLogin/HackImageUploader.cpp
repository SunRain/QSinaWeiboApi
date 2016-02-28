#include "HackImageUploader.h"

#include <QFileInfo>
#include <QDebug>
#include <QHttpPart>
#include <QNetworkReply>

#include "CookieJarBaseHackRequest.h"
#include "HackRequestCookieJar.h"
#include "TokenProvider.h"

namespace QWeiboSDK {
namespace HackLogin {

HackImageUploader::HackImageUploader(QObject *parent)
    : BaseHackRequest(parent)
    , m_reply(nullptr)
    , m_cookieJar(new CookieJarBaseHackRequest(this))
{
    setUrlPath ("mblogDeal/addPic", "");
    curNetworkAccessMgr ()->setCookieJar (m_cookieJar);
    initiate ();
    setTimerInterval (10000);
}

void HackImageUploader::uploadImage(const QString &fileUrl)
{
    setRequestAborted (false);
    QUrl url = initUrl ();
    QString furl = fileUrl;
    if (furl.startsWith ("file://"))
        furl = furl.replace("file://", "");
    QFileInfo imageInfo(furl);
    qDebug() << "file path: " << imageInfo.filePath();

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/" + imageInfo.suffix()));
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                        QVariant("form-data; name=\"pic\"; filename=" + imageInfo.fileName()));
    QFile *file = new QFile(furl);
    bool isOpen = file->open(QIODevice::ReadOnly);
    qDebug() << "file open? " << isOpen <<" file is exist "<<file->exists();

    imagePart.setBodyDevice(file);
    file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart

//    if (!content.isEmpty ()) {
//        QHttpPart textPart;
//        textPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
//        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"status\""));
//        textPart.setBody(content.toUtf8());
//        multiPart->append(textPart);
//    }
    multiPart->append(imagePart);

    if (curNetworkReply ()) {
//        m_requestAborted = true;
        setRequestAborted (true);
        curNetworkReply ()->abort ();
    }
    //post data may need a long time, we don't use timeout killer
//    if (m_timeout->isActive ())
//        m_timeout->stop ();
    stopTimeout ();

    QNetworkRequest request(url);
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9)Gecko/20100101 Firefox/44.0");
    QByteArray data;
    foreach (QString k, postDataParameters ().keys ()) {
        data.append (QString("%1=%2&").arg (k).arg (postDataParameters ().value (k)));
    }
    if (data.endsWith ("&"))
        data = data.left (data.length ()-1);

//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
//    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));

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
//    request.setAttribute (QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferNetwork);

    qDebug()<<Q_FUNC_INFO<<"post request for url: "<<url;
    foreach (QByteArray ba, request.rawHeaderList ()) {
        qDebug()<<Q_FUNC_INFO<<"request rawheader ["<<ba<<"="<<request.rawHeader (ba)<<"]";
    }

    m_reply = curNetworkAccessMgr ()->post (request, multiPart);

    if (m_reply) {
        multiPart->setParent (m_reply); //delete the multiPart with the reply
        file->setParent (m_reply); //delete file with the reply
        connect (m_reply, &QNetworkReply::finished,
                 [&](){
            //TODO maybe should set timeout killer when post data
//            if (m_timeout->isActive ())
//                m_timeout->stop ();

            if (requestAborted ()) {
//                m_requestAborted = false;
                setRequestAborted (false);
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
    } else {
        multiPart->deleteLater ();
        multiPart = nullptr;
        file->deleteLater ();
        file = nullptr;
    }
}

QNetworkReply *HackImageUploader::curNetworkReply()
{
    return m_reply;
}

void HackImageUploader::postRequest()
{
    qDebug()<<Q_FUNC_INFO<<">>>>>>>>> UN-USED-FUNCTION <<<<<<<<<";
}

void HackImageUploader::getRequest()
{
    qDebug()<<Q_FUNC_INFO<<">>>>>>>>> UN-USED-FUNCTION <<<<<<<<<";
}

} //HackLogin
} //QWeiboSDK
