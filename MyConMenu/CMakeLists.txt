cmake_minimum_required(VERSION 3.19)
project(MyConMenu)

set(CMAKE_CXX_STANDARD 20)

set(res AbstractMenuItem/AbstractMenuItem.h
        AbstractMenuItem/AbstractMenuItem.cpp
        CMenu/CMenu.cpp
        CMenu/CMenu.h
        CMenuItem/CMenuItem.h
        CMenuItem/CMenuItem.cpp)

add_library(MyConMenu ${res})