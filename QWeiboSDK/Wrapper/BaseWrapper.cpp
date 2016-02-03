#include "BaseWrapper.h"

#include <QDebug>

#include "BaseRequest.h"
#include "TokenProvider.h"

namespace QWeiboSDK {
namespace Wrapper {

BaseWrapper::BaseWrapper(QObject *parent)
    : QObject(parent)
    , m_request(nullptr)
    , m_tokenProvider(TokenProvider::instance ())
{
    m_useHackLogin = m_tokenProvider->useHackLogin ();
    connect (m_tokenProvider, &TokenProvider::useHackLoginChanged,
             [&](bool changed){
        Q_UNUSED(changed)
        m_useHackLogin = m_tokenProvider->useHackLogin ();
        emit useHackLoginChanged ();
    });
}

BaseWrapper::~BaseWrapper()
{
    if (m_request)
        m_request->deleteLater ();
}

void BaseWrapper::setParameters(const QString &key, const QString &value)
{
    if (!request ()) {
        qWarning()<<Q_FUNC_INFO<<"BaseRequest is nullptr, can't set parameters!!!!";
        return;
    }
    request ()->setParameters (key, value);
}

BaseRequest *BaseWrapper::request() const
{
    return m_request;
}

void BaseWrapper::setRequest(BaseRequest *request)
{
    if (m_request && m_request != request) {
        disconnect (m_request, &BaseRequest::requestAbort, this, &BaseWrapper::requestAbort);
        disconnect (m_request, &BaseRequest::requestFailure, this, &BaseWrapper::requestFailure);
//        disconnect (m_request, &BaseRequest::requestSuccess);
    }
    m_request = request;
    if (m_request) {
        connect (m_request, &BaseRequest::requestAbort, this, &BaseWrapper::requestAbort);
        connect (m_request, &BaseRequest::requestFailure, this, &BaseWrapper::requestFailure);
        connect (m_request, &BaseRequest::requestSuccess,
                 [&](const QString &replyData){
            QString str = parseContent (replyData);
            qDebug()<<Q_FUNC_INFO<<"requestSuccess "<<str;
            emit requestSuccess (str);
        });
    }
}

bool BaseWrapper::useHackLogin() const
{
    return m_useHackLogin;
}

QString BaseWrapper::parseContent(const QString &content)
{
    Q_UNUSED(content)
    qDebug()<<Q_FUNC_INFO<<">>>>>> parseContent <<<<<<";
    return QString();
}

void BaseWrapper::postRequest()
{
    if (m_request)
        m_request->postRequest ();
}

void BaseWrapper::getRequest()
{
    if (m_request)
        m_request->getRequest ();
}


} //Wrapper
} //QWeiboSDK

