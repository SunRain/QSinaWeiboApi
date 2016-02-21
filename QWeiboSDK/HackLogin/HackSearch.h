#ifndef HACKSEARCH_H
#define HACKSEARCH_H

#include <QObject>

#include "global.h"
#include "BaseHackRequest.h"

namespace QWeiboSDK {
namespace HackLogin {

//return all at users list
class QWEIBOSDK_EXPORT HackSearchSuggestionsAtUsersList : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackSearchSuggestionsAtUsersList(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("page", "1")
        ;
    }
};

class QWEIBOSDK_EXPORT HackSearchSuggestionsAtUsers : public BaseHackRequest
{
    Q_OBJECT
public:
    explicit HackSearchSuggestionsAtUsers(QObject *parent = 0);

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("page", "1")
        ("keyword", "") //search words
        ("format", "cards")
        ;
    }
};

} //HackLogin
} //QWeiboSDK
#endif // HACKSEARCH_H
