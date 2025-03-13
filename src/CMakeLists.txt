cmake_minimum_required(VERSION 3.16)

project(drawQml VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(draw_Qml
    main.cpp
)

qt_add_qml_module(draw_Qml
    URI draw
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES PropertyShapePanel.qml
        QML_FILES ColorPicker.qml
)

add_subdirectory(lib)
add_subdirectory(qml)

target_link_libraries(draw_Qml
    PRIVATE Qt6::Quick
    PRIVATE mypainterplugin
)
