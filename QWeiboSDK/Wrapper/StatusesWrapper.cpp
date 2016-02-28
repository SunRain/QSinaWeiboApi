#include "StatusesWrapper.h"

#include <QDebug>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "HackLogin/HackStatuses.h"
#include "QWeiboRequest.h"

namespace QWeiboSDK {
namespace Wrapper {

using namespace HackLogin;

WrapperStatusesFriendsTimeline::WrapperStatusesFriendsTimeline(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<StatusesFriendsTimeline, HackStatusesFriendsTimeline>();
}

QString WrapperStatusesFriendsTimeline::parseContent(const QString &content)
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
            QJsonValue mainValue = mainObj.value ("card_group");
            if (mainValue.isUndefined () || mainValue.isNull ()) {
                qDebug()<<Q_FUNC_INFO<<"InValid main json value";
                continue;
            }
            if (mainValue.isArray ()) {
                QJsonArray mainArray = mainValue.toArray ();
                if (mainArray.isEmpty ()) {
                    qDebug()<<Q_FUNC_INFO<<"main Array is empty!!!";
                    continue;
                }

                foreach (QJsonValue value, mainArray) {
                    QJsonObject tmp = value.toObject ();
                    if (tmp.isEmpty ())
                        continue;
                    QJsonValue v = tmp.value ("mblog");
                    if (v.isUndefined () || v.isNull ())
                        continue;
                    if (!v.isObject ())
                        continue;
                    QJsonObject o = v.toObject ();
                    if (o.isEmpty ())
                        continue;
                    retArray.append (o);
                }
            }
        }
        qDebug()<<Q_FUNC_INFO<<"ret array size "<<retArray.size ();
        QJsonObject ret;
        ret.insert ("statuses",retArray);
        QJsonDocument d(ret);
        return d.toJson ();
    }
    return QString();
}

WrapperStatusesRepostTimeline::WrapperStatusesRepostTimeline(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<StatusesRepostTimeline, HackStatusesRepostTimeline>();
}

QString WrapperStatusesRepostTimeline::parseContent(const QString &content)
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
                foreach (QJsonValue value, topValueArray) {
                    QJsonObject tmp = value.toObject ();
                    if (tmp.isEmpty ())
                        continue;
                    retArray.append (tmp);
                }
            }
        }
        qDebug()<<Q_FUNC_INFO<<"ret array size "<<retArray.size ();
        QJsonObject ret;
        ret.insert ("reposts",retArray);
        QJsonDocument d(ret);
        return d.toJson ();
    }
    return QString();
}

WrapperStatusesUpdate::WrapperStatusesUpdate(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<StatusesUpdate, HackStatusesUpdate>();
}

QString WrapperStatusesUpdate::convertParameterKey(const QString &key)
{
    if (TokenProvider::instance ()->useHackLogin ()) {
        if (key == "status")
            return "content";
    }
    return key;
}

WrapperStatusesRepost::WrapperStatusesRepost(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<StatusesRepost, HackStatusesRepost>();
}

QString WrapperStatusesRepost::convertParameterKey(const QString &key)
{
    if (TokenProvider::instance ()->useHackLogin ()) {
        if (key == "status")
            return "content";
    }
    return key;
}

WrapperStatusesMentions::WrapperStatusesMentions(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<StatusesMentions, HackStatusesMentions>();
}

QString WrapperStatusesMentions::parseContent(const QString &content)
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
            QJsonValue mainValue = mainObj.value ("card_group");
            if (mainValue.isUndefined () || mainValue.isNull ()) {
                qDebug()<<Q_FUNC_INFO<<"InValid main json value";
                continue;
            }
            if (mainValue.isArray ()) {
                QJsonArray mainArray = mainValue.toArray ();
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
        qDebug()<<Q_FUNC_INFO<<"ret array size "<<retArray.size ();
        QJsonObject ret;
        ret.insert ("statuses",retArray);
        QJsonDocument d(ret);
        return d.toJson ();
    }
    return QString();
}

WrapperStatusesUserTimeline::WrapperStatusesUserTimeline(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<StatusesUserTimeline, HackStatusesUserTimeline>();
}

QString WrapperStatusesUserTimeline::parseContent(const QString &content)
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
            QJsonValue mainValue = mainObj.value ("card_group");
            if (mainValue.isUndefined () || mainValue.isNull ()) {
                qDebug()<<Q_FUNC_INFO<<"InValid main json value";
                continue;
            }
            if (mainValue.isArray ()) {
                QJsonArray mainArray = mainValue.toArray ();
                if (mainArray.isEmpty ()) {
                    qDebug()<<Q_FUNC_INFO<<"main Array is empty!!!";
                    continue;
                }
                foreach (QJsonValue value, mainArray) {
                    QJsonObject tmp = value.toObject ();
                    if (tmp.isEmpty ())
                        continue;
                    if (!tmp.contains ("mblog"))
                        continue;
                    QJsonObject o = tmp.value ("mblog").toObject ();
                    if (o.isEmpty ())
                        continue;
                    retArray.append (o);
                }
            }
        }
        qDebug()<<Q_FUNC_INFO<<"ret array size "<<retArray.size ();
        QJsonObject ret;
        ret.insert ("statuses",retArray);
        QJsonDocument d(ret);
        return d.toJson ();
    }
    return QString();
}

} //Wrapper
} //QWeiboSDK
