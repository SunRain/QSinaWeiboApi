TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = weiboAPI examples #tests

weiboAPI.file = weiboAPI/weiboAPI.pro
examples.depends += weiboAPI
tests.depends += weiboAPI

OTHER_FILES += \
    scripts/*.sh

EssentialDepends =
OptionalDepends =

