cmake_minimum_required(VERSION 3.26)
project(lab_8)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_8 main.cpp
        lib/sort.cpp
        lib/sort.h
        entity/patient.cpp
        entity/patient.h
        helper/add_source.cpp
        helper/add_source.h)
