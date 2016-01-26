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
    LoginProvider.cpp \
    WBNetworkAccessManager.cpp \
    WBNetworkAccessManagerFactory.cpp \
    CookieDataProvider.cpp

HEADERS  += \
    Key.h \
    LoginProvider.h \
    WBNetworkAccessManager.h \
    WBNetworkAccessManagerFactory.h \
    CookieDataProvider.h

FORMS    +=


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += openssl htmlcxx

RESOURCES += \
    resource.qrc
