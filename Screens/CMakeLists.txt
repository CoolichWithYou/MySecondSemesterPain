cmake_minimum_required(VERSION 3.17)
project(Screens)

set(CMAKE_CXX_STANDARD 20)

set(res InterfaceScreen.h InterfaceScreen.cpp
        Auth/Auth.cpp Auth/Auth.h)

add_library(Screens ${res})
