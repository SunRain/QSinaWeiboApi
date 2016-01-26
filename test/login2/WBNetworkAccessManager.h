#ifndef WBNETWORKACCESSMANAGER_H
#define WBNETWORKACCESSMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>

class WBNetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit WBNetworkAccessManager(QObject *parent = 0);
    // QNetworkAccessManager interface
protected:
    QNetworkReply *createRequest(Operation op, const QNetworkRequest &request, QIODevice *outgoingData);
};

#endif // WBNETWORKACCESSMANAGER_H
