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
    fractalwidget.cpp \
    sierpinskifractal.cpp \
    triangle.cpp \
    mandelbrotfractal.cpp \
    abstractfractal.cpp \
    sierpinskifractalwidget.cpp

HEADERS  += mainwindow.h \
    fractalwidget.h \
    abstractfractal.h \
    sierpinskifractal.h \
    triangle.h \
    mandelbrotfractal.h \
    sierpinskifractalwidget.h

FORMS    += mainwindow.ui \
    sierpinskifractalwidget.ui
