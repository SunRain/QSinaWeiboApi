#include "HackStatuses.h"

namespace QWeiboSDK {
namespace HackLogin {
HackStatusesFriendsTimeline::HackStatusesFriendsTimeline(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("index/feed", "");
    initiate ();
}

HackStatusesRepostTimeline::HackStatusesRepostTimeline(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("single/rcList", "");
    initiate ();
}

HackStatusesUpdate::HackStatusesUpdate(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("mblogDeal/addAMblog", "");
    initiate ();
}

HackStatusesRepost::HackStatusesRepost(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("mblogDeal/rtMblog", "");
    initiate ();
}

HackStatusesMentions::HackStatusesMentions(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("msg/atme", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
