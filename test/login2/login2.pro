#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T15:33:52
#
#-------------------------------------------------

QT       += core gui network quick qml

TARGET = tst_login2
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    main.cpp \
    CookieDataProvider.cpp \
    LoginCookieJar.cpp

HEADERS  += \
    CookieDataProvider.h \
    LoginCookieJar.h

FORMS    +=

include (../../QWeiboSDK/QWeiboSDK.pri)

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += openssl htmlcxx

RESOURCES += \
    resource.qrc
