/*
      for later https://github.com/vbsw/opengl-win32-example/blob/master/Main.cpp

      ; P *wink


	  implement direct 2d lateer
*/

#pragma once

#include <iostream>
#include <windows.h>
#include <gl/GL.h>

#define ERR_NONE 0
#define ERR_REGCLS 1
#define ERR_CRWIN_AWR 2
#define ERR_CRWIN 3
#define ERR_DC 4
#define ERR_CPF 5
#define ERR_SPF 6
#define ERR_RC 7

class window32
{
public:
      
      window32();
      ~window32();
      struct window
      {
            HINSTANCE instance;
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
      } window;

	struct {
	LPCWSTR className;
	LPCSTR classNameChar;
	LPCWSTR title;
	HWND hndl;
	HDC deviceContext;
	HGLRC renderContext;
	int prevX, prevY, width, height, prevWidth, prevHeight, resX, resY;
	bool fullscreen;
} window = { L"OpenGL", "OpenGL", L"OpenGL Example", nullptr, nullptr, nullptr, 0, 0, 0, 0, 0, 0, 640, 480, false };


	struct {
	int code;
	LPCWSTR message;
	} err = { ERR_NONE, nullptr };

      void create_context();
      void create_window(HINSTANCE instance);

      bool shouldClose(UINT message);
      void ResizeWindow(RECT *WindowRect, int X, int Y, int Width, int Height);
      void ResizeWindow(RECT *WindowRect);
      void ResizeWindow(int X, int Y, int Width, int Height);

      void center_window(HDC DeviceContext);
      
      void set_fullscreen(HDC DeviceContext);

      void test_draw();
      
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

