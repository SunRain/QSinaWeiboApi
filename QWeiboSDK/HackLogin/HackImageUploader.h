#ifndef HACKIMAGEUPLOADER_H
#define HACKIMAGEUPLOADER_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"
#include "ImageUploader.h"

class QNetworkReply;

namespace QWeiboSDK {
namespace HackLogin {
class HackRequestCookieJar;
//post http://m.weibo.cn/mblogDeal/addPic
class QWEIBOSDK_EXPORT HackImageUploader : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackImageUploader(QObject *parent = 0);
    Q_INVOKABLE void uploadImage(const QString &fileUrl);

    // BaseRequest interface
protected:
    QNetworkReply *curNetworkReply();

public slots:
    void postRequest();
    void getRequest();

private:
    HackRequestCookieJar *m_cookieJar;
    QNetworkReply *m_reply;
};

} //HackLogin
} //QWeiboSDK

#endif // HACKIMAGEUPLOADER_H
