cmake_minimum_required(VERSION 3.26)
project(lab_9)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_9 main.cpp
        helper/timer.h
        helper/timer.cpp
        helper/random.cpp)
