#ifndef IMAGEUPLOADERWRAPPER_H
#define IMAGEUPLOADERWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

namespace QWeiboSDK {
namespace Wrapper {

class WrapperImageUploader : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperImageUploader(QObject *parent = 0);
    Q_INVOKABLE void uploadImage(const QString &fileUrl);
    Q_INVOKABLE void sendWeiboWithImage(const QString &content, const QString &fileUrl);
};

} //Wrapper
} //QWeiboSDK
#endif // IMAGEUPLOADERWRAPPER_H
