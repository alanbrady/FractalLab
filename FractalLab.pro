#-------------------------------------------------
#
# Project created by QtCreator 2013-04-12T09:14:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FractalLab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sierpinskifractal.cpp \
    triangle.cpp \
    mandelbrotfractal.cpp \
    abstractfractal.cpp \
    sierpinskifractalwidget.cpp \
    fractaldisplaywidget.cpp \
    abstractfractalwidget.cpp \
    mandelbrotfractalwidget.cpp \
    juliafractal.cpp \
    juliafractalwidget.cpp

HEADERS  += mainwindow.h \
    abstractfractal.h \
    sierpinskifractal.h \
    triangle.h \
    mandelbrotfractal.h \
    sierpinskifractalwidget.h \
    fractaldisplaywidget.h \
    abstractfractalwidget.h \
    mandelbrotfractalwidget.h \
    juliafractal.h \
    juliafractalwidget.h

FORMS    += mainwindow.ui \
    sierpinskifractalwidget.ui \
    mandelbrotfractalwidget.ui \
    juliafractalwidget.ui
