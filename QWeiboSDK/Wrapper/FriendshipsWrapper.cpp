#include "FriendshipsWrapper.h"

#include "QWeiboRequest.h"
#include "HackFriendships.h"

namespace QWeiboSDK {
namespace Wrapper {

using namespace HackLogin;

WrapperFriendshipsCreate::WrapperFriendshipsCreate(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<FriendshipsCreate, HackFriendshipsCreate>();
}

WrapperFriendshipsDestroy::WrapperFriendshipsDestroy(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<FriendshipsDestroy, HackFriendshipsDestroy>();
}


} //Wrapper
} //QWeiboSDK
