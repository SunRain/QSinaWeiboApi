#ifndef HACKSTATUSES_H
#define HACKSTATUSES_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

//get http://m.weibo.cn/index/feed?format=cards
class QWEIBOSDK_EXPORT HackStatusesFriendsTimeline : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackStatusesFriendsTimeline(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("page", "1")
//        ("maxPage", "50") //return 10 items per page
        ("format", "cards")
        ;
    }
};

} //HackLogin
} //QWeiboSDK
#endif // HACKSTATUSES_H
