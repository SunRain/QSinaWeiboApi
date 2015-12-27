TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += weiboAPI examples QWeiboSDK test

weiboAPI.file = weiboAPI/weiboAPI.pro
examples.depends += weiboAPI
tests.depends += weiboAPI

OTHER_FILES += \
    scripts/*.sh

EssentialDepends =
OptionalDepends =

