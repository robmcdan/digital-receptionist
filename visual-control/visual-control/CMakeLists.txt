cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS  "-lboost_system -lpthread -lboost_thread")
project(visual_control)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    cognition/detector/detailedfacedetector.cpp
    cognition/detector/detailedfacedetector.h
    cognition/detector/facedetector.cpp
    cognition/detector/facedetector.h
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
        gui/visualcontrol_gui.cpp
        gui/visualcontrol_gui.h
        gui/webcamwidget_gui.cpp
        gui/webcamwidget_gui.h
    logger.cpp
    logger.h
    main.cpp
    visualcontrol.cpp
    visualcontrol.h
    visualcontrol.qrc
    webcamwidget.cpp
    webcamwidget.h
    cognition/recognizer/fisherfacerecognizer.cpp
    cognition/recognizer/fisherfacerecognizer.h)

add_executable(visual_control ${SOURCE_FILES})

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem thread)
find_package(Qt5Widgets REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
target_link_libraries(visual_control ${Boost_LIBRARIES})

include_directories(/usr/include/qt5)

include_directories(${OpenCV_INCLUDE_DIR} )
target_link_libraries( visual_control ${OpenCV_LIBRARIES} )
target_link_libraries( visual_control Qt5::Widgets )
TARGET_LINK_LIBRARIES(visual_control ${OpenCV_LIBS} ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY})
