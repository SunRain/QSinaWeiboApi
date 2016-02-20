#include "HackStatuses.h"

namespace QWeiboSDK {
namespace HackLogin {
HackStatusesFriendsTimeline::HackStatusesFriendsTimeline(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("index/feed", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
