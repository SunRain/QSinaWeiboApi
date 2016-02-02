QT       += core gui network quick qml

TARGET = tst_login2
TEMPLATE = app

CONFIG += c++11
CONFIG += WITH_HACKLOGIN

SOURCES += \
    main.cpp

FORMS    +=

include (../../QWeiboSDK/QWeiboSDK.pri)

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += openssl htmlcxx

RESOURCES += \
    resource.qrc
