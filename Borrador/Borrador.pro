#-------------------------------------------------
#
# Project created by QtCreator 2014-10-15T09:18:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Borrador
TEMPLATE = app


SOURCES += main.cpp\
    calificacion.cpp \
    materia.cpp \
    pInicial.cpp \
    pPrincipal.cpp \
    semestre.cpp \
    estudiante.cpp

HEADERS  += \
    calificacion.h \
    materia.h \
    pInicial.h \
    pPrincipal.h \
    semestre.h \
    estudiante.h

FORMS    += \
    principal.ui \
    inicial.ui
