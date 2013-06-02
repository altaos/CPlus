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
    graph.cpp \
    graphview.cpp \
    filemanager.cpp \
    subwindow.cpp \
    logger.cpp

HEADERS  += mainwindow.h \
    node.h \
    graph.h \
    graphview.h \
    filemanager.h \
    subwindow.h \
    logger.h

FORMS    += mainwindow.ui \
    subwindow.ui
	
QMAKE_CXXFLAGS += -std=c++11
