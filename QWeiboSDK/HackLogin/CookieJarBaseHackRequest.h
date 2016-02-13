#ifndef COOKIEJARBASEHACKREQUEST_H
#define COOKIEJARBASEHACKREQUEST_H

#include <QObject>
#include "HackRequestCookieJar.h"

namespace QWeiboSDK {
namespace HackLogin {

class CookieJarBaseHackRequest : public HackRequestCookieJar
{
    Q_OBJECT
public:
    explicit CookieJarBaseHackRequest(QObject *parent = 0);

    // QNetworkCookieJar interface
public:
    QList<QNetworkCookie> cookiesForUrl(const QUrl &url) const;
    bool setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url);
};

} //HackLogin
} //QWeiboSDK
#endif // COOKIEJARBASEHACKREQUEST_H
