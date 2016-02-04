#ifndef FRIENDSHIPSGROUPSWRAPPER_H
#define FRIENDSHIPSGROUPSWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

#include "htmlcxx/html/tree.h"
#include "htmlcxx/html/ParserDom.h"
#include "htmlcxx/html/Node.h"

namespace QWeiboSDK {
namespace Wrapper {

class QWEIBOSDK_EXPORT FriendshipsGroupsTimelineWrapper : public BaseWrapper
{
    Q_OBJECT
public:
    explicit FriendshipsGroupsTimelineWrapper(QObject *parent = 0);

protected:
    QString parseContent(const QString &content);
};

} //Wrapper
} //QWeiboSDK
#endif // FRIENDSHIPSGROUPSWRAPPER_H
