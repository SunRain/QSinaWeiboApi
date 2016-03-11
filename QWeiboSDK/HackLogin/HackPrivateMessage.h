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

//http://m.weibo.cn/msg/messages?uid=3180788643&page=1
class QWEIBOSDK_EXPORT HackPrivateMessageChatList : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackPrivateMessageChatList(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("page", "1")
        ("uid", "")
        ("format", "cards")
        ;
    }
};

//post http://m.weibo.cn/msgDeal/sendMsg
class QWEIBOSDK_EXPORT HackPrivateMessageSend : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackPrivateMessageSend(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("fileId", "null")
        ("uid", "")
        ("content", "")
        ("st", "") //can be taken from  HackPrivateMessageToken
        ;
    }

    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        QString uid = parameter ("uid");
        QString referer = QString("http://m.weibo.cn/msg/chat?uid=%1").arg (uid);
        hash.insert ("Referer", referer.toUtf8 ());
        hash.insert ("Accept", "application/json");
        hash.insert ("X-Requested-With", "XMLHttpRequest");
        return hash;
    }
};

//get http://m.weibo.cn/msg/chat?uid=xxx
class QWEIBOSDK_EXPORT HackPrivateMessageToken : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackPrivateMessageToken(QObject *parent = 0);

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
        QString uid = parameter ("uid");
        QString referer = QString("http://m.weibo.cn/msg/chat?uid=%1").arg (uid);
        hash.insert ("Referer", referer.toUtf8 ());
        return hash;
    }
};


} //HackLogin
} //QWeiboSDK
#endif // HACKPRIVATEMESSAGE_H
