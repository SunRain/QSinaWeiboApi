#ifndef BASEWRAPPER
#define BASEWRAPPER

#include <QObject>
#include "global.h"


namespace QWeiboSDK {
class BaseRequest;
class TokenProvider;
namespace Wrapper {

class QWEIBOSDK_EXPORT BaseWrapper : public QObject
{
    Q_OBJECT
public:
    BaseWrapper(QObject *parent = 0);
    virtual ~BaseWrapper();
    Q_INVOKABLE void setParameters(const QString &key, const QString &value);

protected:
    BaseRequest *request() const;
    void setRequest(BaseRequest *request);
    bool useHackLogin() const;
    virtual QString parseContent(const QString &content);

signals:
    void requestSuccess(const QString &replyData);
    void requestFailure(const QString &replyData);
    void requestAbort();
    void useHackLoginChanged();

public slots:
    void postRequest();
    void getRequest();
private:
    BaseRequest *m_request;
    TokenProvider *m_tokenProvider;
    bool m_useHackLogin;
};

} //Wrapper
} //QWeiboSDK
#endif // BASEWRAPPER

