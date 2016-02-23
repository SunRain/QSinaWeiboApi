#include "CookieDataProvider.h"

#include <QDebug>

#include <QTimer>

#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonDocument>
#include <QUrl>
#include <QUrlQuery>

#include <QByteArray>

#if 0
#include "htmlcxx/html/tree.h"
#include "htmlcxx/html/ParserDom.h"
#include "htmlcxx/html/Node.h"
#endif

#include "LoginCookieJar.h"
#include "TokenProvider.h"

#if 0
using namespace htmlcxx;
using namespace std;
#endif

namespace QWeiboSDK {
namespace HackLogin {

CookieDataProvider::CookieDataProvider(QObject *parent)
    : QObject(parent)
    , m_networkMgr(new QNetworkAccessManager(this))
    , m_reply(nullptr)
    , m_timeout(new QTimer(this))
    , m_cookieJar(new LoginCookieJar(this))
    , m_requestAborted(false)
//    , m_loginOK(false)
    , m_timerInterval(5000)
    , m_userName(QString())
    , m_passWord(QString())
    , m_rand(QString())
    , m_headerPassWord(QString())
    , m_vk(QString())
    , m_backTitle(QString())
    , m_submit(QString())
    , m_capId(QString())
    , m_captcha(QString())
    , m_captchaImgUrl(QString())
    , m_pcid(QString())
{
    m_networkMgr->setCookieJar (m_cookieJar);
    m_timeout->setSingleShot (true);
    connect (m_timeout, &QTimer::timeout,
             [&] () {
        m_requestAborted = true;
        if (m_reply)
            m_reply->abort ();
    });
}

CookieDataProvider::~CookieDataProvider()
{
    if (m_timeout->isActive ())
        m_timeout->stop ();
    m_timeout->deleteLater ();
    if (m_reply) {
        m_reply->abort ();
        m_reply->deleteLater ();
    }
    if (m_networkMgr)
        m_networkMgr->deleteLater ();
}

void CookieDataProvider::preLogin()
{
   preLogin1 ();
}

void CookieDataProvider::preLogin1()
{
    m_requestAborted = false;

    QUrl url(QString("http://m.weibo.cn"));
    QNetworkRequest request(url);
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");

    QByteArray data(url.query(QUrl::FullyEncoded).toLatin1());

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));

    qDebug()<<Q_FUNC_INFO<<"post to url ["<<url<<"] with data ["<<data<<"]";

    if (m_reply) {
        m_requestAborted = true;
        m_reply->abort ();
    }
    m_reply = m_networkMgr->post (request, data);

    m_timeout->start (m_timerInterval);

    if (m_reply) {
        QObject::connect (m_reply, &QNetworkReply::finished,
                 [&](){
            if (m_timeout->isActive ())
                m_timeout->stop ();

            if (m_requestAborted) {
                m_requestAborted = false;
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"network request aborted previous";
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"error str "<<str;
                emit loginFailure (str);
            } else {
                QByteArray qba = m_reply->readAll ();
//                qDebug()<<Q_FUNC_INFO<<"ret "<<qba;
                m_reply->deleteLater ();
                m_reply = nullptr;
                preLogin2 ();
            }
        });
    } else {
        qDebug()<<Q_FUNC_INFO<<"no reply";
        emit loginFailure ("No QNetworkReply");
    }
}

void CookieDataProvider::preLogin2()
{
    m_requestAborted = false;

    QUrl url(QString("https://passport.weibo.cn/signin/welcome"));
    QNetworkRequest request(url);
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
//    https://passport.weibo.cn/signin/welcome?entry=mweibo&r=http%3A%2F%2Fm.weibo.cn%2F&wm=3349&vt=4
    QUrlQuery query;
    query.addQueryItem ("entry", "mweibo");
    query.addQueryItem ("r", "http://m.weibo.cn/");
    query.addQueryItem ("wm", "3349");
    query.addQueryItem ("vt", "4");
    url.setQuery (query);

    qDebug()<<Q_FUNC_INFO<<"get url ["<<url;

    if (m_reply) {
        m_requestAborted = true;
        m_reply->abort ();
    }
    m_reply = m_networkMgr->get (request);

    m_timeout->start (m_timerInterval);

    if (m_reply) {
        QObject::connect (m_reply, &QNetworkReply::finished,
                 [&](){
            if (m_timeout->isActive ())
                m_timeout->stop ();

            if (m_requestAborted) {
                m_requestAborted = false;
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"network request aborted previous";
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"error str "<<str;
                emit loginFailure (str);
            } else {
                QByteArray qba = m_reply->readAll ();
//                qDebug()<<Q_FUNC_INFO<<"ret "<<qba;
                m_reply->deleteLater ();
                m_reply = nullptr;
                preLogin3 ();
            }
        });
    } else {
        qDebug()<<Q_FUNC_INFO<<"no reply";
        emit loginFailure ("No QNetworkReply");
    }
}

