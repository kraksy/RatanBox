
cmake_minimum_required(VERSION 3.12)

project(RatanBox VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory("core/window/x11")
add_subdirectory("core/window/win32")
add_subdirectory("core/window/raylib")
add_subdirectory("core/window/curses")
add_subdirectory("core/window/sdl2")
add_subdirectory("core/window/sfml")

target_link_libraries(win PUBLIC "win32")
target_include_directories(win32 PUBLIC "core/window/win32")