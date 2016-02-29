#ifndef HACKFRIENDSHIPS_H
#define HACKFRIENDSHIPS_H

#include <QHash>
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

    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        QByteArray ba("http://m.weibo.cn/u/");
        ba += parameter ("uid", QString()).simplified ().toUtf8 ();
        hash.insert ("Referer", ba);
        return hash;
    }
};

//post http://m.weibo.cn/attentionDeal/delAttention?uid=1494848464
//Need to add Referer:http://m.weibo.cn/u/3180788643 in request
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

    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        QByteArray ba("http://m.weibo.cn/u/");
        ba += parameter ("uid", QString()).simplified ().toUtf8 ();
        hash.insert ("Referer", ba);
        return hash;
    }
};

} //HackLogin
} //QWeiboSDK

#endif // HACKFRIENDSHIPS_H
