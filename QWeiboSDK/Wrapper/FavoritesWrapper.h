#ifndef FAVORITESWRAPPER_H
#define FAVORITESWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

namespace QWeiboSDK {
namespace Wrapper {

//[post] add to Favorites
class QWEIBOSDK_EXPORT WrapperFavoritesCreate : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperFavoritesCreate(QObject *parent = 0);
};

class QWEIBOSDK_EXPORT WrapperFavoritesList : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperFavoritesList(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString parseContent(const QString &content);
};

class QWEIBOSDK_EXPORT WrapperFavoritesDestroy : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperFavoritesDestroy(QObject *parent = 0);
};

} //Wrapper
} //QWeiboSDK
#endif // FAVORITESWRAPPER_H
