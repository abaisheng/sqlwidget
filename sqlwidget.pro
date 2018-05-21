#-------------------------------------------------
#
# Project created by QtCreator 2018-05-12T20:04:47
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqlwidget
TEMPLATE = app


SOURCES += main.cpp\
    stumanager.cpp \
    teamanager.cpp \
    mainwidget.cpp

HEADERS  += \
    stumanager.h \
    teamanager.h \
    mainwidget.h \
    connectdb.h

FORMS    += \
    stumanager.ui \
    teamanager.ui \
    mainwidget.ui

DISTFILES += \
    bugs.txt

RC_ICONS = school.ico
