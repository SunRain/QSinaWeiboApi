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

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ;
    }
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
//        ("cookie", "")
//        ("title", "")
        ("gid", "")
        ("page", "1")
        ("format", "cards")
        ;
    }
};

//创建分组 post http://m.weibo.cn/attGroupsDeal/createAndAddGroup &uid=0000000000&gname=foo2
class QWEIBOSDK_EXPORT HackFriendshipsGroupsCreate : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFriendshipsGroupsCreate(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        //gid=3718227991570528&rl=0
        (*this)
        ("uid", "0000000000")
        ("gname", "")
        ;
    }
};

//删除分组 get http://weibo.cn/attgroup/destroy?save=1&gid=3941862396198197
class QWEIBOSDK_EXPORT HackFriendshipsGroupsDestroy : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFriendshipsGroupsDestroy(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        //gid=3718227991570528&rl=0
        (*this)
        ("save", "1") //必须为1，是确认删除的对话框选择项
        ("gid", "") //group id
        ;
    }
};
} //HackLogin
} //QWeiboSDK

#endif // HACKFRIENDSHIPSGROUPS_H
