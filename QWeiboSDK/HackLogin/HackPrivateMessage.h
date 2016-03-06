#ifndef HACKPRIVATEMESSAGE_H
#define HACKPRIVATEMESSAGE_H

#include <QHash>
#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

//pm for you followed
class QWEIBOSDK_EXPORT HackPrivateMessageList : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackPrivateMessageList(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("page", "1")
        ("format", "cards")
        ;
    }
};

//pm for not followed
class QWEIBOSDK_EXPORT HackPrivateMessageNoteList : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackPrivateMessageNoteList(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("page", "1")
        ("format", "cards")
        ;
    }

    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        hash.insert ("Referer", "http://m.weibo.cn/msg/notes");
        hash.insert ("Accept", "application/json");
        hash.insert ("X-Requested-With", "XMLHttpRequest");
        return hash;
    }
};

} //HackLogin
} //QWeiboSDK
#endif // HACKPRIVATEMESSAGE_H
