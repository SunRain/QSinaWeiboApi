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

////2/friendships/groups: 获取当前登陆用户好友分组列表
class QWEIBOSDK_EXPORT FriendshipsGroupsWrapper : public BaseWrapper
{
    Q_OBJECT
public:
    explicit FriendshipsGroupsWrapper(QObject *parent = 0);

protected:
    QString parseContent(const QString &content);
};

} //Wrapper
} //QWeiboSDK
#endif // FRIENDSHIPSGROUPSWRAPPER_H
