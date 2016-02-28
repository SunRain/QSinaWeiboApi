#ifndef FRIENDSHIPSWRAPPER_H
#define FRIENDSHIPSWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

namespace QWeiboSDK {
namespace Wrapper {

class QWEIBOSDK_EXPORT WrapperFriendshipsCreate : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperFriendshipsCreate(QObject *parent = 0);
};

class QWEIBOSDK_EXPORT WrapperFriendshipsDestroy : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperFriendshipsDestroy(QObject *parent = 0);
};

} //Wrapper
} //QWeiboSDK
#endif // FRIENDSHIPSWRAPPER_H
