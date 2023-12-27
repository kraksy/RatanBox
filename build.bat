@echo off

mkdir ..\..\build
pushd ..\..\build
cl -Zi %~dp0\src\main.cpp user32.lib Gdi32.lib
popd