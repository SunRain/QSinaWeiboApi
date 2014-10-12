#-------------------------------------------------
#
# Project created by QtCreator 2014-10-12T15:33:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeiboExamples
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


unix:!macx: LIBS += -L$$PWD/../../build-weiboAPI-Qt5-Debug/ -lQSinaWeiboAPI

INCLUDEPATH += $$PWD/../../weiboAPI/include
DEPENDPATH += $$PWD/../../weiboAPI/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../build-weiboAPI-Qt5-Debug/libQSinaWeiboAPI.a
