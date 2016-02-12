#include "HackFriendshipsGroups.h"

namespace QWeiboSDK {
namespace HackLogin {

HackFriendshipsGroups::HackFriendshipsGroups(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("home/groupList", "");
    initiate ();
}

HackFriendshipsGroupsTimeline::HackFriendshipsGroupsTimeline(QObject *parent)
    : BaseHackRequest(parent)
{
    //http://weibo.cn/attgroup/show?gid=3718227991570528&rl=0
//    setUrlPath ("index/router", "");
    setUrlPath ("index/group", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
