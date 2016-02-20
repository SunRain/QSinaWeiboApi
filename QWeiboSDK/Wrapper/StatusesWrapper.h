#ifndef STATUSESWRAPPER_H
#define STATUSESWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

namespace QWeiboSDK {
namespace Wrapper {

//statuses/friends_timeline 	获取当前登录用户及其所关注用户的最新微博
class QWEIBOSDK_EXPORT WrapperStatusesFriendsTimeline : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperStatusesFriendsTimeline(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString parseContent(const QString &content);
};

} //Wrapper
} //QWeiboSDK
#endif // STATUSESWRAPPER_H
