#-------------------------------------------------
#
# Project created by QtCreator 2013-05-25T18:33:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graph
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    edge.cpp \
    graph.cpp \
    graphview.cpp \
    filemanager.cpp \
    subwindow.cpp

HEADERS  += mainwindow.h \
    node.h \
    edge.h \
    graph.h \
    graphview.h \
    filemanager.h \
    subwindow.h

FORMS    += mainwindow.ui \
    subwindow.ui
