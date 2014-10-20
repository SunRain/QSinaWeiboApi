
#include <QtDebug>
#include <QMetaObject>
#include <QMetaEnum>

#include "include/QWeiboMethod.h"

namespace QSinaWeiboAPI {

QWeiboMethod::QWeiboMethod(QObject *parent)
    :QObject(parent)
{
}

//#define ENUM_NAME(o,e,v) (o::staticMetaObject.enumerator(o::staticMetaObject.indexOfEnumerator(#e)).valueToKey((v)))
QString QWeiboMethod::getWeiboActionStr(int action)
{
    int index = metaObject()->indexOfEnumerator("WeiboAction");
    QMetaEnum m = metaObject()->enumerator(index);
    return m.valueToKey(action);
}

}
