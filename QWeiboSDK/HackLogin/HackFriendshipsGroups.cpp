#include "HackFriendshipsGroups.h"

namespace QWeiboSDK {
namespace HackLogin {

HackFriendshipsGroupsTimeline::HackFriendshipsGroupsTimeline(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("attgroup/index", "");
}

} //HackLogin
} //QWeiboSDK
