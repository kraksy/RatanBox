
#pragma once

#include <iostream>
#include <windows.h>

class window32
{
public:
      
      window32();
      ~window32();

      void create_context();
      void create_window(std::string title, HINSTANCE instance);

      bool shouldClose();
      void ResizeWindow(RECT *WindowRect, int X, int Y, int Width, int Height);
      void ResizeWindow(RECT *WindowRect);
      void ResizeWindow(int X, int Y, int Width, int Height);

      void center_window(HDC DeviceContext);
      
      void set_fullscreen(HDC DeviceContext);
      
      void set_window_title();
      void set_window_size();
      void set_window_position();

      void close_window();
};

window32::window32()
{

}

window32::~window32()
{
}

void window32::create_context()
{     
      
}

void window32::ResizeWindow(RECT *WindowRect, int X, int Y, int Width, int Height)
{
 
}

bool window32::shouldClose(UINT message) // [should close?] question function for loop
{
      if (message == WM_CLOSE)
      {
            return true;
      }
      if (message == WM_DESTROY)
      {
            return true;
      }
      else
      {
            return false;
      }
}

void window32::create_window(std::string title, HINSTANCE instance) // should I move this into create_window_handle??
{
      HWND 
      CreateWindowExA(
            DWORD     dwExStyle, // 0
            LPCSTR    lpClassName,
            LPCSTR    lpWindowName,
            DWORD     dwStyle,
            int       X,
            int       Y,
            int       nWidth,
            int       nHeight,
            HWND      hWndParent, // 0
            HMENU     hMenu, // 0
            HINSTANCE hInstance,
            LPVOID    lpParam // 0
      );
}
