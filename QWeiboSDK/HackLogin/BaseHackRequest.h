#ifndef BASEHACKREQUEST_H
#define BASEHACKREQUEST_H

#include <QObject>

#include "global.h"
#include "BaseRequest.h"

namespace QWeiboSDK {
namespace HackLogin {
class QWEIBOSDK_EXPORT BaseHackRequest : public BaseRequest
{
    Q_OBJECT
public:
    explicit BaseHackRequest(QObject *parent = 0);
    virtual ~BaseHackRequest();

    // BaseRequest interface
protected:
    virtual void initParameters();
    QNetworkReply *curNetworkReply();
public slots:
    void postRequest();
    void getRequest();

private:
    QNetworkReply *m_reply;
};
} //HackLogin
} //QWeiboSDK
#endif // BASEHACKREQUEST_H
