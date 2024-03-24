cmake_minimum_required(VERSION 3.26)
project(lab5)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab5 main.cpp
        lib/BST.cpp
        helper/range.cpp
        helper/range.h
        lib/timer.cpp)
