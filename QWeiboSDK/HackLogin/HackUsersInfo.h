#ifndef HACKUSERSINFO_H
#define HACKUSERSINFO_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

//get http://m.weibo.cn/home/me?format=cards
class QWEIBOSDK_EXPORT HackUsersInfoMe : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackUsersInfoMe(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ;
    }
};

//get http://m.weibo.cn/u/1494848464?format=cards
//need use resetUrlPath()
class QWEIBOSDK_EXPORT HackUsersInfo : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackUsersInfo(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ;
    }
};


} //HackLogin
} //QWeiboSDK
#endif // HACKUSERSINFO_H
