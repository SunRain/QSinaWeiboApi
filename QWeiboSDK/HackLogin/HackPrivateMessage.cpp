#include "HackPrivateMessage.h"

namespace QWeiboSDK {
namespace HackLogin {

HackPrivateMessageList::HackPrivateMessageList(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("msg/index", "");
    initiate ();
}

HackPrivateMessageNoteList::HackPrivateMessageNoteList(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("msg/noteList", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
