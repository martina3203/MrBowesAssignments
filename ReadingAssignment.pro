#-------------------------------------------------
#
# Project created by QtCreator 2014-05-13T12:45:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReadingAssignment
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    finddialog.cpp \
    gotocelldialog.cpp \
    sortdialog.cpp

HEADERS  += mainwindow.h \
    finddialog.h \
    gotocelldialog.h \
    ui_gotocelldialog.h \
    sortdialog.h

FORMS    += mainwindow.ui \
    gotocelldialog.ui \
    sortdialog.ui
