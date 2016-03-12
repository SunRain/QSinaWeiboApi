#include "LoginCookieJar.h"

#include <QDebug>
#include <QNetworkCookie>
#include <QUrl>

#include "TokenProvider.h"

#define DBG_OUT 0

namespace QWeiboSDK {
namespace HackLogin {

LoginCookieJar::LoginCookieJar(QObject *parent)
    : QNetworkCookieJar(parent)
{
    m_domain = QUrl();
}

void LoginCookieJar::cookieDomain(const QUrl &url)
{
    m_domain = url;
}

QList<QNetworkCookie> LoginCookieJar::cookiesForUrl(const QUrl &url) const
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

bool LoginCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url)
{
#if DBG_OUT
    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
    foreach (QNetworkCookie c, cookieList) {
        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
    }
#endif
    TokenProvider::instance ()->setHackLoginCookies (cookieList);
    return QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
}

} //HackLogin
} //QWeiboSDK

