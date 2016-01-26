#include "LoginProvider.h"

#include <iostream>
#include <stdio.h>

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QUrl>
#include <QUrlQuery>
#include <QByteArray>

#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTimer>

#include <openssl/crypto.h>
#include <openssl/rsa.h>
#include <openssl/ossl_typ.h>
#include <openssl/bn.h>

#include "Key.h"

const char *PRELOGIN_URL = "https://login.sina.com.cn/sso/prelogin.php";
const char *LOGIN_URL = "https://login.sina.com.cn/sso/login.php";
const char *AUTHORIZE_URL = "https://api.weibo.com/oauth2/authorize";
const char *ACCESS_TOKEN_URL = "https://api.weibo.com/oauth2/access_token";

LoginProvider::LoginProvider(QObject *parent)
    :QObject(parent)
    ,m_authorizeCode(QString())
{
    m_networkMgr = new QNetworkAccessManager(this);
    m_userName = QString(USERNAME);
    m_passWord = QString(PASSWORD);

}

LoginProvider::~LoginProvider()
{

}

void LoginProvider::requestAuthorizeCode()
{
    QUrl url(PRELOGIN_URL);
    QUrlQuery query;
//    'entry': 'openapi',
//    'callback': 'sinaSSOController.preloginCallBack',
//    'rsakt': 'mod',
//    'client': 'ssologin.js(v1.4.15)',
//    'su': '',
    query.addQueryItem ("entry","openapi");
    query.addQueryItem ("callback", "sinaSSOController.preloginCallBack");
    query.addQueryItem ("rsakt", "mod");
    query.addQueryItem ("client", "ssologin.js(v1.4.15)");
    query.addQueryItem ("su", QByteArray(USERNAME).toBase64 (QByteArray::Base64UrlEncoding));
    url.setQuery (query);
    qDebug()<<Q_FUNC_INFO<<"request url "<<url;
    QNetworkRequest request(url);
    QNetworkReply *replay = m_networkMgr->get (request);
    if (replay) {
        QTimer t;
        QEventLoop loop;

        connect (replay, &QNetworkReply::finished,
                 [&](){
            t.stop ();
            qDebug()<<Q_FUNC_INFO<<"replay for url "<<replay->url ();
            if (replay->error () == QNetworkReply::NoError) {
                QString data = QString(replay->readAll ());
                qDebug()<<Q_FUNC_INFO<<"get data ["<<data<<"]";
                formatPreLogin (data);
            } else {
                qDebug()<<Q_FUNC_INFO<<"error is "<<replay->errorString ();
            }
            replay->deleteLater ();
            replay = nullptr;
//            t.stop ();
        });
        connect (&t, &QTimer::timeout,
                 [&]() {
            qDebug()<<Q_FUNC_INFO<<"timer out";
            t.stop ();
            loop.quit ();
        });
        t.setSingleShot (false);
        t.start (5000);
        loop.exec ();
    }
}

