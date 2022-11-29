cmake_minimum_required(VERSION 3.23)
project(dGraph C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(dGraph
        DGraph.c
        DGraph.h
        List.c
        List.h
        testDGraph.c)
