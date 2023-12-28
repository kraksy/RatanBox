@echo off

set "project_dir=%~dp0"
set "build_dir=%project_dir%\..\..\build"
set "include_dir=%project_dir%\lib\include"

mkdir "%build_dir%"
pushd "%build_dir%"

for /D %%d in ("%include_dir%\*") do (
    set "INCLUDE=%%d;%INCLUDE%"
    echo Added %%d to INCLUDE
)

cl -Zi "%project_dir%\src\main.cpp" user32.lib Gdi32.lib glfw3.lib /showIncludes /I lib\include\glm\glm.hpp
popd