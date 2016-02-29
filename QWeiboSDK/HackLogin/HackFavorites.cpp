#include "HackFavorites.h"


namespace QWeiboSDK {
namespace HackLogin {

HackFavoritesCreate::HackFavoritesCreate(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("mblogDeal/addFavMblog", "");
    initiate ();
}

HackFavoritesList::HackFavoritesList(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("p/index", "");
    initiate ();
}

HackFavoritesDestroy::HackFavoritesDestroy(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("mblogDeal/delFavMblog", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
