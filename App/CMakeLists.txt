cmake_minimum_required(VERSION 3.17)
project(App)

set(CMAKE_CXX_STANDARD 20)

set(res app.cpp app.h)

add_library(App ${res})
