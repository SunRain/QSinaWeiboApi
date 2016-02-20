#include "FavoritesWrapper.h"

#include <QDebug>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "HackLogin/HackFavorites.h"

#include "QWeiboRequest.h"
#include "TokenProvider.h"

namespace QWeiboSDK {
namespace Wrapper {

using namespace HackLogin;

WrapperFavoritesCreate::WrapperFavoritesCreate(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<FavoritesCreate, HackFavoritesCreate>();
}

WrapperFavoritesList::WrapperFavoritesList(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<Favorites, HackFavoritesList>();
}

QString WrapperFavoritesList::parseContent(const QString &content)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson (content.toUtf8 (), &error);
    if (error.error != QJsonParseError::NoError) {
        qDebug()<<Q_FUNC_INFO<<"Parse main json content error ["<<error.errorString ()<<"]";
        return QString();
    }
    qDebug()<<"doc isObject ["<<doc.isObject ()
           <<"] isArray ["<<doc.isArray ()<<"]";
    if (doc.isNull () || doc.isEmpty ()) {
        qDebug()<<Q_FUNC_INFO<<"Parse main json content, result isNull or isEmpty";
        return QString();
    }
    if (doc.isArray ()) {
        qDebug()<<Q_FUNC_INFO<<">>>>>>>>>>> array <<<<<<<<<<<<";
        QJsonArray array = doc.array ();
        qDebug()<<Q_FUNC_INFO<<"array length "<<array.size ();

        QJsonArray retArray;
        foreach (QJsonValue v, array) {
            QJsonObject mainObj = v.toObject ();
            if (mainObj.isEmpty ()) {
                qDebug()<<Q_FUNC_INFO<<"main object is empty!!";
                continue;
            }
            if (!mainObj.contains ("card_group"))
                continue;
            QJsonValue mainValue = mainObj.value ("card_group"); //array 1
            if (mainValue.isUndefined () || mainValue.isNull ()) {
                qDebug()<<Q_FUNC_INFO<<"InValid main json value";
                continue;
            }
            if (mainValue.isArray ()) {
                QJsonArray topValueArray = mainValue.toArray ();
                if (topValueArray.isEmpty ()) {
                    qDebug()<<Q_FUNC_INFO<<"top ValueArray is empty!!!";
                    continue;
                }
                foreach (QJsonValue av, topValueArray) {
                    QJsonObject avObj = av.toObject ();
                    if (avObj.isEmpty ()) {
                        qDebug()<<Q_FUNC_INFO<<"avObj is empty!!";
                        continue;
                    }
                    if (!avObj.contains ("card_group"))
                        continue;
                    //again for real values
                    QJsonValue avVaule = avObj.value ("card_group"); //array 2
                    if (avVaule.isUndefined () || avVaule.isNull ()) {
                        qDebug()<<Q_FUNC_INFO<<"InValid avArray value";
                        continue;
                    }

                    if (avVaule.isArray ()) {
                        QJsonArray mainArray = avVaule.toArray ();
                        if (mainArray.isEmpty ()) {
                            qDebug()<<Q_FUNC_INFO<<"main Array is empty!!!";
                            continue;
                        }

                        foreach (QJsonValue value, mainArray) {
                            QJsonObject tmp = value.toObject ();
                            if (tmp.isEmpty ())
                                continue;
                            QJsonValue v = tmp.value ("mblog");
                            if (v.isUndefined () || v.isNull () || !v.isObject ())
                                continue;
                            QJsonObject o = v.toObject ();
                            if (o.isEmpty ())
                                continue;
                            v = tmp.value ("scheme");
                            if (v.isUndefined () || v.isNull ())
                                continue;
                            QString scheme = v.toString ();
                            if (scheme.isEmpty ())
                                continue;
                            if (scheme.endsWith ("?")) //remove last "?" for scheme value
                                scheme = scheme.left (scheme.length () -1);
                            o.insert ("scheme", scheme);

                            //add a status wrapper to fit oauth values
                            QJsonObject p;
                            p.insert ("status", o);
                            retArray.append (p);
                        }
                    }
                }
            }
        }
        qDebug()<<Q_FUNC_INFO<<"ret array size "<<retArray.size ();
        QJsonObject ret;
        ret.insert ("favorites",retArray);
        QJsonDocument d(ret);
        return d.toJson ();
    }
    return QString();
}

} //Wrapper
} //QWeiboSDK

