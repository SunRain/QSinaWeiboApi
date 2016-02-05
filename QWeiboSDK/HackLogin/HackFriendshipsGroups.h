#ifndef HACKFRIENDSHIPSGROUPS_H
#define HACKFRIENDSHIPSGROUPS_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {
//2/friendships/groups: 获取当前登陆用户好友分组列表
class QWEIBOSDK_EXPORT HackFriendshipsGroups : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFriendshipsGroups(QObject *parent = 0);
};

//2/friendships/groups/timeline: 获取某一好友分组的微博列表
class QWEIBOSDK_EXPORT HackFriendshipsGroupsTimeline : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFriendshipsGroupsTimeline(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        //gid=3718227991570528&rl=0
        (*this)
        ("gid", "")
        ("rl", "0")
        ("page", 1)
        ;
    }
};


} //HackLogin
} //QWeiboSDK

#endif // HACKFRIENDSHIPSGROUPS_H
