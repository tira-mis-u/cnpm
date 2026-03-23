cmake_minimum_required(VERSION 3.16)
project(StudentMS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

set(SOURCES
    src/main.cpp
    src/models/student.cpp
    src/models/class_model.cpp
    src/models/department.cpp
    src/database/databasemanager.cpp
    src/controllers/studentcontroller.cpp
    src/controllers/classcontroller.cpp
    src/controllers/departmentcontroller.cpp
    src/views/mainwindow.cpp
    src/views/studentdialog.cpp
    src/views/classdialog.cpp
    src/views/departmentdialog.cpp
    src/views/logindialog.cpp
)

set(HEADERS
    src/models/student.h
    src/models/class_model.h
    src/models/department.h
    src/database/databasemanager.h
    src/controllers/studentcontroller.h
    src/controllers/classcontroller.h
    src/controllers/departmentcontroller.h
    src/views/mainwindow.h
    src/views/studentdialog.h
    src/views/classdialog.h
    src/views/departmentdialog.h
    src/views/logindialog.h
)

set(UI_FILES
    ui/mainwindow.ui
    ui/studentdialog.ui
    ui/classdialog.ui
    ui/departmentdialog.ui
    ui/logindialog.ui
)

qt_add_executable(StudentMS
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

target_include_directories(StudentMS PRIVATE
    src/models
    src/views
    src/controllers
    src/database
)

target_link_libraries(StudentMS PRIVATE
    Qt6::Widgets
    Qt6::Sql
)

# Đặt tên app và icon
set_target_properties(StudentMS PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
