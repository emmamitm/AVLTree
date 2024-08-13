cmake_minimum_required(VERSION 3.26)
project(GatorAVL)

set(CMAKE_CXX_STANDARD 17)

add_executable(GatorAVL main.cpp
        AVL.h
        CodeRunner.h
        test.cpp)
