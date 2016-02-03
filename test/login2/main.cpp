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

#include "TokenProvider.h"
#include "PluginRegister.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app (new QGuiApplication(argc, argv));
    app.data ()->setOrganizationName ("SunRain");
    app.data ()->setApplicationName ("HackLoginTest");

    QWeiboSDK::registerPlugins ("harbour.sailfish_sinaweibo.sunrain");

    QScopedPointer<QQmlApplicationEngine> engine(new QQmlApplicationEngine(app.data ()));

    QWeiboSDK::TokenProvider *t = QWeiboSDK::TokenProvider::instance ();

    QQmlContext *ctx = engine.data ()->rootContext ();

    ctx->setContextProperty ("tokenProvider", t);

    engine.data ()->load (QUrl(QStringLiteral("qrc:/main.qml")));

    return app.data ()->exec ();
}
