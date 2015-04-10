/******************************************************************************
    QPut: make post easy
    Copyright (C) 2012 Wang Bin <wbsecg1@gmail.com>
    Copyright (C) 2015 wanggjghost <41245110@qq.com>

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

#ifndef QWEIBOPUT_H
#define QWEIBOPUT_H

#include <QSslError>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;
class QWeiboPut : public QObject
{
    Q_OBJECT
public:
    QWeiboPut(QObject* parent = 0);
    explicit QWeiboPut(const QUrl &pUrl, QObject* parent = 0);
    ~QWeiboPut();

    void reset(); //call it before a new post
    //equals setSnapshotData(pData) then start()
    void addTextPart(const QByteArray& name, const QByteArray& body);
    void addDataPart(const QByteArray& mine, const QByteArray& name, const QByteArray& data, const QString& fileName = QString());
    void upload();
    void post();
    void get();

    void setData(const QByteArray& pData);
    void setUrl(const QUrl& pUrl);

signals:
    void fail(const QUrl &requestedUrl, const QString& error);
    void ok(const QUrl &requestedUrl, const QString& replyData);
public slots:
    void abort();
private slots:
    void DoFinished();
//    void DoReplyError();

private:
    void init();

    QNetworkAccessManager *mNetwork;
    QNetworkReply *mReply;
    QUrl mUrl;
    bool mSuccess;
    bool mRequestAborted;
    QByteArray mData;
    QByteArray mTextPart, mDataPart;
    QByteArray mBoundary;
};
#endif // QWEIBOPUT_H
