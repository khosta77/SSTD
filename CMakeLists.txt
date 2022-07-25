cmake_minimum_required(VERSION 3.4)
project(main)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        Queue/SQueue.h
        Stack/SStack.h
        List/SList.h
        Vector/SVector.h
        src/main.cpp
        )