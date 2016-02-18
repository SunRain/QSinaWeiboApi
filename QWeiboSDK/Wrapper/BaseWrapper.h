#ifndef BASEWRAPPER
#define BASEWRAPPER

#include <QObject>
#include "global.h"
#include "TokenProvider.h"
#include "BaseRequest.h"

namespace QWeiboSDK {

namespace HackLogin {
class HackRequestCookieJar;
}
namespace Wrapper {
class QWEIBOSDK_EXPORT BaseWrapper : public QObject
{
    Q_OBJECT
public:
    BaseWrapper(QObject *parent = 0);
    virtual ~BaseWrapper();
    Q_INVOKABLE void setParameters(const QString &key, const QString &value);
    void appendExtraRequestCookie(HackLogin::HackRequestCookieJar *cookieJar);

protected:
    inline bool useHackLogin() const {
        return m_useHackLogin;
    }
    virtual QString convertParameterKey(const QString &key);
    virtual QString parseContent(const QString &content);

    template <class Base, class Hack>
    void registerRequest() {
        if (m_request) {
            //setRequest to nullptr to call to disconnect all request connections
            setRequest (nullptr);
            m_request->deleteLater ();
        }
        m_request = nullptr;

        if (m_useHackLogin)
            setRequest (new Hack(this));
        else
            setRequest (new Base(this));

        connect (m_tokenProvider, &TokenProvider::useHackLoginChanged,
                 [&](bool changed){
            Q_UNUSED(changed)

            m_useHackLogin = m_tokenProvider->useHackLogin ();

            if (m_request) {
                //setRequest to nullptr to call to disconnect all request connections
                setRequest (nullptr);
                m_request->deleteLater ();
            }
            m_request = nullptr;

            if (m_useHackLogin) {
                setRequest (new Hack(this));
                if (m_cookieJar)
                    appendExtraRequestCookie (m_cookieJar);
            } else {
                setRequest (new Base(this));
            }
        });
    }

signals:
    void requestSuccess(const QString &replyData);
    void requestFailure(const QString &replyData);
    void requestAbort();
    void requestResult(BaseRequest::RequestRet ret, const QString &replyData);
public slots:
    void postRequest();
    void getRequest();

private:
    void setRequest(BaseRequest *request);
private:
    BaseRequest *m_request;
    TokenProvider *m_tokenProvider;
    HackLogin::HackRequestCookieJar *m_cookieJar;
    bool m_useHackLogin;
};

} //Wrapper
} //QWeiboSDK
#endif // BASEWRAPPER

