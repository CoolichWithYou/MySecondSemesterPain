cmake_minimum_required(VERSION 3.19)
project(opi-dz)

set(CMAKE_CXX_STANDARD 20)

include_directories(Models)

include_directories(MyConMenu)

include_directories(App)

include_directories(Screens)

include_directories(.)

include_directories(State)

add_subdirectory(Models)

add_subdirectory(MyConMenu)

add_subdirectory(App)

add_subdirectory(State)

add_subdirectory(Screens)

add_executable(opi-dz main.cpp)

target_link_libraries(opi-dz MyConMenu Models App State Screens)