void LoginProvider::formatPreLogin(const QString &data)
{
    QString str = QString(data);
    str = str.replace ("sinaSSOController.preloginCallBack(", "");
    str = str.left (str.length () - 1);
    QJsonDocument json = QJsonDocument::fromJson (str.toLocal8Bit ());
    QJsonObject preloginObj = json.object ();

    qDebug()<<Q_FUNC_INFO<<"check obj , is empty "<<preloginObj.isEmpty ();

    QString strPubkey = preloginObj.value ("pubkey").toString ();

    qDebug()<<Q_FUNC_INFO<<"pubkey value "<<strPubkey<<" length "<<strPubkey.length ();

//    BIGNUM  bn;
//    BIGNUM *bnn = &bn;// = new BIGNUM();
//    int ret = BN_hex2bn(&bnn, strPubkey.toLocal8Bit ().constData ());
//    qDebug()<<Q_FUNC_INFO<<"nret "<<ret;

//    unsigned long e = 0x10001;
//    BIGNUM bn2;
//    BIGNUM *bne = &bn2;// = new BIGNUM();
//    ret = BN_set_word(bne, e);
//    qDebug()<<Q_FUNC_INFO<<"eret "<<ret;

//    RSA *rsaObj = RSA_new();
//    rsaObj->n = bnn;
//    rsaObj->e = bne;
//    rsaObj->d = nullptr;
//    int flen = RSA_size (rsaObj);
//    qDebug()<<Q_FUNC_INFO<<"RSA flen "<<flen;

    QString plainStr = QString("%1\t%2\n%3")
            .arg (preloginObj.value ("servertime").toInt ())
            .arg (preloginObj.value ("nonce").toString ())
            .arg (QString(PASSWORD));
    QByteArray plainData = plainStr.toUtf8 ();
    qDebug()<<Q_FUNC_INFO<<"toUtf8 plainStr ["<<plainData<<"] size "<<plainStr.size ();

////    int RSA_public_encrypt(int flen, const unsigned char *from,
////                           unsigned char *to, RSA *rsa, int padding);
//    unsigned char *to = (unsigned char *)malloc (flen + 1);
//    memset (to, 0, flen+1);
//    int eret = RSA_public_encrypt (flen,
//                                   (unsigned char *)plainData.constData (),
//                                   to, rsaObj, RSA_NO_PADDING);
//    qDebug()<<Q_FUNC_INFO<<"eret ["<<eret<<"], data ["<<to<<"]";

    BIGNUM *bne = BN_new ();
//    BIGNUM *bnd = BN_new ();
    BIGNUM *bnn = BN_new ();

    unsigned long e = 65537;
    int  ret = BN_set_word(bne, e);
    qDebug()<<Q_FUNC_INFO<<"eret "<<ret;

    ret = BN_hex2bn (&bnn, strPubkey.toLatin1 ().constData ());
    qDebug()<<Q_FUNC_INFO<<"nret "<<ret<<" bnn length "<<bnn->dmax;
//    QString s;
//    for(int i=0;i<bnn->dmax;++i) {
//        s.append (QString::number (bnn->d[i]));
//    }
//    qDebug()<<Q_FUNC_INFO<<"bnn  str "<<s;

    RSA *rsaObj = RSA_new();
    rsaObj->n = bnn;
    rsaObj->e = bne;
    rsaObj->d = nullptr;

    RSA_print_fp(stdout, rsaObj, 5);

    int flen = RSA_size (rsaObj);
    qDebug()<<Q_FUNC_INFO<<"RSA flen "<<flen;


    unsigned char *to = (unsigned char *)malloc (flen + 1);
    memset (to, 0, flen+1);
    int eret = RSA_public_encrypt (flen,
                                   (unsigned char *)plainData.constData (),
                                   to, rsaObj, RSA_NO_PADDING);

    qDebug()<<Q_FUNC_INFO<<"eret ["<<eret<<"], data ["<<to<<"]";

    QUrl url(LOGIN_URL);
    QUrlQuery query;
//    LOGIN_PARAMETER = {
//        'entry': 'openapi',
//        'gateway': '1',
//        'from': '',
//        'savestate': '0',
//        'useticket': '1',
//        'vsnf': '1',
//        'vsnval': '',
//        'door': '',
//        'scope': '',  # scope of the application
//        'su': '',
//        'service': 'miniblog',
//        'servertime': '',
//        'nonce': '',
//        'pwencode': 'rsa2',
//        'rsakv': '',
//        'sp': '',
//        'encoding': 'UTF-8',
//        'cdult': '2',
//        'domain': 'weibo.com',
//        'prelt': '1609',
//        'returntype': 'TEXT',
//    }
    query.addQueryItem ("client","ssologin.js(v1.4.15)");
    query.addQueryItem ("entry", "openapi");
    query.addQueryItem ("gateway", "1");
    query.addQueryItem ("from", "");
    query.addQueryItem ("savestate", "0");
    query.addQueryItem ("useticket", "1");
    query.addQueryItem ("vsnf", "1");
    query.addQueryItem ("vsnval", "");
    query.addQueryItem ("door", "");
    query.addQueryItem ("scope", "");
    query.addQueryItem ("su", QByteArray(USERNAME).toBase64 (QByteArray::Base64UrlEncoding));
    query.addQueryItem ("service", "miniblog");
    query.addQueryItem ("servertime", QString::number (preloginObj.value ("servertime").toInt ()));
    query.addQueryItem ("nonce", preloginObj.value ("nonce").toString ());
    query.addQueryItem ("pwencode", "rsa2");
    query.addQueryItem ("rsakv", preloginObj.value ("rsakv").toString ());
    query.addQueryItem ("sp", QByteArray((const char*)to).toHex ().toBase64 (QByteArray::Base64UrlEncoding));
    query.addQueryItem ("encoding", "UTF-8");
    query.addQueryItem ("cdult", "2");
    query.addQueryItem ("domain", "weibo.com");
    query.addQueryItem ("prelt", "1609");
    query.addQueryItem ("returntype", "TEXT");
    url.setQuery (query);
    qDebug()<<Q_FUNC_INFO<<"request url "<<url;
    QByteArray dd;//(url.query ().toLatin1 ());
    dd.append (url.query (QUrl::FullyEncoded));

    qDebug()<<Q_FUNC_INFO<<"data "<<dd;

    QNetworkRequest request(url);
    request.setHeader (QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(dd.length()));
    QNetworkReply *replay = m_networkMgr->post (request, dd);
    if (replay) {
        QTimer t;
        QEventLoop loop;

        connect (replay, &QNetworkReply::finished,
                 [&](){
            qDebug()<<Q_FUNC_INFO<<"post replay for url "<<replay->url ();
            if (replay->error () == QNetworkReply::NoError) {
                QString data = QString(replay->readAll ());
                qDebug()<<Q_FUNC_INFO<<"post data ["<<data<<"]";
            } else {
                qDebug()<<Q_FUNC_INFO<<"error is "<<replay->errorString ();
            }
            replay->deleteLater ();
            replay = nullptr;
            t.stop ();
        });
        connect (&t, &QTimer::timeout,
                 [&]() {
            qDebug()<<Q_FUNC_INFO<<"timer out";
            t.stop ();
            loop.quit ();
        });
        t.setSingleShot (false);
        t.start (5000);
        loop.exec ();
    }
}
