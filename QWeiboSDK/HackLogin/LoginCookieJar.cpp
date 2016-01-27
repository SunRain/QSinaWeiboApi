#include "LoginCookieJar.h"

#include <QDebug>
#include <QNetworkCookie>
#include <QUrl>

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
    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
    QList<QNetworkCookie> cookies = QNetworkCookieJar::cookiesForUrl(url);
    foreach (QNetworkCookie c, cookies) {
        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
    }
    return cookies;
}

bool LoginCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url)
{
    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
    foreach (QNetworkCookie c, cookieList) {
        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
    }
    return QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
}

