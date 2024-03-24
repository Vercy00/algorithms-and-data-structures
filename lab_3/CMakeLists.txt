cmake_minimum_required(VERSION 3.26)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_3 main.cpp
        helper/random.cpp
        lib/node.cpp
        lib/list.cpp
        lib/iterator.cpp
        lib/stack.cpp
        lib/queue.cpp
        lib/queue.h)
