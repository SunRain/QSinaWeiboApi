#include "SearchWrapper.h"

#include <QDebug>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "HackLogin/HackSearch.h"
#include "QWeiboRequest.h"
#include "TokenProvider.h"

namespace QWeiboSDK {
namespace Wrapper {

using namespace HackLogin;

WrapperSearchSuggestionsAtUsersList::WrapperSearchSuggestionsAtUsersList(QObject *parent)
    : BaseWrapper(parent)
{
    qWarning()<<Q_FUNC_INFO<<"This api only support hack login!!!";
    registerRequest<HackSearchSuggestionsAtUsersList, HackSearchSuggestionsAtUsersList>();
}

QString WrapperSearchSuggestionsAtUsersList::parseContent(const QString &content)
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
    if (doc.isObject ()) {
        qDebug()<<Q_FUNC_INFO<<">>>>>>>>>>> is Object <<<<<<<<<<<<";

        QJsonValue parentValue = doc.object ().value ("cards");
        if (parentValue.isUndefined () || parentValue.isNull ()) {
            qDebug()<<Q_FUNC_INFO<<"parentValue invalid!!";
            return QString();
        }
        QJsonArray retArray;
        if (parentValue.isArray ()) {
            QJsonArray array = parentValue.toArray ();
            qDebug()<<Q_FUNC_INFO<<"array length "<<array.size ();
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
                                retArray.append (tmp);
                            }
                        }
                    }
                }
            }
        }
        qDebug()<<Q_FUNC_INFO<<"ret array size "<<retArray.size ();
        QJsonDocument d(retArray);
        return d.toJson ();
    }
    return QString();
}

WrapperSearchSuggestionsAtUsers::WrapperSearchSuggestionsAtUsers(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<SearchSuggestionsAtUsers, HackSearchSuggestionsAtUsers>();
}

QString WrapperSearchSuggestionsAtUsers::convertParameterKey(const QString &key)
{
    if (TokenProvider::instance ()->useHackLogin ()) {
        if (key == "q")
            return "keyword";
    }
    return key;
}

QString WrapperSearchSuggestionsAtUsers::parseContent(const QString &content)
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
    if (doc.isObject ()) {
        qDebug()<<Q_FUNC_INFO<<">>>>>>>>>>> is Object <<<<<<<<<<<<";

        QJsonValue parentValue = doc.object ().value ("cards");
        if (parentValue.isUndefined () || parentValue.isNull ()) {
            qDebug()<<Q_FUNC_INFO<<"parentValue invalid!!";
            return QString();
        }
        QJsonArray retArray;
        if (parentValue.isArray ()) {
            QJsonArray array = parentValue.toArray ();
            qDebug()<<Q_FUNC_INFO<<"array length "<<array.size ();
            foreach (QJsonValue v, array) {
                QJsonObject mainObj = v.toObject ();
                if (mainObj.isEmpty ()) {
                    qDebug()<<Q_FUNC_INFO<<"main object is empty!!";
                    continue;
                }
                retArray.append (mainObj);
            }
        }
        qDebug()<<Q_FUNC_INFO<<"ret array size "<<retArray.size ();
        QJsonDocument d(retArray);
        return d.toJson ();
    }
    return QString();
}

} //Wrapper
} //QWeiboSDK
