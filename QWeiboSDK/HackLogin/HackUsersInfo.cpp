#include "HackUsersInfo.h"


namespace QWeiboSDK {
namespace HackLogin {

HackUsersInfo::HackUsersInfo(QObject *parent)
    : BaseHackRequest(parent)
{
    //get http://m.weibo.cn/home/me?format=cards
    setUrlPath ("home/me", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
