#ifndef FRIENDSHIPSGROUPSWRAPPER_H
#define FRIENDSHIPSGROUPSWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

#include "htmlcxx/html/tree.h"
#include "htmlcxx/html/ParserDom.h"
#include "htmlcxx/html/Node.h"

namespace QWeiboSDK {
class BaseRequest;

namespace Wrapper {

class QWEIBOSDK_EXPORT FriendshipsGroupsTimelineWrapper : public BaseWrapper
{
    Q_OBJECT
public:
    explicit FriendshipsGroupsTimelineWrapper(QObject *parent = 0);

protected:
    QString parseContent(const QString &content);

private:
    BaseRequest *m_request;
};

} //Wrapper
} //QWeiboSDK
#endif // FRIENDSHIPSGROUPSWRAPPER_H
