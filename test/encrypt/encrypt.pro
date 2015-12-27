#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T15:33:52
#
#-------------------------------------------------

QT       += core gui network

TARGET = tst_encrypt
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    main.cpp \

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += openssl
