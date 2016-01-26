#include "CookieDataProvider.h"

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QUrl>
#include <QUrlQuery>

#include <QByteArray>

#include <htmlcxx/html/tree.h>
#include <htmlcxx/html/ParserDom.h>
#include <htmlcxx/html/Node.h>

using namespace htmlcxx;
using namespace std;

#include "Key.h"

CookieDataProvider::CookieDataProvider(QObject *parent)
    : QObject(parent)
    , m_networkMgr(new QNetworkAccessManager(this))
    , m_reply(nullptr)
    , m_userName(QString(USERNAME))
    , m_passWord(QString(PASSWORD))
    , m_rand(QString())
    , m_headerPassWord(QString())
    , m_vk(QString())
    , m_backTitle(QString())
    , m_submit(QString())
    , m_capId(QString())
    , m_captcha(QString())
    , m_captchaImgUrl(QString())
{

}

CookieDataProvider::~CookieDataProvider()
{

}

void CookieDataProvider::login()
{
    QUrl url("http://login.weibo.cn/login/");
    QNetworkRequest request(url);
//    request.setRawHeader ("User-Agent", "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:43.0) Gecko/20100101 Firefox/43.0");
    request.setRawHeader ("User-Agent", "Mozilla/5.0 (Windows;U;Windows NT 5.1;zh-CN;rv:1.9.2.9) Gecko/20100101 Firefox/43.0");
//            post.setHeader("Referer", CommonConst.loginUrl);
//    request.setRawHeader("Origin", "http://m.weibo.cn");
//    request.setRawHeader("Cache-Control", "max-age=0");
//    request.setRawHeader("Accept",
//        "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
//    request.setRawHeader("Accept-Encoding", "gzip,deflate,sdch");
//    request.setRawHeader("Accept-Language", "en-US,en;q=0.8");
//    request.setRawHeader("Accept-Charset", "ISO-8859-1,utf-8;q=0.7,*;q=0.3");
//    request.setRawHeader("Accept-Encoding", "gzip,deflate,sdch");
//    request.setRawHeader("Referer", "http://m.weibo.cn/login");
    request.setRawHeader("Referer", "");

    QByteArray data(url.query(QUrl::FullyEncoded).toLatin1());

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));

    qDebug()<<Q_FUNC_INFO<<"post "<<url;
    m_reply = m_networkMgr->post (request, data);
    if (m_reply) {
        QObject::connect (m_reply, &QNetworkReply::finished,
                 [&](){
            QNetworkReply::NetworkError error = m_reply->error ();
            bool success = (error == QNetworkReply::NoError);
            qDebug()<<Q_FUNC_INFO<<"success "<<success;

            if (!success) {
                QString str = m_reply->errorString ();
                qDebug()<<Q_FUNC_INFO<<" not success "<<str;

                m_reply->deleteLater ();
                m_reply = nullptr;
            } else {
                QByteArray qba = m_reply->readAll ();
                qDebug()<<Q_FUNC_INFO<<" is success ";//<<qba;

                m_reply->deleteLater ();
                m_reply = nullptr;

                HTML::ParserDom parser;
                tree<HTML::Node> dom = parser.parseTree(QString(qba).toStdString ());

                tree<HTML::Node>::iterator domBeg = dom.begin();
                tree<HTML::Node>::iterator domEnd = dom.end();

                for (; domBeg != domEnd; ++domBeg)   // 遍历文档中所有的元素
                {
                    qDebug()<<"================================";
                    qDebug()<<"TagName ["<< QString::fromStdString ((*domBeg).tagName ())<<"]"
                           <<" is tag ["<<(*domBeg).isTag ()<<"]";

                    if (!(*domBeg).tagName ().compare ("form")) {
                        domBeg->parseAttributes();
                        m_rand = QString::fromStdString ((*domBeg).attribute ("action").second);
                        qDebug()<<"form value second ["<<m_rand<<"]";
                    }
                    else if (!(*domBeg).tagName ().compare ("a")) {
                        domBeg->parseAttributes();
                        qDebug()<<"a value ["<< QString::fromStdString ((*domBeg).attribute ("href").second)<<"]";
                    }
                    else if (!(*domBeg).tagName ().compare ("img")) {
                        domBeg->parseAttributes();
                        QString value = QString::fromStdString ((*domBeg).attribute ("src").second);
                        if (value.contains ("captcha"))
                            m_captchaImgUrl = value;
                    }
                    else if (!(*domBeg).tagName ().compare ("input")) {
                        domBeg->parseAttributes();
                        if (!(*domBeg).attribute ("type").second.compare ("password")) {
                            m_headerPassWord = QString::fromStdString ((*domBeg).attribute ("name").second);
                            qDebug()<<"a password value ["<<m_headerPassWord<<"]";
                        }
                        else if (!(*domBeg).attribute ("type").second.compare ("hidden")) {
                            QString name = QString::fromStdString ((*domBeg).attribute ("name").second);
                            QString value = QString::fromStdString ((*domBeg).attribute ("value").second);
                            qDebug()<<"a hidden name ["<< name<<"]"<<" value ["<<value<<"]";
                            if (name == QString("vk"))
                                m_vk = value;
                            else if (name == QString("backTitle"))
                                m_backTitle = value;
                            else if (name == QString("capId"))
                                m_capId = value;
                        }
                        else if (!(*domBeg).attribute ("type").second.compare ("submit")) {
                            QString name = QString::fromStdString ((*domBeg).attribute ("name").second);
                            QString value = QString::fromStdString ((*domBeg).attribute ("submit").second);
                            if (name == QString("submit"))
                                m_submit = value;
                            qDebug()<<"a hidden name ["<< name<<"]"<<" value ["<<value<<"]";
                        }
                    }

//                    if (!domBeg->tagName().compare("div"))    // 查找所有div标签
//                    {
//                        domBeg->parseAttributes();  // 这个函数很重要。如果不调用，我们无法获取标签的属性。而下面我们正需要获取div的class属性，所以必须调用。</span>

//                        qDebug()<<"text ["<< QString::fromStdString ((*domBeg).text ())<<"]";


////                        if (!domBeg->attribute("class").second.compare("post_item"))   // 如果是class属性值为post_item，表明是一个博文结构，开始解析
////                        {
////                            count = 0;  // count计数，每条博文只解析7个字段，主要是为了跳出循环。没有找到更好的跳出循环的方法
////                            out << "-----------------------------------------------" << endl;
////                            for (; domBeg != domEnd; ++domBeg)
////                            {
////                                if (!domBeg->tagName().compare("a"))  // 如果是a标签，则将a标签的href属性值提取出来保存到文件
////                                {
////                                    domBeg->parseAttributes();
////                                    out << domBeg->attribute("href").second << endl;
////                                }
////                                if (!domBeg->isTag())   // 如果不是html标签而是普通文本，那么就要进行空格处理
////                                {
////                                    temp = domBeg->text();  // 先将该文本提出取出来
////                                    temp.erase(0,temp.find_first_not_of(" \t\v\r\n"));  // 去掉' ', '\t', '\v', '\n', '\r'
////                                    temp.erase(temp.find_last_not_of(" \t\v\r\n") + 1);
////                                    if (!temp.empty())  // 如果剔除了空格字符之后还剩下其他字符，则保存到文件
////                                    {
////                                        out << temp << endl;
////                                        ++count;
////                                    }
////                                }
////                                if (count == 7)   // 已经找到7个字段，跳出循环，继续下一条博文的解析
////                                {
////                                    break;
////                                }
////                            }
////                        }
//                    }

                }
            }
        });
    } else {
        qDebug()<<Q_FUNC_INFO<<"no reply";
    }
}

QUrl CookieDataProvider::captchaImgUrl() const
{
    return m_captchaImgUrl;
}

void CookieDataProvider::setCaptcha(QString captcha)
{
    if (m_captcha == captcha)
        return;

    m_captcha = captcha;
    emit captchaChanged(captcha);
}

