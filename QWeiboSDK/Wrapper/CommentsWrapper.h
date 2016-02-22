#ifndef COMMENTSWRAPPER_H
#define COMMENTSWRAPPER_H

#include <QObject>

#include "global.h"
#include "BaseWrapper.h"

namespace QWeiboSDK {
namespace Wrapper {

//get
class QWEIBOSDK_EXPORT WrapperCommentsShow : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperCommentsShow(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString parseContent(const QString &content);
};

//post
class QWEIBOSDK_EXPORT WrapperCommentsReply : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperCommentsReply(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString convertParameterKey(const QString &key);
};

//post
class QWEIBOSDK_EXPORT WrapperCommentsCreate : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperCommentsCreate(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString convertParameterKey(const QString &key);
};

class QWEIBOSDK_EXPORT WrapperCommentsMentions : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperCommentsMentions(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString parseContent(const QString &content);
};

class QWEIBOSDK_EXPORT WrapperCommentsTimeline : public BaseWrapper
{
    Q_OBJECT
public:
    explicit WrapperCommentsTimeline(QObject *parent = 0);

    // BaseWrapper interface
protected:
    QString parseContent(const QString &content);
};

} //Wrapper
} //QWeiboSDK
#endif // COMMENTSWRAPPER_H
