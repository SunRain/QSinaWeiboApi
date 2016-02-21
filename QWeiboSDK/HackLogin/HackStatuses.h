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
        ("st", "") //unknow seems ok if empty
        ;
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
};

} //HackLogin
} //QWeiboSDK
#endif // HACKSTATUSES_H
