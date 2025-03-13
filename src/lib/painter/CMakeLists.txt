cmake_minimum_required(VERSION 3.16)

project(mypainter)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR}/qml ${CMAKE_BINARY_DIR}/imports CACHE STRING "" FORCE)

find_package(Qt6 6.4 REQUIRED COMPONENTS Core Quick QuickControls2 Gui)

qt_add_library(mypainter STATIC)
qt_add_qml_module(mypainter
    URI "MyPainter"
    VERSION 1.0
    # SOURCES
    # mypainter.h
    # mypainter.cpp
    # SOURCES rectanglepainter.h rectanglepainter.cpp
    # SOURCES shapenode.h shapenode.cpp
    # SOURCES rectanglenode.h rectanglenode.cpp
    # SOURCES circle.h circle.cpp
    SOURCES canvasitem.h canvasitem.cpp
    # SOURCES linenode.h linenode.cpp
    SOURCES shape.h shape.cpp
    SOURCES rectangleshape.h rectangleshape.cpp
    SOURCES lineshape.h lineshape.cpp
    SOURCES shapesmodel.h shapesmodel.cpp
)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)

# target_include_directories(painterBackend PUBLIC
#         "${PROJECT_BINARY_DIR}"
#         "${PROJECT_SOURCE_DIR}"
# )
set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)

target_link_libraries(mypainter PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Gui
)
