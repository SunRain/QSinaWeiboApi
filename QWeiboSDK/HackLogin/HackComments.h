#ifndef HACKCOMMENTS_H
#define HACKCOMMENTS_H

#include <QHash>
#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

/**
 * =========== unused now ======
 * get http://m.weibo.cn/5745465731/3944994903627565/rcMod?format=cards&type=comment&hot=1
 * 5745465731 is uer.id, 3944994903627565 is weibo.id
 * need resetBaseUrl to fit this function
 */
/**
 * =========== use below call now =====
 * http://m.weibo.cn/single/rcList?format=cards&id=3944994350358232&type=comment&hot=0&page=4
 */
class QWEIBOSDK_EXPORT HackCommentsShow : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackCommentsShow(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ("id", "") //weibo id
        ("type", "comment")
        ("hot", "0") //0 all comment weibo, 1 top hot weibo
        ("page","1")
        ;
    }
};
//CommentsReply
/*
 * post http://m.weibo.cn/commentDeal/replyComment
 */
class QWEIBOSDK_EXPORT HackCommentsReply : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackCommentsReply(QObject *parent = 0);
    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
//        ("format", "cards")
        ("content", "") //reply content,  need URLencode
        ("id", "") //weibo id , from weibo.card.id
        ("cid", "") //the weibo Comment content id, from weibo.id
        ("rt", "1") //当评论转发微博时，是否评论给原微博，0：否、1：是，默认为1。
        ("st", "") //don't know ,but ok to use empty
        ;
    }

    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        QString id = parameter ("id", QString()).simplified ();
        QString cid = parameter ("cid", QString()).simplified ();
        QString content = parameter ("content", QString()).simplified ();
        QString value = QString("http://m.weibo.cn/comment?id=%1&reply=%2&content=%3")
                .arg (id).arg (cid).arg (content);
        hash.insert ("Referer", /*value.toUtf8 ()*/"http://m.weibo.cn/msg/atMeCmt?subtype=allPL");
        hash.insert ("Accept", "application/json, text/javascript, */*; q=0.01");
        hash.insert ("X-Requested-With", "XMLHttpRequest");
        return hash;
    }
};

//post //http://m.weibo.cn/commentDeal/addCmt
class QWEIBOSDK_EXPORT HackCommentsCreate : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackCommentsCreate(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
//        ("format", "cards")
        ("content", "") //comment content,  need URLencode
        ("id", "") //weibo id
        ("rt", "0") //当评论微博时，是否转发原微博，0：否、1：是，默认为0。
        ("st", "") //don't know ,but ok to use empty
        ;
    }
    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        QString id = parameter ("id", QString()).simplified ();
        QString referer = QString("http://m.weibo.cn/comment?id=%1").arg (id);
        hash.insert ("Referer", referer.toUtf8 ());
        hash.insert ("Accept", "application/json, text/javascript, */*; q=0.01");
        hash.insert ("X-Requested-With", "XMLHttpRequest");
        return hash;
    }
};

//2/comments/mentions: 获取@到我的评论
//get http://m.weibo.cn/msg/atMeCmt?subtype=allPL&format=cards&page=1
class QWEIBOSDK_EXPORT HackCommentsMentions : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackCommentsMentions(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ("subtype", "allPL")
        ("page", "1")
        ;
    }
};

//2/comments/timeline: 获取用户发送及收到的评论列表
//get http://m.weibo.cn/msg/cmts?subtype=allPL&format=cards&page=1
class QWEIBOSDK_EXPORT HackCommentsTimeline : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackCommentsTimeline(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ("subtype", "allPL")
        ("page", "1")
        ;
    }
};

} //HackLogin
} //QWeiboSDK
#endif // HACKCOMMENTS_H
