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
    $$PWD/ImageUploader.h

SOURCES += \
    $$PWD/BaseRequest.cpp \
    $$PWD/global.cpp \
    $$PWD/TokenProvider.cpp \
    $$PWD/LoginProvider.cpp \
    $$PWD/PluginRegister.cpp

contains (CONFIG, WITH_HACKLOGIN) {
    DEFINES += WITH_HACKLOGIN
    INCLUDEPATH += $$PWD/HackLogin
    DEPENDPATH += $$PWD/HackLogin
    HEADERS += \
        $$PWD/HackLogin/BaseHackRequest.h \
        $$PWD/HackLogin/CookieDataProvider.h \
        $$PWD/HackLogin/HackFriendshipsGroups.h \
        $$PWD/HackLogin/LoginCookieJar.h \
        $$PWD/HackLogin/HackRequestCookieJar.h \
        $$PWD/HackLogin/HackRemind.h \
        $$PWD/HackLogin/CookieJarBaseHackRequest.h \
        $$PWD/HackLogin/HackUsersInfo.h \
        $$PWD/HackLogin/HackFavorites.h \
        $$PWD/HackLogin/HackComments.h \
        $$PWD/HackLogin/HackSearch.h \
        $$PWD/HackLogin/HackStatuses.h

    SOURCES += \
        $$PWD/HackLogin/BaseHackRequest.cpp \
        $$PWD/HackLogin/CookieDataProvider.cpp \
        $$PWD/HackLogin/HackFriendshipsGroups.cpp \
        $$PWD/HackLogin/LoginCookieJar.cpp \
        $$PWD/HackLogin/HackRequestCookieJar.cpp \
        $$PWD/HackLogin/HackRemind.cpp \
        $$PWD/HackLogin/CookieJarBaseHackRequest.cpp \
        $$PWD/HackLogin/HackUsersInfo.cpp \
        $$PWD/HackLogin/HackStatuses.cpp \
        $$PWD/HackLogin/HackFavorites.cpp \
        $$PWD/HackLogin/HackComments.cpp \
        $$PWD/HackLogin/HackSearch.cpp
}

contains (CONFIG, WITH_SDK_WRAPPER) {
    DEFINES += WITH_SDK_WRAPPER
    HEADERS += \
        $$PWD/Wrapper/FriendshipsGroupsWrapper.h \
        $$PWD/Wrapper/BaseWrapper.h \
        $$PWD/Wrapper/StatusesWrapper.h \
        $$PWD/Wrapper/FavoritesWrapper.h \
        $$PWD/Wrapper/CommentsWrapper.h \
        $$PWD/Wrapper/SearchWrapper.h

    SOURCES += \
        $$PWD/Wrapper/FriendshipsGroupsWrapper.cpp \
        $$PWD/Wrapper/BaseWrapper.cpp \
        $$PWD/Wrapper/StatusesWrapper.cpp \
        $$PWD/Wrapper/FavoritesWrapper.cpp \
        $$PWD/Wrapper/CommentsWrapper.cpp \
        $$PWD/Wrapper/SearchWrapper.cpp
}


