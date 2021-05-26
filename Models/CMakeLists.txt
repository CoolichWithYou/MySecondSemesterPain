cmake_minimum_required(VERSION 3.17)
project(Models)

set(CMAKE_CXX_STANDARD 20)

set(res Subject/Subject.cpp Subject/Subject.h
        Human/Human.cpp Human/Human.h)

add_library(Models ${res})
