#include "CommentsWrapper.h"

#include <QDebug>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "HackLogin/HackComments.h"

#include "QWeiboRequest.h"

namespace QWeiboSDK {
namespace Wrapper {

using namespace HackLogin;

WrapperCommentsShow::WrapperCommentsShow(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<CommentsShow, HackCommentsShow>();
}

QString WrapperCommentsShow::parseContent(const QString &content)
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
        ret.insert ("comments",retArray);
        QJsonDocument d(ret);
        return d.toJson ();
    }
    return QString();
}

WrapperCommentsReply::WrapperCommentsReply(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<CommentsReply, HackCommentsReply>();
}

QString WrapperCommentsReply::convertParameterKey(const QString &key)
{
    if (TokenProvider::instance ()->useHackLogin ()) {
        if (key == "comment")
            return "content";
        else if (key == "comment_ori")
            return "rt";
    }
    return key;
}

WrapperCommentsCreate::WrapperCommentsCreate(QObject *parent)
     : BaseWrapper(parent)
{
    registerRequest<CommentsCreate, HackCommentsCreate>();
}

QString WrapperCommentsCreate::convertParameterKey(const QString &key)
{
    if (TokenProvider::instance ()->useHackLogin ()) {
        if (key == "comment")
            return "content";
        else if (key == "comment_ori")
            return "rt";
    }
    return key;
}


} //Wrapper
} //QWeiboSDK
