#-------------------------------------------------
#
# Project created by QtCreator 2013-11-25T10:44:29
#
#-------------------------------------------------

QT       += core gui

TARGET = CFK1
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    datasturct.cpp \
    mainwindow.cpp \
    init.cpp \
    deliverwindow.cpp \
    bosswindow.cpp

HEADERS  += login.h \
    datastruct.h \
    mainwindow.h \
    global.h \
    init.h \
    deliverwindow.h \
    bosswindow.h

FORMS    += login.ui \
    mainwindow.ui \
    deliverwindow.ui \
    bosswindow.ui

OTHER_FILES +=

RESOURCES += \
    image.qrc
