#include "HackFriendshipsGroups.h"

namespace QWeiboSDK {
namespace HackLogin {

HackFriendshipsGroups::HackFriendshipsGroups(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("attgroup/index", "");
}

} //HackLogin
} //QWeiboSDK
