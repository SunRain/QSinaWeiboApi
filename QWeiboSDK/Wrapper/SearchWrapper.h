#ifndef SEARCHWRAPPER_H
#define SEARCHWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

namespace QWeiboSDK {
namespace Wrapper {

class QWEIBOSDK_EXPORT WrapperSearchSuggestionsAtUsersList : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperSearchSuggestionsAtUsersList(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString parseContent(const QString &content);
};

class QWEIBOSDK_EXPORT WrapperSearchSuggestionsAtUsers : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperSearchSuggestionsAtUsers(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString convertParameterKey(const QString &key);
    QString parseContent(const QString &content);
};
} //Wrapper
} //QWeiboSDK
#endif // SEARCHWRAPPER_H
