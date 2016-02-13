#include "HackRequestCookieJar.h"

#include <QDebug>
#include <QNetworkCookie>
#include <QUrl>

namespace QWeiboSDK {
namespace HackLogin {
HackRequestCookieJar::HackRequestCookieJar(QObject *parent)
    : QNetworkCookieJar(parent)
{

}

QString HackRequestCookieJar::cookies()
{
//    QStringList list;
//    foreach (QString s, m_cookiesHash.keys ()) {
//        QString v = QString("%1=%2").arg (s).arg (m_cookiesHash.value (s, QString()));
//        list.append (v);
//    }
//    if (list.isEmpty ())
//        return QString();
//    return list.join (";");
    return QString();
}

//QList<QNetworkCookie> HackRequestCookieJar::cookiesForUrl(const QUrl &url) const
//{
//    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
//    QList<QNetworkCookie> cookies = QNetworkCookieJar::cookiesForUrl(url);
//    foreach (QNetworkCookie c, cookies) {
//        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
//    }
//    return cookies;
//}

//bool HackRequestCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url)
//{
//    qDebug()<<Q_FUNC_INFO<<"cookiesForUrl "<<url;
//    foreach (QNetworkCookie c, cookieList) {
//        qDebug()<<Q_FUNC_INFO<<"cookies name="<<c.name ()<<" value="<<c.value ();
//        m_cookiesHash.insert (QString(c.name ()), QString(c.value ()));
//    }
//    return QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
//}

} //HackLogin
} //QWeiboSDK
