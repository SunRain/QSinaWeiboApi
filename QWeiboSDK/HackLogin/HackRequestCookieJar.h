#ifndef HACKREQUESTCOOKIEJAR_H
#define HACKREQUESTCOOKIEJAR_H

#include <QNetworkCookieJar>
#include <QObject>
#include <QHash>

class QUrl;
class QNetworkCookie;

namespace QWeiboSDK {
namespace HackLogin {
class HackRequestCookieJar : public QNetworkCookieJar
{
    Q_OBJECT
public:
    explicit HackRequestCookieJar(QObject *parent = 0);

    virtual QString cookies();

//    // QNetworkCookieJar interface
//public:
//    QList<QNetworkCookie> cookiesForUrl(const QUrl &url) const;
//    bool setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url);

//private:
//    QHash<QString, QString> m_cookiesHash;
};
} //HackLogin
} //QWeiboSDK
#endif // HACKREQUESTCOOKIEJAR_H
