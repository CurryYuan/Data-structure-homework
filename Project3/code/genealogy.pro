#-------------------------------------------------
#
# Project created by QtCreator 2017-11-23T20:40:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = genealogy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    tree.cpp \
    mylabel.cpp \
    borndialog.cpp \
    marriagedialog.cpp \
    divorcedialog.cpp \
    diedialog.cpp \
    rootdialog.cpp

HEADERS += \
        mainwindow.h \
    tree.h \
    mylabel.h \
    borndialog.h \
    marriagedialog.h \
    divorcedialog.h \
    diedialog.h \
    rootdialog.h

FORMS += \
        mainwindow.ui \
    borndialog.ui \
    marriagedialog.ui \
    divorcedialog.ui \
    diedialog.ui \
    rootdialog.ui
