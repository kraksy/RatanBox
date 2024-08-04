
cmake_minimum_required(VERSION 3.10)
project(project VERSION 0.1)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../RatanBox/core/window/win32/src/include)

set(SOURCES
        ../RatanBox/core/window/win32/src/CoreGlobals.cpp
        ../RatanBox/core/window/win32/src/include/CoreGlobals.h
        ../RatanBox/core/window/win32/src/CoreRender.cpp
        ../RatanBox/core/window/win32/src/include/CoreRender.h
        ../RatanBox/core/window/win32/src/main.cpp
)

add_executable(project ${SOURCES})