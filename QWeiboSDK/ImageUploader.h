#ifndef IMAGEUPLOADER_H
#define IMAGEUPLOADER_H

#include <QObject>
#include "BaseRequest.h"

namespace QWeiboSDK {

class QWEIBOSDK_EXPORT ImageUploader : public BaseRequest
{
    Q_OBJECT
public:
    explicit ImageUploader(QObject *parent = 0)
        : BaseRequest(parent) {
        setBaseUrl (QString(IMAGE_UPLOAD_HOST));
        setUrlPath ("2/statuses/upload");
        initiate ();
    }
    virtual ~ImageUploader() {}

    // BaseRequest interface
protected:
    void initParameters() {
        (*this)
        ("access_token", "")
        ;
    }
};

} //QWeiboSDK
#endif // IMAGEUPLOADER_H
