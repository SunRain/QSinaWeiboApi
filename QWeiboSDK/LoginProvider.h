#ifndef LOGINPROVIDER_H
#define LOGINPROVIDER_H

#include <QObject>

namespace QWeiboSDK {
class LoginProvider : public QObject
{
    Q_OBJECT
public:
    explicit LoginProvider(QObject *parent = 0);
    virtual ~LoginProvider();
};
}//QWeiboSDK
#endif // LOGINPROVIDER_H
