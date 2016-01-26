#ifndef LOGINPROVIDER_H
#define LOGINPROVIDER_H

#include <QObject>

class QNetworkAccessManager;
class QByteArray;

class LoginProvider : public QObject
{
    Q_OBJECT
public:
    explicit LoginProvider(QObject *parent = 0);
    virtual ~LoginProvider();

    void requestAuthorizeCode();
    void formatPreLogin(const QString &data);
private:
    QNetworkAccessManager *m_networkMgr;

    QString m_userName;
    QString m_passWord;
    QString m_authorizeCode;
};

#endif // LOGINPROVIDER_H
