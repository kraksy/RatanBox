# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project name
project(RatanBox)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/main.cpp
    src/foo.cpp
    src/bar.cpp
)

# Add executable target
add_executable(RatanBox ${SOURCES})