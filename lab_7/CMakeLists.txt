cmake_minimum_required(VERSION 3.26)
project(lab_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_7 main.cpp
        lib/sort.cpp
        lib/sort.h
        helper/random.h
        helper/random.cpp
        helper/timer.cpp
        helper/timer.h
)
