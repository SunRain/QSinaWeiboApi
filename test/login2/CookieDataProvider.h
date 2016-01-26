#ifndef COOKIEDATAPROVIDER_H
#define COOKIEDATAPROVIDER_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;
class CookieDataProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString captcha WRITE setCaptcha  NOTIFY captchaChanged)
    Q_PROPERTY(QString captchaImgUrl READ captchaImgUrl NOTIFY captchaImgUrlChanged)
public:
    explicit CookieDataProvider(QObject *parent = 0);
    virtual ~CookieDataProvider();
    void login();

    QUrl captchaImgUrl() const;

signals:
    void captchaChanged(QString captcha);
    //TODO emit captchaImgUrlChanged
    void captchaImgUrlChanged(QString captchaImgUrl);

public slots:
    void setCaptcha(QString captcha);

private:
    QNetworkAccessManager *m_networkMgr;
    QNetworkReply *m_reply;
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

#endif // COOKIEDATAPROVIDER_H
