#include "FriendshipsGroupsWrapper.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QUrlQuery>

#include "HackLogin/HackFriendshipsGroups.h"
#include "HackLogin/BaseHackRequest.h"

#include "QWeiboRequest.h"
#include "TokenProvider.h"

namespace QWeiboSDK {
namespace Wrapper {

using namespace HackLogin;
using namespace htmlcxx;
using namespace std;

FriendshipsGroupsTimelineWrapper::FriendshipsGroupsTimelineWrapper(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<FriendshipsGroupsTimeline, HackFriendshipsGroupsTimeline>();
}

QString FriendshipsGroupsTimelineWrapper::parseContent(const QString &content)
{
    HTML::ParserDom parser;
    tree<HTML::Node> dom = parser.parseTree(content.toStdString ());

    tree<HTML::Node>::iterator domBeg = dom.begin();
    tree<HTML::Node>::iterator domEnd = dom.end();

    QString tmp = QString();
    QJsonArray jarray;
    while (domBeg != domEnd) { // 遍历文档中所有的元素
        if (!(*domBeg).tagName ().compare ("a")) {
            domBeg->parseAttributes();
            QString cv = QString::fromStdString ((*domBeg).attribute ("href").second);
            if (cv.contains ("attgroup/show")) {
//                qDebug()<<Q_FUNC_INFO<<"***************************";
//                qDebug()<<Q_FUNC_INFO<<"a value ["<<cv<<"], text is "<<QString::fromStdString ((*domBeg).text ());
                ++domBeg;

                QUrl url = QUrl::fromEncoded ((QString("http://fake.com/%1").arg (cv))
                                              .replace ("&amp;","&")
                                              .toUtf8 ());
//                qDebug()<<Q_FUNC_INFO<<"url is "<<url;
//                qDebug()<<Q_FUNC_INFO<<"url has query "<<url.hasQuery ()
//                       <<"  query value "<<url.query ();

                QUrlQuery query(url.query ());
                if (!query.hasQueryItem ("gid"))
                    continue;

                QString gid = query.queryItemValue ("gid");
                if (gid.isEmpty ())
                    continue;

                if (! (*domBeg).isTag ()) {
                    tmp = QString();
                    tmp = QString::fromStdString ((*domBeg).text ());
                    tmp = tmp.mid (0, tmp.lastIndexOf ("["));
                }
                if (tmp.isEmpty ())
                    continue;

                QJsonObject obj;
                obj.insert ("id", gid);
                obj.insert ("idstr", gid);
                obj.insert ("name", tmp);
                jarray.append (obj);

                continue;
            }
        }
        ++domBeg;
    }
    QJsonDocument d(jarray);
    return d.toJson ();
}

} //Wrapper
} //QWeiboSDK
