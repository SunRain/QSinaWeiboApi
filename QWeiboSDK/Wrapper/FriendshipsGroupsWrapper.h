#ifndef FRIENDSHIPSGROUPSWRAPPER_H
#define FRIENDSHIPSGROUPSWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

namespace QWeiboSDK {
namespace Wrapper {

//2/friendships/groups: 获取当前登陆用户好友分组列表
class QWEIBOSDK_EXPORT WrapperFriendshipsGroups : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperFriendshipsGroups(QObject *parent = 0);

protected:
    QString parseContent(const QString &content);
};

//2/friendships/groups/timeline: 获取某一好友分组的微博列表
class QWEIBOSDK_EXPORT WrapperFriendshipsGroupsTimeline : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperFriendshipsGroupsTimeline(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString parseContent(const QString &content);
    QString convertParameterKey(const QString &key);
};

} //Wrapper
} //QWeiboSDK
#endif // FRIENDSHIPSGROUPSWRAPPER_H
