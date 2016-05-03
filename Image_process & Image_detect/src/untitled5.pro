#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T13:50:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    res.qrc \
    res.qrc

INCLUDEPATH+=D:\opencv\build\include\
INCLUDEPATH+=D:\opencv\build\include\opencv\
INCLUDEPATH+=D:\opencv\build\include\opencv2\

LIBS+=D:\opencv\lib\libopencv_calib3d249.dll.a\
        D:\opencv\lib\libopencv_contrib249.dll.a\
        D:\opencv\lib\libopencv_core249.dll.a\
        D:\opencv\lib\libopencv_features2d249.dll.a\
        D:\opencv\lib\libopencv_flann249.dll.a\
        D:\opencv\lib\libopencv_gpu249.dll.a\
        D:\opencv\lib\libopencv_highgui249.dll.a\
        D:\opencv\lib\libopencv_imgproc249.dll.a\
        D:\opencv\lib\libopencv_legacy249.dll.a\
        D:\opencv\lib\libopencv_ml249.dll.a\
        D:\opencv\lib\libopencv_objdetect249.dll.a\
        D:\opencv\lib\libopencv_video249.dll.a\
