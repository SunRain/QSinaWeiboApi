#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T14:43:37
#
#-------------------------------------------------

QT       += network

TARGET = QSinaWeiboSDK
TEMPLATE = lib
CONFIG   += console
CONFIG += c++11

include (QWeiboSDK.pri)

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

