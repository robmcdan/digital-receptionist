cmake_minimum_required(VERSION 3.6)
project(visual_control)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    cognition/detector/detailedfacedetector.cpp
    cognition/detector/detailedfacedetector.h
    cognition/detector/facedetector.cpp
    cognition/detector/facedetector.h
    cognition/recognizer/eigenfacerecognizer.cpp
    cognition/recognizer/eigenfacerecognizer.h
    cognition/Controller.h
    cognition/detector.cpp
    cognition/detector.h
    cognition/framecapture.cpp
    cognition/framecapture.h
    cognition/framereceiver.h
    cognition/recognizer.h
    cognition/trainerimage.cpp
    cognition/trainerimage.h
    cognition/util.h
    gui/visualcontrol.cpp
    gui/visualcontrol.h
    gui/webcamwidget.cpp
    gui/webcamwidget.h
    logger.cpp
    logger.h
    main.cpp
    visualcontrol.cpp
    visualcontrol.h
    visualcontrol.qrc
    webcamwidget.cpp
    webcamwidget.h)

add_executable(visual_control ${SOURCE_FILES})

include_directories(/home/rob/git/boost)
include_directories(/usr/include/qt4)