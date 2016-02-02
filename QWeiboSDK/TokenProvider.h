#ifndef TOKENPROVIDER_H
#define TOKENPROVIDER_H

#include <QObject>
#include <QList>
#include <QHash>

#include "global.h"
#include "SingletonPointer.h"

class QSettings;
class QNetworkCookie;

namespace QWeiboSDK {

class Oauth2GetTokenInfo;
class QWEIBOSDK_EXPORT TokenProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString accessToken READ accessToken WRITE setAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(QString refreshToken READ refreshToken WRITE setRefreshToken NOTIFY refreshTokenChanged)
    Q_PROPERTY(QString uid READ uid WRITE setUid NOTIFY uidChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString passWord READ passWord WRITE setPassWord NOTIFY passWordChanged)
    Q_PROPERTY(QString expiresData READ expiresData WRITE setExpiresData NOTIFY expiresDataChanged)
    Q_PROPERTY(QString hackLoginCookies READ hackLoginCookies NOTIFY hackLoginCookiesChanged)
    Q_PROPERTY(bool useHackLogin READ useHackLogin WRITE setUseHackLogin NOTIFY useHackLoginChanged)

    DECLARE_SINGLETON_POINTER(TokenProvider)
public:
//    explicit TokenProvider(QObject *parent = 0);
    virtual ~TokenProvider();
    Q_INVOKABLE void checkToken(const QString &token);
    QString accessToken() const;
    QString uid() const;
    QString userName() const;
    QString passWord() const;
    QString refreshToken() const;
    QString expiresData() const;
    QString hackLoginCookies() const;
    void setHackLoginCookies(const QList<QNetworkCookie> &list);
    bool useHackLogin() const;

public slots:
    void setAccessToken(const QString &arg);
    void setUid(const QString &arg);
    void setUserName(const QString &arg);
    void setPassWord(const QString &arg);
    void setRefreshToken(const QString &refreshToken);
    void setExpiresData(const QString &expiresData);
    void setUseHackLogin(bool useHackLogin);

signals:
    void accessTokenChanged(const QString &token);
    void uidChanged(const QString &uid);
    void userNameChanged(const QString &userName);
    void passWordChanged(const QString &passWord);
    void tokenExpired(bool tokenExpired);
    void refreshTokenChanged(QString refreshToken);
    void expiresDataChanged(QString expiresData);
    void hackLoginCookiesChanged(QString hackLoginCookies);
    void useHackLoginChanged(bool useHackLogin);

private:
    QSettings *m_settings;
    QString m_accessToken;
    QString m_uid;
    QString m_userName;
    QString m_passWord;
    QString m_refreshToken;
    QString m_expiresData;
    Oauth2GetTokenInfo *m_tokenInfo;
    QString m_hackLoginCookies;
    bool m_useHackLogin;
    QHash<QString, QString> m_cookiesHash;
};
} //QWeiboSDK
#endif // TOKENPROVIDER_H
