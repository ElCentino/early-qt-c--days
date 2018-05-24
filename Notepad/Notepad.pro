#-------------------------------------------------
#
# Project created by QtCreator 2014-08-19T23:17:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad
TEMPLATE = app


SOURCES += main.cpp\
    finddialog.cpp \
    about.cpp \
    replacedialog.cpp \
    gotoline.cpp \
    window.cpp \
    settings.cpp

HEADERS  += \
    finddialog.h \
    about.h \
    replacedialog.h \
    gotoline.h \
    window.h \
    settings.h \
    overloads.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

win32:RC_ICONS += images/notepad2.ico
