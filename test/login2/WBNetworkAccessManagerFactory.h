#ifndef WBNETWORKACCESSMANAGERFACTORY_H
#define WBNETWORKACCESSMANAGERFACTORY_H

#include <QQmlNetworkAccessManagerFactory>

class WBNetworkAccessManagerFactory : public QObject, public QQmlNetworkAccessManagerFactory
{
    Q_OBJECT
public:
    explicit WBNetworkAccessManagerFactory();

    // QQmlNetworkAccessManagerFactory interface
public:
    QNetworkAccessManager *create(QObject *parent);
};

#endif // WBNETWORKACCESSMANAGERFACTORY_H
