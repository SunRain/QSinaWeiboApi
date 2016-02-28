#include "HackFriendships.h"

namespace QWeiboSDK {
namespace HackLogin {

HackFriendshipsCreate::HackFriendshipsCreate(QObject *parent)
     : BaseHackRequest(parent)
{
    setUrlPath ("attentionDeal/addAttention", "");
    initiate ();
}

HackFriendshipsDestroy::HackFriendshipsDestroy(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("attentionDeal/delAttention", "");
    initiate ();
}


} //HackLogin
} //QWeiboSDK
