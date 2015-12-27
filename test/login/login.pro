#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T15:33:52
#
#-------------------------------------------------

QT       += core gui network

TARGET = tst_login
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    main.cpp \
    LoginProvider.cpp

HEADERS  += \
    Key.h \
    LoginProvider.h

FORMS    +=


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += openssl
