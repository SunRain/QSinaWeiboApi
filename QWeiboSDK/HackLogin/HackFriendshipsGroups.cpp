#include "HackFriendshipsGroups.h"

namespace QWeiboSDK {
namespace HackLogin {

HackFriendshipsGroups::HackFriendshipsGroups(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("attgroup/index", "");
}

HackFriendshipsGroupsTimeline::HackFriendshipsGroupsTimeline(QObject *parent)
    : BaseHackRequest(parent)
{
    //http://weibo.cn/attgroup/show?gid=3718227991570528&rl=0
    setUrlPath ("attgroup/show", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
