#ifndef HACKFRIENDSHIPSGROUPS_H
#define HACKFRIENDSHIPSGROUPS_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {
class QWEIBOSDK_EXPORT HackFriendshipsGroups : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackFriendshipsGroups(QObject *parent = 0);
};

#endif // HACKFRIENDSHIPSGROUPS_H

} //HackLogin
} //QWeiboSDK
