INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/BaseRequest.h \
    $$PWD/QWeiboRequest.h \
    $$PWD/global.h \
    $$PWD/SingletonPointer.h \
    $$PWD/SingletonPointer_p.h \
    $$PWD/TokenProvider.h \
    $$PWD/LoginProvider.h \
    $$PWD/PluginRegister.h

SOURCES += \
    $$PWD/BaseRequest.cpp \
    $$PWD/global.cpp \
    $$PWD/TokenProvider.cpp \
    $$PWD/LoginProvider.cpp \
    $$PWD/PluginRegister.cpp
