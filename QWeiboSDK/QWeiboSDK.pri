INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

CONFIG += c++11
QT     += network

HEADERS += \
    $$PWD/BaseRequest.h \
    $$PWD/QWeiboRequest.h \
    $$PWD/global.h \
    $$PWD/SingletonPointer.h \
    $$PWD/SingletonPointer_p.h \
    $$PWD/TokenProvider.h \
    $$PWD/LoginProvider.h \
    $$PWD/PluginRegister.h \
    $$PWD/ImageUploader.h

SOURCES += \
    $$PWD/BaseRequest.cpp \
    $$PWD/global.cpp \
    $$PWD/TokenProvider.cpp \
    $$PWD/LoginProvider.cpp \
    $$PWD/PluginRegister.cpp

contains (CONFIG, WITH_HACKLOGIN) {
include (HackLogin/HackLogin.pri)
}

