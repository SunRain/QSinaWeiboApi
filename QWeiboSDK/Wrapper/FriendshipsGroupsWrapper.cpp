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

#define TO_QSTR(x) QString::fromStdString (x)

WrapperFriendshipsGroups::WrapperFriendshipsGroups(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<FriendshipsGroups, HackFriendshipsGroups>();
}

QString WrapperFriendshipsGroups::parseContent(const QString &content)
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

WrapperFriendshipsGroupsTimeline::WrapperFriendshipsGroupsTimeline(QObject *parent)
    : BaseWrapper(parent)
{
    registerRequest<FriendshipsGroupsTimeline, HackFriendshipsGroupsTimeline>();
}

QString WrapperFriendshipsGroupsTimeline::parseContent(const QString &content)
{
    qDebug()<<Q_FUNC_INFO<<"=================";

    HTML::ParserDom parser;
    tree<HTML::Node> dom = parser.parseTree(content.toStdString ());

    tree<HTML::Node>::iterator it = dom.begin();
    tree<HTML::Node>::iterator end = dom.end();

    QString tmp = QString();
    QJsonArray jarray;

    while (it != end) { // 遍历文档中所有的元素

        if ((*it).tagName () == "div") {
            (*it).parseAttributes ();

            //<div class="pa" id="pagelist">是最后一条内容之后的页面内容，作为跳出循环的标记
            if ((*it).attribute ("class").second == "pa"
                    && (*it).attribute ("id").second == "pagelist") {
                qDebug()<<Q_FUNC_INFO<<">>>>>> break main loop <<<<";
                break;
            }

            if ((*it).attribute ("class").second != "c"
                    || (*it).attribute ("id").second.empty ()) {
                ++it;
                continue;
            }
            qDebug()<<Q_FUNC_INFO<<"*******************************************";

            //第一次到达解析地址，迭代+1开始解析后面内容
            if ((*it).tagName () == "div") {
                if (!(*it).attribute ("id").second.empty ()
                        && (*it).attribute ("class").second == "c") {
                    qDebug()<<"mark for <TAG> [tagname ="<<QString::fromStdString ((*it).tagName ())
                           <<"] [text="<<QString::fromStdString ((*it).text ())<<"]";
                    ++it;

                    qDebug()<<"Next Tag is ["<<TO_QSTR((*it).tagName ())
                           <<"] closingText text ["<<TO_QSTR ((*it).closingText ())
                           <<"]";
                    if ((*it).tagName () == "div") {
                        int start = (*it).offset ();
                        int length = (*it).length ();
                        qDebug()<<"Next Tag [DIV] length ["<<length
                                <<"], offset ["<<start
                                <<"]";
                        QString data = content.mid (start, length);
                        qDebug()<<"Next Tag [DIV] data <"<<data<<">";
                    }
                 }
            }

            do {
                //<div class="pa" id="pagelist">是最后一条内容之后的页面内容，作为跳出循环的标记
                if ((*it).attribute ("class").second == "pa"
                        && (*it).attribute ("id").second == "pagelist") {
                    qDebug()<<">>>>>> break inner loop <<<<";
                    break;
                }

                if ((*it).tagName () == "div") {
                    if (!(*it).attribute ("id").second.empty ()
                            && (*it).attribute ("class").second == "c") {
                        qDebug()<<"break for <TAG> [tagname ="<<QString::fromStdString ((*it).tagName ())
                               <<"] [text="<<QString::fromStdString ((*it).text ())<<"]";
//                        breakFlag = true;
                        break;
                     }
                }
                qDebug()<<"Tag is ["<<TO_QSTR((*it).tagName ())
                       <<"] closingText text ["<<TO_QSTR ((*it).closingText ())
                       <<"]";

                if ((*it).tagName () == "div") {
                    int start = (*it).offset ();
                    int length = (*it).length ();
                    qDebug()<<"[DIV] length ["<<length
                            <<"], offset ["<<start
                            <<"]";
                    QString data = content.mid (start, length);
                    qDebug()<<"[DIV] data <"<<data<<">";
                }
                if ((*it).isTag ()) {
                    qDebug()<<"<TAG> [tagname ="<<QString::fromStdString ((*it).tagName ())
                           <<"] [text="<<QString::fromStdString ((*it).text ())<<"]";
                } else if ((*it).isComment ()){
                    qDebug()<<"<Comment> [tagname ="<<QString::fromStdString ((*it).tagName ())
                           <<"] [text="<<QString::fromStdString ((*it).text ())<<"]";
                } else {
                    qDebug()<<"<TEXT> [tagname ="<<QString::fromStdString ((*it).tagName ())
                           <<"] [text="<<QString::fromStdString ((*it).text ())<<"]";
                }
                ++it;
                (*it).parseAttributes ();
            } while (true);
            continue;
        }
        ++it;
    }

    qDebug()<<Q_FUNC_INFO<<"====  end of parser ====";

    return content;
}








































} //Wrapper
} //QWeiboSDK
