cmake_minimum_required(VERSION 3.15)
project(Shape_classes)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shape_classes main.cpp shape.h shape.cpp square.h square.cpp rectangle.h rectangle.cpp circle.h circle.cpp triangle.h triangle.cpp)