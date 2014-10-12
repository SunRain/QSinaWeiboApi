/******************************************************************************
    Weibo: login, logout and upload api
    Copyright (C) 2012-2014 Wang Bin <wbsecg1@gmail.com>
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

#ifndef QWEIBOAPI_REQUEST_H
#define QWEIBOAPI_REQUEST_H

#include <QMap>
#include <QVariant>

#include "qweiboapi_global.h"

namespace QSinaWeiboAPI {

static const QString kOAuthUrl = "https://api.weibo.com/oauth2/access_token";
static const QString kApiHost = "https://api.weibo.com/";
//appkey, appsecret are weico for iOS
//static QString sAppKey = "82966982";
//static QString sAppSecret = "72d4545a28a46a6f329c4f2b1e949e6a";
static QString sAppKey = "2323547071";
static QString sAppSecret = "16ed80cc77fea11f7f7e96eca178ada3";

class QWEIBOAPI_EXPORT Request
{
public:
    enum RequestType {
        Get, Post
    };
    Request();
    virtual ~Request() {}
    RequestType type() const;
    QString apiUrl() const;
    QUrl url() const; //apiUrl() + parameters
    /*!
     * \brief prepare
     * \return
     * initialize api parameters. usually you don't have to call it. do nothing if already called
     */
    Request& prepare();
    //only the existing (name, value) will be modified, otherwise do nothing
    Request& operator ()(const QString& name, const QVariant& value);
    void addImage(const QString& file);
    void addImage(const QByteArray& data, const QString& format);

    QMap<QString, QVariant> paramsters() const;
protected:
    virtual void initParameters() {qDebug("Request::initParameters() !!!");}

    bool mEditable; //true in ctor
    RequestType mType;
    QString mApiUrl;
    QString mApiPath;
    QMap<QString, QVariant> mParameters;
};

} //namespace QWeiboAPI
#endif // QWEIBOAPI_REQUEST_H
