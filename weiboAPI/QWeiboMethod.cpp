
#include <QtDebug>
#include <QMetaObject>
#include <QMetaEnum>

#include "include/QWeiboMethod.h"

namespace QSinaWeiboAPI {

QWeiboMethod::QWeiboMethod(QObject *parent)
    :QObject(parent)
{
    // mWeiboActionList<<
    
}

//#define ENUM_NAME(o,e,v) (o::staticMetaObject.enumerator(o::staticMetaObject.indexOfEnumerator(#e)).valueToKey((v)))
QString QWeiboMethod::getWeiboActionStr(int action)
{
    qDebug()<<"=== getWeiboActionStr for "<<action;
    QMetaObject meta = QWeiboMethod::staticMetaObject;
//    int key = meta.indexOfEnumerator(action);
//    qDebug()<<"=== getWeiboActionStr for key "<<key;
     
    QMetaEnum m = meta.enumerator(action);
    return m.valueToKey(action);
//    QString key = ENUM_NAME(QWeiboMethod, WeiboAction, action);
//    qDebug()<<"=== getWeiboActionStr for "<<action <<" with value "<< key;
//    return key;
}

}
