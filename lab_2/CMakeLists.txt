cmake_minimum_required(VERSION 3.26)
project(lab_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_2 main.cpp
        lib/list.h
        lib/list.cpp
        lib/stack.cpp
        lib/stack.h
        lib/node.cpp
        lib/node.h
        helper/random.cpp
        helper/random.h
        lib/iterator.cpp
        lib/iterator.h
        lib/tab_stack.cpp
        lib/tab_stack.h
        lib/queue.cpp
        lib/queue.h)
