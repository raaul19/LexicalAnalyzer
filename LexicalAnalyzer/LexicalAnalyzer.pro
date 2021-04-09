#-------------------------------------------------
#
# Project created by QtCreator 2021-03-16T09:14:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LexicalAnalyzer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    analyzer.cpp \
    automatum.cpp

HEADERS  += mainwindow.h \
    analyzer.h \
    automatum.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
