#ifndef HACKSTATUSES_H
#define HACKSTATUSES_H

#include <QHash>
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

/*
 * get http://m.weibo.cn/single/rcList?format=cards&id=3944998526806367&type=repost&hot=0
 * 3944994903627565 is weibo.id
 */
class QWEIBOSDK_EXPORT HackStatusesRepostTimeline : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackStatusesRepostTimeline(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ("id", "") //weibo id
        ("type", "repost")
        ("hot", "0") //0 all repost weibo, 1 top hot weibo
        ("page", "1")
        ;
    }
};

//post
class QWEIBOSDK_EXPORT HackStatusesUpdate : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackStatusesUpdate(QObject *parent = 0);

    // BaseRequest interface
protected:
    //TODO more Parameters
    void initParameters() {
        (*this)
        ("content", "") //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("visible", "0") //微博的可见性，0：所有人能看，1：仅自己可见，2：密友可见，3：指定分组可见，默认为0。
        ("picId", "") //picids from uploaded images, multi picids should be seperated by ,
        //ac361c4cjw1f1fgdqivguj20hs0dct9v,ac361c4cjw1f1fgeqsgvxj20900g5gmi"
        ("st", "") //unknow seems ok if empty
        ;
    }

    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        hash.insert ("Referer", "http://m.weibo.cn/mblog");
        return hash;
    }
};

//转发一条微博信息
//post http://m.weibo.cn/mblogDeal/rtMblog
class QWEIBOSDK_EXPORT HackStatusesRepost : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackStatusesRepost(QObject *parent = 0);

    // BaseRequest interface
protected:
    //TODO more Parameters
    void initParameters() {
        (*this)
        ("content", "") //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("id", "0") //需要转发的微博id
        ("rtcomment" ,"") //同时评论的用户id（即发送被转发的微博的用户id）
        ("st", "") //unknow, seems ok if empty
        ;
    }

    // BaseHackRequest interface
protected:
    QHash<QByteArray, QByteArray> extraRawtHeaders() {
        QHash<QByteArray, QByteArray> hash;
        QString id = parameter ("id", QString()).simplified ();
        QString referer = QString("http://m.weibo.cn/repost?id=%1").arg (id);
        hash.insert ("Referer", referer.toUtf8 ());
        hash.insert ("Accept", "application/json, text/javascript, */*; q=0.01");
        hash.insert ("X-Requested-With", "XMLHttpRequest");
        return hash;
    }
};

// 2/statuses/mentions: 获取@当前用户的最新微博
//get http://m.weibo.cn/msg/atme?subtype=allWB
class QWEIBOSDK_EXPORT HackStatusesMentions : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackStatusesMentions(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ("subtype", "allWB")
        ("page", "1")
        ;
    }
};

/*get
 http://m.weibo.cn/page/tpl?
    containerid=1005051494848464_-_WEIBO_SECOND_PROFILE_WEIBO
    &itemid=&title=%E5%85%A8%E9%83%A8%E5%BE%AE%E5%8D%9A&format=cards
    &page=1
 ======================
 containerid should be from http://m.weibo.cn/u/1494848464 => sub object
 ==> itemid": "1005051850988623_-_WEIBO_INDEX_PROFILE_APPS",
 ==> containerid is 1005051850988623
*/
class QWEIBOSDK_EXPORT HackStatusesUserTimeline : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackStatusesUserTimeline(QObject *parent = 0);
    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("format", "cards")
        ("containerid", "")
        ("itemid", "") //ok if empty
        ("title", "%E5%85%A8%E9%83%A8%E5%BE%AE%E5%8D%9A")
        ("page", "1")
        ;
    }
};

// 2/statuses/show: 根据ID获取单条微博信息
//get http://m.weibo.cn/---user.id ---/--- bid ----
//need resetUrlPath
class QWEIBOSDK_EXPORT HackStatusesShow : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackStatusesShow(QObject *parent = 0);

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
#endif // HACKSTATUSES_H
