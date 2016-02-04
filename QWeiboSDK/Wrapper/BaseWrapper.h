#ifndef BASEWRAPPER
#define BASEWRAPPER

#include <QObject>
#include "global.h"
#include "TokenProvider.h"
#include "BaseRequest.h"

namespace QWeiboSDK {
namespace Wrapper {

class QWEIBOSDK_EXPORT BaseWrapper : public QObject
{
    Q_OBJECT
public:
    BaseWrapper(QObject *parent = 0);
    virtual ~BaseWrapper();
    Q_INVOKABLE void setParameters(const QString &key, const QString &value);

protected:
    virtual QString parseContent(const QString &content);

    template <class Base, class Hack>
    void registerRequest() {
        if (m_useHackLogin)
            m_request = new Hack(this);
        else
            m_request = new Base(this);

        setRequest (m_request);

        connect (m_tokenProvider, &TokenProvider::useHackLoginChanged,
                 [&](bool changed){
            Q_UNUSED(changed)
            qDebug()<<Q_FUNC_INFO<<"****";

            m_useHackLogin = m_tokenProvider->useHackLogin ();

            //setRequest to nullptr to call to disconnect all request connections
            setRequest (nullptr);

            if (m_request)
                m_request->deleteLater ();
            m_request = nullptr;

            if (m_useHackLogin)
                m_request = new Hack(this);
            else
                m_request = new Base(this);

            setRequest (m_request);
        });
    }

signals:
    void requestSuccess(const QString &replyData);
    void requestFailure(const QString &replyData);
    void requestAbort();

public slots:
    void postRequest();
    void getRequest();

private:
    void setRequest(BaseRequest *request);
private:
    BaseRequest *m_request;
    TokenProvider *m_tokenProvider;
    bool m_useHackLogin;
};

} //Wrapper
} //QWeiboSDK
#endif // BASEWRAPPER