void CookieDataProvider::preLogin3()
{
    m_requestAborted = false;

    QUrl url(QString("https://passport.weibo.cn/signin/login"));
    QNetworkRequest request(url);
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
//    https://passport.weibo.cn/signin/login?entry=mweibo&res=wel&wm=3349&r=http%3A%2F%2Fm.weibo.cn%2F
    QUrlQuery query;
    query.addQueryItem ("entry", "mweibo");
    query.addQueryItem ("r", "http://m.weibo.cn/");
    query.addQueryItem ("wm", "3349");
    query.addQueryItem ("res", "wel");
    url.setQuery (query);

    qDebug()<<Q_FUNC_INFO<<"get url ["<<url;

    if (m_reply) {
        m_requestAborted = true;
        m_reply->abort ();
    }
    m_reply = m_networkMgr->get (request);

    m_timeout->start (m_timerInterval);

    if (m_reply) {
        QObject::connect (m_reply, &QNetworkReply::finished,
                 [&](){
            if (m_timeout->isActive ())
                m_timeout->stop ();

            if (m_requestAborted) {
                m_requestAborted = false;
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"network request aborted previous";
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"error str "<<str;
                emit loginFailure (str);
            } else {
                QByteArray qba = m_reply->readAll ();
//                qDebug()<<Q_FUNC_INFO<<"ret "<<qba;
                m_reply->deleteLater ();
                m_reply = nullptr;
//                emit preLoginSuccess ();
                preCaptchaImage ();
            }
        });
    } else {
        qDebug()<<Q_FUNC_INFO<<"no reply";
        emit loginFailure ("No QNetworkReply");
    }
}

//void CookieDataProvider::login2_pre()
//{
//    m_requestAborted = false;

//    QUrl url(QString("https://login.sina.com.cn/sso/prelogin.php"));
//    QNetworkRequest request(url);
//    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
//    request.setRawHeader("Referer", "https://passport.weibo.cn/signin/login?entry=mweibo&res=wel&wm=3349&r=http%3A%2F%2Fm.weibo.cn%2F");
//    request.setRawHeader("Cookie", TokenProvider::instance ()->hackLoginCookies ().toLatin1 ());

//    QUrlQuery query;
//    query.addQueryItem ("checkpin", "1");
//    query.addQueryItem ("entry", "mweibo");
//    query.addQueryItem ("su", m_userName.toLatin1 ().toBase64 (QByteArray::Base64Encoding | QByteArray::OmitTrailingEquals));
//    query.addQueryItem ("callback", "jsonpcallback1454764734570");
//    url.setQuery (query);

//    qDebug()<<Q_FUNC_INFO<<"get url ["<<url;

//    if (m_reply) {
//        m_requestAborted = true;
//        m_reply->abort ();
//    }
//    m_reply = m_networkMgr->get (request);

//    m_timeout->start (m_timerInterval);

//    if (m_reply) {
//        QObject::connect (m_reply, &QNetworkReply::finished,
//                 [&](){
//            if (m_timeout->isActive ())
//                m_timeout->stop ();

