#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T19:42:54
#
#-------------------------------------------------

QT       += core gui\
                    serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StandTrend
TEMPLATE = app


SOURCES += main.cpp\
                mainwindow.cpp \
                    serialporthandler.cpp \
    stm32vcp.cpp

HEADERS  += mainwindow.h \
                     stm32vcp.h \
                        serialporthandler.h

FORMS    += mainwindow.ui

DISTFILES += \
         ReadMe.txt
