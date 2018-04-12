#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T22:16:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

include (/home/ws/tmp/opencv/c++/qzxing/src/QZXing.pri)

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

#LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui

LIBS += /usr/local/lib/libopencv_calib3d.so \
        /usr/local/lib/libopencv_core.so \
        /usr/local/lib/libopencv_dnn.so \
        /usr/local/lib/libopencv_features2d.so \
        /usr/local/lib/libopencv_flann.so \
        /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_imgcodecs.so \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_ml.so \
        /usr/local/lib/libopencv_objdetect.so \
        /usr/local/lib/libopencv_photo.so \
        /usr/local/lib/libopencv_shape.so \
        /usr/local/lib/libopencv_stitching.so \
        /usr/local/lib/libopencv_superres.so \
        /usr/local/lib/libopencv_videoio.so \
        /usr/local/lib/libopencv_video.so \
        /usr/local/lib/libopencv_videostab.so
