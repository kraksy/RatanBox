
cmake_minimum_required(VERSION 3.12)

project(RatanBox VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(core\window\x11)
add_subdirectory(core\window\win32)
add_subdirectory(core\window\raylib)
add_subdirectory(core\window\curses)
add_subdirectory(core\window\sdl2)
add_subdirectory(core\window\sfml)
add_subdirectory(core\window\x11)

set(SOURCES
      src/main.cpp
      src/foo.cpp
      src/bar.cpp
)

# Add your header files here
set(HEADERS
      include/foo.h
      include/bar.h
)

# Create an executable target
add_executable(MyExecutable ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(MyExecutable PRIVATE include)