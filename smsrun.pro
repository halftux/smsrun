#-------------------------------------------------
#
# Project created by QtCreator 2015-08-07T19:00:44
#
#-------------------------------------------------

QT       += core dbus

QT       -= gui

TARGET = smsrun
CONFIG += sailfishapp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += src/main.cpp \
    src/mainclass.cpp \
    src/smsrun.cpp

HEADERS += \
    src/mainclass.h \
    src/smsrun.h

addF1.files = cmdlist.txt
addF1.path = /home/nemo/.config/smsrun/
addF2.files = whitelist.txt
addF2.path = /home/nemo/.config/smsrun/

INSTALLS += addF1 \
    addF2
