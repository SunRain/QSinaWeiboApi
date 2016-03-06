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

HackPrivateMessageChatList::HackPrivateMessageChatList(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("msg/messages", "");
    initiate ();
}

HackPrivateMessageSend::HackPrivateMessageSend(QObject *parent)
    : BaseHackRequest(parent)
{
    setUrlPath ("msgDeal/sendMsg", "");
    initiate ();
}

} //HackLogin
} //QWeiboSDK
