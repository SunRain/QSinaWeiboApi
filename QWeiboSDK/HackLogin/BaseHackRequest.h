#ifndef BASEHACKREQUEST_H
#define BASEHACKREQUEST_H

#include <QObject>

#include "global.h"
#include "BaseRequest.h"

namespace QWeiboSDK {
namespace HackLogin {
class HackRequestCookieJar;
class QWEIBOSDK_EXPORT BaseHackRequest : public BaseRequest
{
    Q_OBJECT
public:
    explicit BaseHackRequest(QObject *parent = 0);
    virtual ~BaseHackRequest();

    void appendExtraRequestCookie(HackRequestCookieJar *cookieJar);

    ///
    /// \brief reset base url to newUrl
    /// \param newUrl
    ///
    void resetBaseUrl(const QString &newUrl);

    // BaseRequest interface
protected:
//    virtual void initParameters();
    QNetworkReply *curNetworkReply();
public slots:
    void postRequest();
    void getRequest();

private:
    QNetworkReply *m_reply;
    HackRequestCookieJar *m_cookieJar;
};
} //HackLogin
} //QWeiboSDK
#endif // BASEHACKREQUEST_H
