#include "CookieJarBaseHackRequest.h"

#include <QDebug>
#include <QNetworkCookie>

#include "TokenProvider.h"

#define DBG_OUT 0
namespace QWeiboSDK {
namespace HackLogin {

CookieJarBaseHackRequest::CookieJarBaseHackRequest(QObject *parent)
    : HackRequestCookieJar(parent)
{

}

QList<QNetworkCookie> CookieJarBaseHackRequest::cookiesForUrl(const QUrl &url) const
{
#if DBG_OUT
    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
#endif
    QList<QNetworkCookie> cookies = QNetworkCookieJar::cookiesForUrl(url);
#if DBG_OUT
    foreach (QNetworkCookie c, cookies) {
        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
    }
#endif
    return cookies;
}

bool CookieJarBaseHackRequest::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url)
{
#if DBG_OUT
    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
    foreach (QNetworkCookie c, cookieList) {
        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
    }
#endif
    TokenProvider::instance ()->updateHackLoginCookies (cookieList);
    return QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
}


} //HackLogin
} //QWeiboSDK
