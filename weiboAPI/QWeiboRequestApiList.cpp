
#include "include/QWeiboRequestApiList.h"

namespace QSinaWeiboAPI {

//static QMap<QString, FactoryBase*> factoryMap;

QWeiboRequest *QWeiboRequestApiList::createRequest(const QString &className)
{
    friends_timeline.create();

    qDebug()<<" factoryMap "<<factoryMap.keys();

    qDebug()<<" createRequest for "<<className;
    FactoryBase *base = factoryMap.value(className);
    if (base == 0) {
        qDebug()<<" createRequest NULL ";
        return 0;
    }
    return base->create();
    //return factoryMap.value(className, FactoryBase*)->create();
}

}
