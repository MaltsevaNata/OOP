cmake_minimum_required(VERSION 3.9)
project(Task)

set(CMAKE_CXX_STANDARD 14)

add_library(spline spline.cpp spline.h)

add_executable(Task main.cpp)

target_link_libraries(Task spline)