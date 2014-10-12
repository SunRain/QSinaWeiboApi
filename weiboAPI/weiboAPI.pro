#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T14:43:37
#
#-------------------------------------------------

QT       += network

TARGET = QSinaWeiboAPI
TEMPLATE = lib
#CONFIG += staticlib
CONFIG   += console

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

HEADERS += \
    include/version.h \
    include/qweiboapi_global.h \
    include/dptr.h \
    include/QSinaWeibo.h \
    include/RequestApiList.h \
    include/Request.h \
    include/QWeiboPut.h \
    include/QWeiboMethod.h

SOURCES += \
    qweiboapi_global.cpp \
    Request.cpp \
    QSinaWeibo.cpp \
    QWeiboPut.cpp
