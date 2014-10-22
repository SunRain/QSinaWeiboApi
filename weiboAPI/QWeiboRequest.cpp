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


#include <QtDebug>
#include <QDir>
#include <QFile>
#include <QUrlQuery>
#include <QImage>
#include <QString>

#include "include/QWeiboPut.h"
#include "include/QWeiboRequest.h"
#include "include/QWeiboRequestApiList.h"

namespace QSinaWeiboAPI {

QWeiboRequest::QWeiboRequest():
    mEditable(false)
  , mType(Get)
//  , QObject(parent)
{
}

QWeiboRequest::WeiboRequestType QWeiboRequest::getRequestType() const
{
    return mType;
}

void QWeiboRequest::setRequestType(QWeiboRequest::WeiboRequestType type)
{
    mType = type;
}

QString QWeiboRequest::apiUrl() const
{
    if (!mApiUrl.isEmpty())
        return mApiUrl;
    return kApiHost + mApiPath + ".json";
}

QUrl QWeiboRequest::url() const
{
    QUrl url(apiUrl());
    if (!mParameters.isEmpty()) {
        QMap<QString, QVariant>::ConstIterator it = mParameters.constBegin();
        QUrlQuery urlQuery;
        for (; it != mParameters.constEnd(); ++it) {
            QString value = it.value().toString();
            if (value.isEmpty())
                continue;
            value = value.trimmed();
            urlQuery.addQueryItem(it.key(), value);
        }
        url.setQuery(urlQuery);
    }
    qDebug() << "request url with parameters: " << url.toString();
    return url;
}

QWeiboRequest& QWeiboRequest::prepare()
{
    if (mParameters.isEmpty()) {
        mEditable = true;
        initParameters();
        mEditable = false;
    }
    return *this;
}

QMap<QString, QVariant> QWeiboRequest::paramsters() const
{
    return mParameters;
}

QWeiboRequest& QWeiboRequest::operator ()(const QString& name, const QVariant& value)
{
    if (mEditable || mParameters.contains(name)) {
        qDebug() << name << "==>" << value;
        mParameters[name] = value;
    } else {
        qWarning() << "Can not set the parameter: " << name;
    }
    return *this;
}



//LoginRequest::LoginRequest():
//    QWeiboRequest()
//{
//    mType = Post;
//    mApiUrl = kOAuthUrl;
//}

} //namespace QWeiboAPI
