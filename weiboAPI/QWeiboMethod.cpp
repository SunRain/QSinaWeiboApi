
#include <QtDebug>
#include <QMetaObject>
#include <QMetaEnum>
#include <QStringList>

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

int QWeiboMethod::getWeiboAction(const QString &weiboActionStr)
{
    QString action = weiboActionStr.toUpper();
    QStringList actionList;
    actionList<<action
             <<"WBOPT_GET_"+action
            <<"WBOPT_POST_"+action;

    int index = metaObject()->indexOfEnumerator("WeiboAction");
    QMetaEnum m = metaObject()->enumerator(index);
     
    //WBOPT_GET_TRENDS_WEEKLY,
    //WBOPT_POST_TRENDS_FOLLOW,
    int value = -1;
    for(int i=0; i<actionList.length(); ++i) {
        value = m.keyToValue((const char*)actionList[i].toLocal8Bit());
        if (value >= 0) {
            qDebug()<<"getWeiboAction match key "<<actionList[i];
            break;
        }
    }
    return value;
}

}
