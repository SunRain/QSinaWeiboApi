#ifndef HACKFAVORITES_H
#define HACKFAVORITES_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

//post http://m.weibo.cn/mblogDeal/addFavMblog?id=
class QWEIBOSDK_EXPORT HackFavoritesCreate : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFavoritesCreate(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
//        (*this)
//        ("id", "") //weibo id
//        ;
    }
};

//获取当前用户的收藏列表  get http://m.weibo.cn/p/index?containerid=2302592889227340&format=cards&page=2
class QWEIBOSDK_EXPORT HackFavoritesList : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFavoritesList(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        //containerid from http://m.weibo.cn/home/me?format=cards
        ("containerid", "")
        ("page", "1")
        ("format", "cards")
        ;
    }
};

} //HackLogin
} //QWeiboSDK
#endif // HACKFAVORITES_H
