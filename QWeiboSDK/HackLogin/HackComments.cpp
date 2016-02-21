#include "HackComments.h"

namespace QWeiboSDK {
namespace HackLogin {

HackCommentsShow::HackCommentsShow(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("single/rcList", "");
    initiate ();
}

HackCommentsReply::HackCommentsReply(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("commentDeal/replyComment", "");
    initiate ();
}

HackCommentsCreate::HackCommentsCreate(QObject *parent)
     : BaseHackRequest(parent)
{
    setUrlPath ("commentDeal/addCmt", "");
    initiate ();
}


} //HackLogin
} //QWeiboSDK
