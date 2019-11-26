cmake_minimum_required(VERSION 3.5)

project(Lab2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Qt5Multimedia REQUIRED)

add_executable(Lab2
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
        Timers/timer.h
        Timers/timer.cpp
        Timers/timerclock.h
        Timers/timerclock.cpp
        Timers/alarmclock.h
        Timers/alarmclock.cpp
  improvisedmodel.h
  improvisedmodel.cpp
        Dialog/timerdialog.h
        Dialog/timerdialog.cpp
        Dialog/timerdialog.ui
  alarmdialog.h
  alarmdialog.cpp
  alarmdialog.ui
  icons.qrc
        timernotification.h
        timernotification.cpp
        timernotification.ui
)

target_link_libraries(Lab2 PRIVATE Qt5::Widgets)
target_link_libraries(Lab2 PRIVATE Qt5::Multimedia)
