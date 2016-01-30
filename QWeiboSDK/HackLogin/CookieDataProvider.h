#ifndef COOKIEDATAPROVIDER_H
#define COOKIEDATAPROVIDER_H

#include <QObject>
#include <QUrl>

class QTimer;
class QNetworkAccessManager;
class QNetworkReply;

namespace QWeiboSDK {
namespace HackLogin {

class LoginCookieJar;
class CookieDataProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString captcha WRITE setCaptcha  NOTIFY captchaChanged)
    Q_PROPERTY(QUrl captchaImgUrl READ captchaImgUrl NOTIFY captchaImgUrlChanged)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString passWord READ passWord WRITE setPassWord NOTIFY passWordChanged)
public:
    explicit CookieDataProvider(QObject *parent = 0);
    virtual ~CookieDataProvider();
    Q_INVOKABLE void preLogin();
    Q_INVOKABLE void login();

    QUrl captchaImgUrl() const;
    QString userName() const;
    QString passWord() const;
signals:
    void preLoginSuccess();
    void preLoginFailure(QString str);
    void captchaChanged(QString captcha);
    void captchaImgUrlChanged(QUrl captchaImgUrl);
    void userNameChanged(QString userName);
    void passWordChanged(QString passWord);
public slots:
    void setCaptcha(QString captcha);
    void setUserName(QString userName);
    void setPassWord(QString passWord);
private:
    void preLoginParse(const QByteArray &values);
private:
    QNetworkAccessManager *m_networkMgr;
    QNetworkReply *m_reply;
    QTimer *m_timeout;
    LoginCookieJar *m_cookieJar;
    bool m_requestAborted;
    int m_timerInterval;
    QString m_userName;
    QString m_passWord;
    QString m_rand;
    QString m_headerPassWord;
    QString m_vk;
    QString m_backTitle;
    QString m_submit;
    QString m_capId;
    QString m_captcha;
    QString m_captchaImgUrl;
};
} //HackLogin
} //QWeiboSDK

#endif // COOKIEDATAPROVIDER_H
