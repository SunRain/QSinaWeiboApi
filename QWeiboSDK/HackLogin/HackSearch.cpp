#include "HackSearch.h"

namespace QWeiboSDK {
namespace HackLogin {

HackSearchSuggestionsAtUsersList::HackSearchSuggestionsAtUsersList(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("attention/getAtList", "");
    initiate ();
}

HackSearchSuggestionsAtUsers::HackSearchSuggestionsAtUsers(QObject *parent)
    : HackSearchSuggestionsAtUsers(parent)
{
    setUrlPath ("attention/getAttentionList", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