//            if (m_requestAborted) {
//                m_requestAborted = false;
//                m_reply->deleteLater ();
//                m_reply = nullptr;
//                qDebug()<<Q_FUNC_INFO<<"network request aborted previous";
//                return;
//            }
//            QNetworkReply::NetworkError error = m_reply->error ();
//            bool success = (error == QNetworkReply::NoError);
//            if (!success) {
//                QString str = m_reply->errorString ();
//                m_reply->deleteLater ();
//                m_reply = nullptr;
//                qDebug()<<Q_FUNC_INFO<<"error str "<<str;
//                emit loginFailure (str);
//            } else {
//                QByteArray qba = m_reply->readAll ();
//                qDebug()<<Q_FUNC_INFO<<"ret "<<qba;
//                m_reply->deleteLater ();
//                m_reply = nullptr;
//            }
//        });
//    } else {
//        qDebug()<<Q_FUNC_INFO<<"no reply";
//        emit loginFailure ("No QNetworkReply");
//    }
//}

void CookieDataProvider::preCaptchaImage()
{
    m_requestAborted = false;

    QUrl url(QString("https://passport.weibo.cn/captcha/image"));
    QNetworkRequest request(url);
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
    request.setRawHeader("Referer", "https://passport.weibo.cn/signin/login?entry=mweibo&res=wel&wm=3349&r=http%3A%2F%2Fm.weibo.cn%2F");
    request.setRawHeader("Cookie", TokenProvider::instance ()->hackLoginCookies ().toLatin1 ());

//    QUrlQuery query;
//    query.addQueryItem ("checkpin", "1");
//    query.addQueryItem ("entry", "mweibo");
//    query.addQueryItem ("su", m_userName.toLatin1 ().toBase64 (QByteArray::Base64Encoding | QByteArray::OmitTrailingEquals));
//    query.addQueryItem ("callback", "jsonpcallback1454764734570");
//    url.setQuery (query);

    qDebug()<<Q_FUNC_INFO<<"get url ["<<url;

    if (m_reply) {
        m_requestAborted = true;
        m_reply->abort ();
    }
    m_reply = m_networkMgr->get (request);

    m_timeout->start (m_timerInterval);

    if (m_reply) {
        QObject::connect (m_reply, &QNetworkReply::finished,
                 [&](){
            if (m_timeout->isActive ())
                m_timeout->stop ();

            if (m_requestAborted) {
                m_requestAborted = false;
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"network request aborted previous";
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"error str "<<str;
                emit loginFailure (str);
            } else {
                QByteArray qba = m_reply->readAll ();
//                qDebug()<<Q_FUNC_INFO<<"ret "<<qba;
                m_reply->deleteLater ();
                m_reply = nullptr;

                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson (qba, &error);
                if (error.error != QJsonParseError::NoError) {
                    qDebug()<<Q_FUNC_INFO<<"Parse json error => "<<error.errorString ();
                    return;
                }
                QJsonObject obj = doc.object ();
                QJsonValue v = obj.value ("data");
                obj = v.toObject ();
                m_pcid = obj.value ("pcid").toString ();
                QString tmpImgUrl = obj.value ("image").toString ();
                qDebug()<<Q_FUNC_INFO<<"pcid is "<<m_pcid;
                qDebug()<<Q_FUNC_INFO<<"Image data url is "<<QUrl(m_captchaImgUrl);
                if (m_captchaImgUrl != tmpImgUrl) {
                    m_captchaImgUrl = tmpImgUrl;
                    qDebug()<<"captchaImgUrl ["<<m_captchaImgUrl<<"]";
                    emit captchaImgUrlChanged (QUrl(m_captchaImgUrl));
                }
                emit preLoginSuccess ();
            }
        });
    } else {
        qDebug()<<Q_FUNC_INFO<<"no reply";
        emit loginFailure ("No QNetworkReply");
    }
}

