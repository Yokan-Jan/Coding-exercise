#-------------------------------------------------
#
# Project created by QtCreator 2016-04-27T13:32:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

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
