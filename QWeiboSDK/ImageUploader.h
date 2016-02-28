#ifndef IMAGEUPLOADER_H
#define IMAGEUPLOADER_H

#include <QObject>
#include "BaseRequest.h"

class QNetworkReply;
namespace QWeiboSDK {

class QWEIBOSDK_EXPORT ImageUploader : public BaseRequest
{
    Q_OBJECT
public:
    explicit ImageUploader(QObject *parent = 0);
    Q_INVOKABLE void sendWeiboWithImage(const QString &content, const QString &fileUrl);
//    virtual ~ImageUploader() {}

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("access_token", "")
        ;
    }
    QNetworkReply *curNetworkReply();

private:
    QNetworkReply *m_reply;
};

} //QWeiboSDK
#endif // IMAGEUPLOADER_H
