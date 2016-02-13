#include "CookieJarBaseHackRequest.h"

#include <QDebug>
#include <QNetworkCookie>

#include "TokenProvider.h"

namespace QWeiboSDK {
namespace HackLogin {

CookieJarBaseHackRequest::CookieJarBaseHackRequest(QObject *parent)
    : HackRequestCookieJar(parent)
{

}

QList<QNetworkCookie> CookieJarBaseHackRequest::cookiesForUrl(const QUrl &url) const
{
    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
    QList<QNetworkCookie> cookies = QNetworkCookieJar::cookiesForUrl(url);
    foreach (QNetworkCookie c, cookies) {
        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
    }
    return cookies;
}

bool CookieJarBaseHackRequest::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url)
{
    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
    foreach (QNetworkCookie c, cookieList) {
        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
    }
    TokenProvider::instance ()->updateHackLoginCookies (cookieList);
    return QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
}


} //HackLogin
} //QWeiboSDK
