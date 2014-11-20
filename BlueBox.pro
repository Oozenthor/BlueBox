#-------------------------------------------------
#
# Project created by QtCreator 2014-10-26T08:20:46
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlueBox
TEMPLATE = app


SOURCES += main.cpp\
        bluebox.cpp \
    serialdialog.cpp \
    zlamp.cpp

HEADERS  += bluebox.h \
    serialdialog.h \
    zlamp.h \
    bits.h

FORMS    += bluebox.ui \
    serialdialog.ui

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    LICENSE
