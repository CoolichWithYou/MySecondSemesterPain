cmake_minimum_required(VERSION 3.17)
project(State)

set(CMAKE_CXX_STANDARD 20)

set(res State.cpp State.h
        Store.cpp Store.h)

include_directories(../Models)

include_directories(../cereal)

add_library(State ${res})

target_link_libraries(State Models)
