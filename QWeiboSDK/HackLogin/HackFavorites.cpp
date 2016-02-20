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

} //HackLogin
} //QWeiboSDK
