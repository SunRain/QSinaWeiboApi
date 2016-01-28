#ifndef BASEREQUEST_H
#define BASEREQUEST_H

#include <QObject>
#include <QMap>

#include "global.h"

class QTimer;
class QNetworkAccessManager;
class QNetworkReply;
namespace QWeiboSDK {

class QWEIBOSDK_EXPORT BaseRequest : public QObject
{
    Q_OBJECT
public:
    explicit BaseRequest(QObject *parent = 0);
    virtual ~BaseRequest();

    void setBaseUrl(const QString &url);

    void initiate();

    Q_INVOKABLE void setParameters(const QString &key, const QString &value);
    Q_INVOKABLE void uploadImage(const QString &status, const QString &fileUrl);

    BaseRequest& operator ()(const QString &key, const QVariant &value);
    BaseRequest& operator ()(const QString &key, const char *value);
    BaseRequest& operator ()(const QString &key, int value);

    void setTimerInterval(int msec);
protected:
    virtual void initParameters();
    void setUrlPath(const QString &urlPath, const QString &tag = QString(".json"));
    QUrl initUrl();

signals:
    void requestSuccess(const QString &replyData);
    void requestFailure(const QString &replyData);
    void requestAbort();
public slots:
    void postRequest();
    void getRequest();
//private slots:
//    void requestFinished();
private:
    bool m_Editable;
    bool m_requestAborted;
    int m_timerInterval;
    QString m_urlPath;
    QString m_baseUrl;
    QMap<QString, QString> m_parameters;
    QNetworkAccessManager *m_networkMgr;
    QNetworkReply *m_reply;
    QTimer *m_timeout;
};
} //QWeiboSDK
#endif // BASEREQUEST_H