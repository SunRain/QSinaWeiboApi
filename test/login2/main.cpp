#include <QCoreApplication>
#include <QScopedPointer>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QGuiApplication>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QList>

#include <QDebug>

#include "WBNetworkAccessManager.h"
#include "WBNetworkAccessManagerFactory.h"

#include "CookieDataProvider.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app (new QGuiApplication(argc, argv));

    CookieDataProvider *provider = new CookieDataProvider();

    QScopedPointer<QQmlApplicationEngine> engine(new QQmlApplicationEngine(app.data ()));

//    QScopedPointer<WBNetworkAccessManagerFactory> factory (new WBNetworkAccessManagerFactory());
//    engine.data ()->setNetworkAccessManagerFactory (factory.data ());

    QQmlContext *ctx = engine.data ()->rootContext ();
    ctx->setContextProperty ("loginProvider", provider);
    engine.data ()->load (QUrl(QStringLiteral("qrc:/main.qml")));

    return app.data ()->exec ();
}
