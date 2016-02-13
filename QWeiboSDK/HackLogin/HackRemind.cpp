#include "HackRemind.h"

namespace QWeiboSDK {
namespace HackLogin {

HackRemindUnreadCount::HackRemindUnreadCount(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("unread", "");
    initiate ();
}



} //HackLogin
} //QWeiboSDK
