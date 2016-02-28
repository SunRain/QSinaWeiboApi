#include "ImageUploaderWrapper.h"
#include <QDebug>
#include "HackImageUploader.h"

namespace QWeiboSDK {
namespace Wrapper {

using namespace HackLogin;

WrapperImageUploader::WrapperImageUploader(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<ImageUploader, HackImageUploader>();
}

void WrapperImageUploader::uploadImage(const QString &fileUrl)
{
    if (TokenProvider::instance ()->useHackLogin ()) {
        BaseRequest *br = request ();
        if (br) {
            HackImageUploader *r = qobject_cast<HackImageUploader*>(br);
            if (r)
                r->uploadImage (fileUrl);
            else
                qWarning()<<Q_FUNC_INFO<<"No HackImageUploader object!!!";
        } else {
            qWarning()<<Q_FUNC_INFO<<"No request found!!!";
        }
    } else {
        qWarning()<<Q_FUNC_INFO<<"Functions only works in Hack Login!!!";
    }
}

void WrapperImageUploader::sendWeiboWithImage(const QString &content, const QString &fileUrl)
{
    if (!TokenProvider::instance ()->useHackLogin ()) {
        BaseRequest *br = request ();
        if (br) {
            ImageUploader *r = qobject_cast<ImageUploader*>(br);
            if (r)
                r->sendWeiboWithImage (content, fileUrl);
            else
                qWarning()<<Q_FUNC_INFO<<"No ImageUploader object!!!";
        } else {
            qWarning()<<Q_FUNC_INFO<<"No request found!!!";
        }
    } else {
        qWarning()<<Q_FUNC_INFO<<"Functions only works in OAuth Login!!!";
    }
}

} //Wrapper
} //QWeiboSDK
