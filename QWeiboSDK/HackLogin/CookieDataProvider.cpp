#include "CookieDataProvider.h"

#include <QDebug>

#include <QTimer>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QUrl>
#include <QUrlQuery>

#include <QByteArray>

#include <htmlcxx/html/tree.h>
#include <htmlcxx/html/ParserDom.h>
#include <htmlcxx/html/Node.h>

#include "LoginCookieJar.h"

using namespace htmlcxx;
using namespace std;

//#include "Key.h"

CookieDataProvider::CookieDataProvider(QObject *parent)
    : QObject(parent)
    , m_networkMgr(new QNetworkAccessManager(this))
    , m_reply(nullptr)
    , m_timeout(new QTimer(this))
    , m_cookieJar(new LoginCookieJar(this))
    , m_requestAborted(false)
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
    m_requestAborted = false;

    QUrl url("http://login.weibo.cn/login/");
    QNetworkRequest request(url);
//    request.setRawHeader ("User-Agent", "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:43.0) Gecko/20100101 Firefox/43.0");
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
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
    request.setRawHeader("Referer", "");

    QByteArray data(url.query(QUrl::FullyEncoded).toLatin1());

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));

    qDebug()<<Q_FUNC_INFO<<"post "<<url;

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
                emit preLoginFailure (str);
            } else {
                QByteArray qba = m_reply->readAll ();
                m_reply->deleteLater ();
                m_reply = nullptr;
                preLoginParse (qba);
                if (m_rand.isEmpty () || m_headerPassWord.isEmpty () || m_vk.isEmpty ()
                        || m_backTitle.isEmpty () || m_submit.isEmpty () || m_capId.isEmpty ()) {
                    emit preLoginFailure ("some parameter empty!!");
                } else {
                    emit preLoginSuccess ();
                }
            }
        });
    } else {
        emit preLoginFailure ("no network reply");
    }
}

void CookieDataProvider::login()
{
    m_requestAborted = false;

    QUrl url(QString("http://login.weibo.cn/login/%1").arg (m_rand));
    QNetworkRequest request(url);
//    request.setRawHeader ("User-Agent", "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:43.0) Gecko/20100101 Firefox/43.0");
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
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
    request.setRawHeader("Referer", "");

    QByteArray data;
    data.append (QString("mobile=%1").arg (m_userName));
    data.append (QString("&%1=%2").arg (m_headerPassWord).arg (m_passWord));
    data.append (QString("&remember=on&backURL=http://weibo.cn/"));
    data.append (QString("&backTitle=%1").arg (m_backTitle));
    data.append (QString("&vk=%1").arg (m_vk));
    data.append (QString("&submit=%1").arg (m_submit));
//    data.append (QString("&encoding=utf-8"));
    data.append (QString("&capId=%1").arg (m_capId));
    data.append (QString("&code=%1").arg (m_captcha));

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
            qDebug()<<Q_FUNC_INFO<<"is success "<<success;
            if (!success) {
                QString str = m_reply->errorString ();
                qDebug()<<Q_FUNC_INFO<<"errorString "<<str;
                m_reply->deleteLater ();
                m_reply = nullptr;
                emit preLoginFailure (str);
            } else {
                QByteArray qba = m_reply->readAll ();
                qDebug()<<Q_FUNC_INFO<<"ret "<<qba;
                m_reply->deleteLater ();
                m_reply = nullptr;
            }
        });
    } else {
        qDebug()<<Q_FUNC_INFO<<"no reply";
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

void CookieDataProvider::preLoginParse(const QByteArray &values)
{
    HTML::ParserDom parser;
    tree<HTML::Node> dom = parser.parseTree(QString(values).toStdString ());

    tree<HTML::Node>::iterator domBeg = dom.begin();
    tree<HTML::Node>::iterator domEnd = dom.end();

    QString tmpImgUrl = QString();
    for (; domBeg != domEnd; ++domBeg) {  // 遍历文档中所有的元素
//        qDebug()<<"================================";
//        qDebug()<<"TagName ["<< QString::fromStdString ((*domBeg).tagName ())<<"]"
//               <<" is tag ["<<(*domBeg).isTag ()<<"]";

        if (!(*domBeg).tagName ().compare ("form")) {
            domBeg->parseAttributes();
            m_rand = QString::fromStdString ((*domBeg).attribute ("action").second);
            qDebug()<<"form value second ["<<m_rand<<"]";
        }
        else if (!(*domBeg).tagName ().compare ("a")) {
            domBeg->parseAttributes();
//            qDebug()<<"a value ["<< QString::fromStdString ((*domBeg).attribute ("href").second)<<"]";
        }
        else if (!(*domBeg).tagName ().compare ("img")) {
            domBeg->parseAttributes();
            QString value = QString::fromStdString ((*domBeg).attribute ("src").second);
            if (value.contains ("captcha"))
                tmpImgUrl = value;
        }
        else if (!(*domBeg).tagName ().compare ("input")) {
            domBeg->parseAttributes();
            if (!(*domBeg).attribute ("type").second.compare ("password")) {
                m_headerPassWord = QString::fromStdString ((*domBeg).attribute ("name").second);
                qDebug()<<"a password value ["<<m_headerPassWord<<"]";
            }
            else if (!(*domBeg).attribute ("type").second.compare ("hidden")) {
                QString name = QString::fromStdString ((*domBeg).attribute ("name").second);
                QString value = QString::fromStdString ((*domBeg).attribute ("value").second);
                qDebug()<<"a hidden name ["<< name<<"]"<<" value ["<<value<<"]";
                if (name == QString("vk"))
                    m_vk = value;
                else if (name == QString("backTitle"))
                    m_backTitle = value;
                else if (name == QString("capId"))
                    m_capId = value;
            }
            else if (!(*domBeg).attribute ("type").second.compare ("submit")) {
                QString name = QString::fromStdString ((*domBeg).attribute ("name").second);
                QString value = QString::fromStdString ((*domBeg).attribute ("value").second);
                if (name == QString("submit"))
                    m_submit = value;
                qDebug()<<"a hidden name ["<< name<<"]"<<" value ["<<value<<"]";
            }
        }
    }
    if (m_captchaImgUrl != tmpImgUrl) {
        m_captchaImgUrl = tmpImgUrl;
        qDebug()<<"captchaImgUrl ["<<m_captchaImgUrl<<"]";
        emit captchaImgUrlChanged (QUrl(m_captchaImgUrl));
    }
}

