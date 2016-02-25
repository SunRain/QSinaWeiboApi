#include "HackUsersInfo.h"


namespace QWeiboSDK {
namespace HackLogin {

HackUsersInfoMe::HackUsersInfoMe(QObject *parent)
    : BaseHackRequest(parent)
{
    //get http://m.weibo.cn/home/me?format=cards
    setUrlPath ("home/me", "");
    initiate ();
}

HackUsersInfo::HackUsersInfo(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("u/", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
