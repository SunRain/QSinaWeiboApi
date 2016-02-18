#ifndef HACKREMIND_H
#define HACKREMIND_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

//未读私信 get http://m.weibo.cn/unread?t=1455297987840
/*****
{"qp":{"pl":1,"sx":3，"new":2},"ht":{"pl":1,"sx":3}}
pl 评论
sx 私信
new 新微博
fs 粉丝
 ******/
class QWEIBOSDK_EXPORT HackRemindUnreadCount : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackRemindUnreadCount(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("t", "") //似乎是任意一个13位的随机数, unix时间戳?
        ;
    }
};

} //HackLogin
} //QWeiboSDK

#endif // HACKREMIND_H
