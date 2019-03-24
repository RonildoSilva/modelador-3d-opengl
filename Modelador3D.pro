#-------------------------------------------------
#
# Project created by QtCreator 2018-03-06T00:14:05
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modelador3D
TEMPLATE = app


LIBS += -lGLU -lglut

SOURCES += main.cpp \
    entities/torus.cpp \
    entities/model.cpp \
    entities/tree.cpp \
    entities/teapot.cpp \
    entities/cube.cpp \
    entities/luz.cpp \
    bib/Extra.cpp \
    bib/GUI.cpp

SOURCES += mainwindow.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/Vetor3D.cpp \
    oglwidget.cpp


HEADERS  += mainwindow.h \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/Vetor3D.h \
    oglwidget.h \
    entities/torus.h \
    entities/model.h \
    entities/tree.h \
    entities/teapot.h \
    entities/cube.h \
    entities/luz.h \
    bib/Extra.h \
    bib/GUI.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md


