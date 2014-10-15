/******************************************************************************
    Weibo: login, logout and upload api
    Copyright (C) 2012 Wang Bin <wbsecg1@gmail.com>
    Copyright (C) 2014 wanggjghost <41245110@qq.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
******************************************************************************/

#ifndef QWEIBOAPI_WEIBO_H
#define QWEIBOAPI_WEIBO_H

#include <QObject>

#include "qweiboapi_global.h"

class QWeiboPut;
namespace QSinaWeiboAPI {
class QWeiboRequest;
class QWEIBOAPI_EXPORT QSinaWeibo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString accessToken READ getAccessToken WRITE setAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(QString username WRITE setUser)
    Q_PROPERTY(QString password WRITE setPassword)
    Q_PROPERTY(QString uid READ getUid WRITE setUid)

public:
    explicit QSinaWeibo(QObject *parent = 0);
    ~QSinaWeibo();
    void setUser(const QString& user);
    void setPassword(const QString& passwd);
    
    QString getAccessToken() const;
    void setAccessToken(const QString& token);

    QString getUid() const;
    void setUid(const QString &uid);
    
    //take the ownership
    void createRequest(QWeiboRequest* request);
    Q_INVOKABLE void login();
    Q_INVOKABLE void logout();
//    void updateStatusWithPicture(const QString& status, const QString& fileName);
    
signals:
    void weiboPutFail(const QString& weiboPutFail);
    void loginSucceed(const QString &accessToken, const QString &uid);
    void loginFail(const QString &fail);
    //void sendOk();
    void weiboPutSucceed(const QString& replyData);
    void accessTokenChanged();

public slots:

private slots:
    void processNextRequest(); //process 1 request
    void parseOAuth2ReplyData(const QString& data);
    //void sendStatusWithPicture();
    void dumpOk(const QString& data);
    void dumpError(const QString& weiboPutFail);
private:
    QWeiboPut *mPut;
    QList<QWeiboRequest*> mRequests; //pending requests that start when login ok
    QString mUser, mPasswd;
    QString mAccessToken;
    QString mUid;
    QString mStatus, mFile;
};
} //namespace QWeiboAPI
#endif // QWEIBOAPI_WEIBO_H
