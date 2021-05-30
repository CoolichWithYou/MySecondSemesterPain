cmake_minimum_required(VERSION 3.17)
project(Color)

set(CMAKE_CXX_STANDARD 20)

set(res Color.cpp Color.h)

add_library(Color ${res})
