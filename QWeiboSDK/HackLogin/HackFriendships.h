#ifndef HACKFRIENDSHIPS_H
#define HACKFRIENDSHIPS_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

//post http://m.weibo.cn/attentionDeal/addAttention?uid=1494848464&st=902a55
class QWEIBOSDK_EXPORT HackFriendshipsCreate : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFriendshipsCreate(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("uid", "")
        ("st", "") //ok if empty
        ;
    }
};

//post http://m.weibo.cn/attentionDeal/delAttention?uid=1494848464
class QWEIBOSDK_EXPORT HackFriendshipsDestroy : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFriendshipsDestroy(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("uid", "")
        ;
    }
};

} //HackLogin
} //QWeiboSDK

#endif // HACKFRIENDSHIPS_H
