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
    include/QWeiboPut.h \
    include/QWeiboMethod.h \
    include/QWeiboRequestApiList.h \
    include/QWeiboRequest.h

SOURCES += \
    qweiboapi_global.cpp \
    QSinaWeibo.cpp \
    QWeiboPut.cpp \
    QWeiboRequest.cpp \
    QWeiboMethod.cpp

OTHER_FILES += \
    SailfishWeiboAPI.pro
