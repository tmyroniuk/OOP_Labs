cmake_minimum_required(VERSION 3.14)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp CList/CList.cpp CList/CList.h CList/List/Node.cpp CList/List/Node.h CList/List/List.cpp CList/List/List.h Vector.cpp Vector.h CList/List/Iterator.cpp CList/List/Iterator.h)