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
    $$PWD/PluginRegister.h \
    $$PWD/ImageUploader.h \
    $$PWD/HackLogin/HackRequestCookieJar.h


SOURCES += \
    $$PWD/BaseRequest.cpp \
    $$PWD/global.cpp \
    $$PWD/TokenProvider.cpp \
    $$PWD/LoginProvider.cpp \
    $$PWD/PluginRegister.cpp \
    $$PWD/HackLogin/HackRequestCookieJar.cpp

contains (CONFIG, WITH_HACKLOGIN) {
    DEFINES += WITH_HACKLOGIN
    INCLUDEPATH += $$PWD/HackLogin
    DEPENDPATH += $$PWD/HackLogin
    HEADERS += \
        $$PWD/HackLogin/BaseHackRequest.h \
        $$PWD/HackLogin/CookieDataProvider.h \
        $$PWD/HackLogin/HackFriendshipsGroups.h \
        $$PWD/HackLogin/LoginCookieJar.h

    SOURCES += \
        $$PWD/HackLogin/BaseHackRequest.cpp \
        $$PWD/HackLogin/CookieDataProvider.cpp \
        $$PWD/HackLogin/HackFriendshipsGroups.cpp \
        $$PWD/HackLogin/LoginCookieJar.cpp
}

contains (CONFIG, WITH_SDK_WRAPPER) {
    DEFINES += WITH_SDK_WRAPPER
    HEADERS += \
        $$PWD/Wrapper/FriendshipsGroupsWrapper.h \
        $$PWD/Wrapper/BaseWrapper.h

    SOURCES += \
        $$PWD/Wrapper/FriendshipsGroupsWrapper.cpp \
        $$PWD/Wrapper/BaseWrapper.cpp
}


