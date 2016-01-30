#ifndef LOGINCOOKIEJAR_H
#define LOGINCOOKIEJAR_H

#include <QNetworkCookieJar>
#include <QObject>

class QUrl;
class QNetworkCookie;

namespace QWeiboSDK {
namespace HackLogin {

class LoginCookieJar : public QNetworkCookieJar
{
    Q_OBJECT
public:
    LoginCookieJar(QObject *parent = 0);

    void cookieDomain(const QUrl &url);

    // QNetworkCookieJar interface
public:
    QList<QNetworkCookie> cookiesForUrl(const QUrl &url) const;
    bool setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url);

private:
    QUrl m_domain;
};

} //HackLogin
} //QWeiboSDK
#endif // LOGINCOOKIEJAR_H
