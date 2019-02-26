#-------------------------------------------------
#
# Project created by QtCreator 2019-02-25T10:05:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JHvisionFoundation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ImageBuffer.cpp \
    hikvision.cpp \
    globalvariable.cpp \
    camera.cpp \
    inputdata.cpp \
    processing.cpp \
    usbcam.cpp \
    video.cpp \
    picture.cpp

HEADERS  += mainwindow.h \
    ImageBuffer.h \
    hikvision.h \
    globalvariable.h \
    camera.h \
    inputdata.h \
    processing.h \
    usbcam.h \
    video.h \
    picture.h

FORMS    += mainwindow.ui

# opencv3.1.0
LIBS += -L G:/opencv3.1.0/mingw32/install/x86/mingw/lib/libopencv_*.a
INCLUDEPATH += G:/opencv3.1.0/mingw32/install/include \
               G:/opencv3.1.0/mingw32/install/include/opencv \
               G:/opencv3.1.0/mingw32/install/include/opencv2

# hik win32
LIBS += -L G:/hikSDK/win32/bin/*.lib
INCLUDEPATH += G:/hikSDK/win32/include
