@echo off

set "project_dir=%~dp0"
set "build_dir=%project_dir%\..\..\build"
set "include_dir=%project_dir%\lib\include"

mkdir "%build_dir%"
pushd "%build_dir%"

call "D:\apps\VS\VC\Auxiliary\Build\vcvarsall.bat" x64
cl -Zi -EHsc -Fe "%project_dir%\src\main.cpp" user32.lib Gdi32.lib
popd