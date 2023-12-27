@echo off

set "project_dir=%~dp0"
set "build_dir=%project_dir%\..\..\build"

mkdir "%build_dir%"
pushd "%build_dir%"
cl -Zi "%project_dir%\src\main.cpp" user32.lib Gdi32.lib /showIncludes /I "include"
popd