void CookieDataProvider::login()
{
    m_requestAborted = false;

    QUrl url(QString("https://passport.weibo.cn/sso/login"));
    QNetworkRequest request(url);
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
    request.setRawHeader("Host", "passport.weibo.cn");
    //            post.setHeader("Referer", CommonConst.loginUrl);
//    request.setRawHeader("Origin", "http://m.weibo.cn");
//    request.setRawHeader("Cache-Control", "max-age=0");
//    request.setRawHeader("Accept",
//        "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
//    request.setRawHeader("Accept-Encoding", "gzip,deflate,sdch");
//    request.setRawHeader("Accept-Language", "en-US,en;q=0.8");
//    request.setRawHeader("Accept-Charset", "ISO-8859-1,utf-8;q=0.7,*;q=0.3");
//    request.setRawHeader("Accept-Encoding", "gzip,deflate,sdch");
//    request.setRawHeader("Referer", "http://m.weibo.cn/login");
    request.setRawHeader("Referer", "https://passport.weibo.cn/signin/login?entry=mweibo&res=wel&wm=3349&r=http%3A%2F%2Fm.weibo.cn%2F");
    request.setRawHeader("Cookie", TokenProvider::instance ()->hackLoginCookies ().toLatin1 ());

    QByteArray data;
    data.append (QString("username=%1").arg (m_userName));
    data.append (QString("&password=%1").arg (m_passWord));
    data.append (QString("&savestate=1"));
    data.append (QString("&ec=0"));
    data.append (QString("&pagerefer=https://passport.weibo.cn/signin/welcome?entry=mweibo&r=http%3A%2F%2Fm.weibo.cn%2F&wm=3349&vt=4"));
    data.append (QString("&entry=mweibo"));
    data.append (QString("&wentry="));
    data.append (QString("&loginfrom="));
    data.append (QString("&client_id="));
    data.append (QString("&code="));
    data.append (QString("&qq="));
    data.append (QString("&hff="));
    data.append (QString("&hfp="));
    data.append (QString("&pincode=%1").arg (m_captcha));
    data.append (QString("&pcid=%1").arg (m_pcid));


    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));

    qDebug()<<Q_FUNC_INFO<<"post to url ["<<url<<"] with data ["<<data<<"]";

    if (m_reply) {
        m_requestAborted = true;
        m_reply->abort ();
    }
    m_reply = m_networkMgr->post (request, data);

    m_timeout->start (m_timerInterval);

    if (m_reply) {
        QObject::connect (m_reply, &QNetworkReply::finished,
                 [&](){
            if (m_timeout->isActive ())
                m_timeout->stop ();

            if (m_requestAborted) {
                m_requestAborted = false;
                m_reply->deleteLater ();
                m_reply = nullptr;
                qDebug()<<Q_FUNC_INFO<<"network request aborted previous";
                return;
            }
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            if (!success) {
                QString str = m_reply->errorString ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit loginFailure (str);
            } else {
                QByteArray qba = m_reply->readAll ();
                qDebug()<<Q_FUNC_INFO<<"ret "<<qba;
                m_reply->deleteLater ();
                m_reply = nullptr;

                QJsonParseError error;
                QJsonDocument doc = QJsonDocument::fromJson (qba, &error);
                if (error.error != QJsonParseError::NoError) {
                    qDebug()<<Q_FUNC_INFO<<"Parse json error => "<<error.errorString ();
                    emit loginFailure (error.errorString ());
                    return;
                }
                QJsonObject obj = doc.object ();
                int retcode = obj.value ("retcode").toInt (-1);
                if (retcode != 20000000) {
                    emit loginFailure (QString("retcode = %1").arg (retcode));
                    return;
                }
                QJsonValue v = obj.value ("data");
                obj = v.toObject ();
                QString uid = obj.value ("uid").toString ();
                if (uid.isEmpty ()) {
                    emit loginFailure ("UID is empty");
                    return;
                }
                TokenProvider::instance ()->setHackLoginUid (uid);
                emit loginSuccess ();
            }
        });
    } else {
        qDebug()<<Q_FUNC_INFO<<"no reply";
        emit loginFailure ("No QNetworkReply");
    }
}

QUrl CookieDataProvider::captchaImgUrl() const
{
    return QUrl(m_captchaImgUrl);
}

QString CookieDataProvider::userName() const
{
    return m_userName;
}

QString CookieDataProvider::passWord() const
{
    return m_passWord;
}

void CookieDataProvider::setCaptcha(QString captcha)
{
    if (m_captcha == captcha)
        return;

    m_captcha = captcha;
    emit captchaChanged(captcha);
}

void CookieDataProvider::setUserName(QString userName)
{
    if (m_userName == userName)
        return;

    m_userName = userName;
    emit userNameChanged(userName);
}

void CookieDataProvider::setPassWord(QString passWord)
{
    if (m_passWord == passWord)
        return;

    m_passWord = passWord;
    emit passWordChanged(passWord);
}

} //HackLogin
} //QWeiboSDK

