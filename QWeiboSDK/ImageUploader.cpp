#include "ImageUploader.h"

#include <QFileInfo>
#include <QDebug>
#include <QHttpPart>
#include <QNetworkReply>

namespace QWeiboSDK {

ImageUploader::ImageUploader(QObject *parent)
    : BaseRequest(parent)
    , m_reply(nullptr)
{
    setBaseUrl (QString(IMAGE_UPLOAD_HOST));
    setUrlPath ("2/statuses/upload");
    initiate ();
    setTimerInterval (10000);
}

void ImageUploader::sendWeiboWithImage(const QString &content, const QString &fileUrl)
{
    setRequestAborted (false);
    QUrl url = initUrl ();
    QString furl = fileUrl;
    if (furl.startsWith ("file://"))
        furl = furl.replace("file://", "");
    QFileInfo imageInfo(furl);
    qDebug() << "file path: " << imageInfo.filePath();

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart textPart;
    textPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
    textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"status\""));
    textPart.setBody(content.toUtf8());

    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/" + imageInfo.suffix()));
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                        QVariant("form-data; name=\"pic\"; filename=" + imageInfo.fileName()));
    QFile *file = new QFile(furl);
    bool isOpen = file->open(QIODevice::ReadOnly);
    qDebug() << "file open? " << isOpen <<" file is exist "<<file->exists();

    imagePart.setBodyDevice(file);
    file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart

    multiPart->append(textPart);
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

QNetworkReply *ImageUploader::curNetworkReply()
{
    return m_reply;
}

} //QWeiboSDK
