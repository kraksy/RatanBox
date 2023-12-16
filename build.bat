@echo off

mkdir ..\..\build
pushd ..\..\build
cl -Zi C:\Users\kraks\Desktop\RatanBox\code\main.cpp user32.lib
popd