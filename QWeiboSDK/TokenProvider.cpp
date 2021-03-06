#include "TokenProvider.h"

#include <QSettings>
#include <QCoreApplication>
#include <QJsonParseError>
#include <QDebug>
#include <QJsonObject>

#include <QNetworkCookie>

#include "QWeiboRequest.h"

namespace QWeiboSDK {

const char *KEY_TOKEN = "QWeiboSDK/AccessToken";
const char *KEY_UID = "QWeiboSDK/UID";
const char *KEY_REFRESH_TOKEN = "QWeiboSDK/RefreshToken";
const char *KEY_EXPIRES_DATA = "QWeiboSDK/ExpiresData";
const char *KEY_HACKLOGIN_COOKIES = "QWeiboSDK/HackLoginCookies";
const char *KEY_HACKLOGIN_UID = "QWeiboSDK/HackLoginUID";

TokenProvider::TokenProvider(QObject *parent)
    :QObject(parent)
    ,m_userName(QString())
    ,m_passWord(QString())
    ,m_tokenInfo(nullptr)
{
    m_settings = new QSettings(qApp->organizationName (), qApp->applicationName (), parent);
    m_accessToken = m_settings->value (KEY_TOKEN, QString()).toString ();
    m_uid = m_settings->value (KEY_UID, QString()).toString ();
    m_refreshToken = m_settings->value (KEY_REFRESH_TOKEN, QString()).toString ();
    m_expiresData = m_settings->value (KEY_EXPIRES_DATA, QString()).toString ();
    m_hackLoginCookies = m_settings->value (KEY_HACKLOGIN_COOKIES, QString()).toString ();
    m_useHackLogin = !m_hackLoginCookies.isEmpty ();
    m_hackLoginUid = m_settings->value (KEY_HACKLOGIN_UID, QString()).toString ();

    //insert cookies to hashlist to avoid erase stored values in function setHackLoginCookies()
    if (!m_hackLoginCookies.isEmpty ()) {
        foreach (QString str, m_hackLoginCookies.split (";")) {
            QStringList list = str.split ("=");
            if (list.size () == 2)
                m_cookiesHash.insert (list.at (0), list.at (1));
        }
    }
}

TokenProvider::~TokenProvider()
{
    qDebug()<<Q_FUNC_INFO;

    if (m_settings) {
        m_settings->setValue (KEY_TOKEN, m_accessToken);
        m_settings->setValue (KEY_UID, m_uid);
        m_settings->setValue (KEY_EXPIRES_DATA, m_expiresData);
        m_settings->setValue (KEY_REFRESH_TOKEN, m_refreshToken);
        m_settings->sync ();
        m_settings->deleteLater ();
    }
    m_settings = nullptr;
    if (m_tokenInfo)
        m_tokenInfo->deleteLater ();
    m_tokenInfo = nullptr;
}

QString TokenProvider::accessToken() const
{
    return m_accessToken;
}

QString TokenProvider::uid() const
{
    return m_uid;
}

QString TokenProvider::userName() const
{
    return m_userName;
}

QString TokenProvider::passWord() const
{
    return m_passWord;
}

void TokenProvider::checkToken(const QString &token)
{
    if (token.isEmpty ()) {
        emit tokenExpired (true);
        return;
    }
//    Oauth2GetTokenInfo *info = new Oauth2GetTokenInfo(this);
//    info->setParameters ("access_token", token);
    if (!m_tokenInfo) {
        m_tokenInfo = new Oauth2GetTokenInfo(this);

        connect (m_tokenInfo, &Oauth2GetTokenInfo::requestAbort,
                 [&](){
            qDebug()<<Q_FUNC_INFO<<"requestAbort";
            if (m_tokenInfo)
                m_tokenInfo->deleteLater ();
            m_tokenInfo = nullptr;
            emit tokenExpired (true);
        });
        connect (m_tokenInfo, &Oauth2GetTokenInfo::requestFailure,
                 [&](const QString &replyData){
            qDebug()<<Q_FUNC_INFO<<"requestFailure :"<<replyData;
            if (m_tokenInfo)
                m_tokenInfo->deleteLater ();
            m_tokenInfo = nullptr;
            emit tokenExpired (true);
        });
        connect (m_tokenInfo, &Oauth2GetTokenInfo::requestSuccess,
                 [&](const QString &replyData){
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(replyData.toLocal8Bit (), &error);
            if (m_tokenInfo)
                m_tokenInfo->deleteLater ();
            m_tokenInfo = nullptr;

            if (error.error != QJsonParseError::NoError) {
                emit tokenExpired(true);
                return;
            }
            QJsonObject jsonObj = doc.object();
            QJsonValue value = jsonObj.value("expire_in");

            qDebug()<<"=== parseTokenCheckReplyData in  " <<value.toDouble(-1);

            if (value.isUndefined() || value.toDouble(-1) < 1) {
                emit tokenExpired(true);
            } else {
                emit tokenExpired(false);
            }
        });
    }
    m_tokenInfo->setParameters ("access_token", token);
    m_tokenInfo->postRequest ();
}

QString TokenProvider::refreshToken() const
{
    return m_refreshToken;
}

QString TokenProvider::expiresData() const
{
    return m_expiresData;
}

QString TokenProvider::hackLoginCookies() const
{
    return m_hackLoginCookies;
}

void TokenProvider::setHackLoginCookies(const QList<QNetworkCookie> &list)
{
    foreach (QNetworkCookie c, list) {
        m_cookiesHash.insert (QString(c.name ()), QString(c.value ()));
    }
    QStringList values;
    foreach (QString s, m_cookiesHash.keys ()) {
        QString v = QString("%1=%2").arg (s).arg (m_cookiesHash.value (s, QString()));
        values.append (v);
    }
    m_hackLoginCookies = values.join (";");
    m_settings->setValue (KEY_HACKLOGIN_COOKIES, m_hackLoginCookies);
    m_settings->sync ();
    emit hackLoginCookiesChanged (m_hackLoginCookies);
}

void TokenProvider::updateHackLoginCookies(const QList<QNetworkCookie> &list)
{
    bool needUpdate = false;
    foreach (QNetworkCookie c, list) {
        QString pre = m_cookiesHash.value (QString(c.name ()), QString());
        if (pre != QString(c.value ())) {
            needUpdate = true;
            break;
        }
    }
    if (needUpdate)
        setHackLoginCookies (list);
}

bool TokenProvider::useHackLogin()
{
    return m_useHackLogin;
}

QString TokenProvider::hackLoginUid() const
{
    return m_hackLoginUid;
}

void TokenProvider::setAccessToken(const QString &arg)
{
    if (m_accessToken == arg)
        return;
    m_accessToken = arg;
    m_settings->setValue (KEY_TOKEN, m_accessToken);
    m_settings->sync ();
    emit accessTokenChanged(arg);
}

void TokenProvider::setUid(const QString &arg)
{
    if (m_uid == arg)
        return;
    m_uid = arg;
    m_settings->setValue (KEY_UID, m_uid);
    m_settings->sync ();
    emit uidChanged(arg);
}

void TokenProvider::setUserName(const QString &arg)
{
    if (m_userName == arg)
        return;

    m_userName = arg;
    emit userNameChanged(arg);
}

void TokenProvider::setPassWord(const QString &arg)
{
    if (m_passWord == arg)
        return;

    m_passWord = arg;
    emit passWordChanged(arg);
}

void TokenProvider::setRefreshToken(const QString &refreshToken)
{
    if (m_refreshToken == refreshToken)
        return;
    m_refreshToken = refreshToken;
    m_settings->setValue (KEY_REFRESH_TOKEN, m_refreshToken);
    m_settings->sync ();
    emit refreshTokenChanged(refreshToken);
}

void TokenProvider::setExpiresData(const QString &expiresData)
{
    if (m_expiresData == expiresData)
        return;

    m_expiresData = expiresData;
    emit expiresDataChanged(expiresData);
}

void TokenProvider::setUseHackLogin(bool useHackLogin)
{
    if (m_useHackLogin == useHackLogin)
        return;

    m_useHackLogin = useHackLogin;
    emit useHackLoginChanged(useHackLogin);
}

void TokenProvider::setHackLoginUid(QString hackLoginUid)
{
    if (m_hackLoginUid == hackLoginUid)
        return;

    m_hackLoginUid = hackLoginUid;
    m_settings->setValue (KEY_HACKLOGIN_UID, m_hackLoginUid);
    m_settings->sync ();
    emit hackLoginUidChanged(hackLoginUid);
}

} //QWeiboSDK
