
#pragma once 
#include <iostream>
#include <windows.h>

class win32wnd
{
public:
    typedef struct
    {   HINSTANCE instance;
        HWND hndl;
        LPCWSTR className;
        LPCWSTR title;
        int resX;
        int resY;
        int width;
        int height;

        int prevX;
        int prevY;
        int prevWidth;
        int prevHeight;
    }Window;

    static Window create_window(HINSTANCE instance);
    static void create_context();
};