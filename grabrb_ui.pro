#-------------------------------------------------
#
# Project created by QtCreator 2020-09-22T13:48:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = grabrb_ui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11

#添加ROS库
INCLUDEPATH += /opt/ros/kinetic/include
DEPENDPATH += /opt/ros/kinetic/include
LIBS += -L/opt/ros/kinetic/lib -lroscpp -lroslib -lrosconsole -lroscpp_serialization -lrostime -lcv_bridge

#添加OpenCV
INCLUDEPATH += /opt/ros/kinetic/include/opencv-3.3.1-dev/opecv \
                /opt/ros/kinetic/include/opencv-3.3.1-dev/opecv2 \
                /opt/ros/kinetic/include \
                /opt/ros/kinetic/include/opencv-3.3.1-dev
LIBS +=  /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv*

INCLUDEPATH += /home/fshs/catkin_ws/devel/include

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        gobangwidget.cpp \
        cubewidget.cpp \
        dulgripperwidget.cpp

HEADERS += \
        mainwindow.h \
        gobangwidget.h \
        cubewidget.h \
        dulgripperwidget.h


FORMS += \
        mainwindow.ui \
        gobangwidget.ui \
        cubewidget.ui \
        dulgripperwidget.ui

RESOURCES += \
    photosource.qrc
