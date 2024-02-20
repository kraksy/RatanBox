/*
      for later https://github.com/vbsw/opengl-win32-example/blob/master/Main.cpp

      
      ; P *wink
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

      void create_context();
      void create_window(HINSTANCE instance);

      bool shouldClose();
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

void window32::create_context()
{     
      
}

void
test_draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(0, 1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2i(-1, -1);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2i(1, -1);
	glEnd();
	glFlush();
}

void
set_fullscreen(bool fullscreen)
{
	DWORD style = GetWindowLong(window.hndl, GWL_STYLE);
	if (fullscreen)
	{
		RECT rect;
		MONITORINFO mi = { sizeof(mi) };
		GetWindowRect(window.hndl, &rect);
		window.prevX = rect.left;
		window.prevY = rect.top;
		window.prevWidth = rect.right - rect.left;
		window.prevHeight = rect.bottom - rect.top;

		GetMonitorInfo(MonitorFromWindow(window.hndl, MONITOR_DEFAULTTOPRIMARY), &mi);
		SetWindowLong(window.hndl, GWL_STYLE, style & ~WS_OVERLAPPEDWINDOW);
		SetWindowPos(window.hndl, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top,
			mi.rcMonitor.right - mi.rcMonitor.left,
			mi.rcMonitor.bottom - mi.rcMonitor.top,
			SWP_NOOWNERZORDER | SWP_FRAMECHANGED | SWP_SHOWWINDOW);
	}
	else
	{
		MONITORINFO mi = { sizeof(mi) };
		UINT flags = SWP_NOZORDER | SWP_FRAMECHANGED | SWP_SHOWWINDOW;
		GetMonitorInfo(MonitorFromWindow(window.hndl, MONITOR_DEFAULTTOPRIMARY), &mi);
		SetWindowLong(window.hndl, GWL_STYLE, style | WS_OVERLAPPEDWINDOW);
		SetWindowPos(window.hndl, HWND_NOTOPMOST, window.prevX, window.prevY, window.prevWidth, window.prevHeight, flags);
	}
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

void window32::create_window(HINSTANCE instance) // should I move this into create_window_handle??
{
	if (err.code == ERR_NONE)
	{
		DWORD  style = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		RECT rect = { 0, 0, window.resX, window.resY };

		if (AdjustWindowRect(&rect, style, false))
		{
			/* compute window size including border */
			window.width = rect.right - rect.left;
			window.height = rect.bottom - rect.top;

			window.hndl = CreateWindowW(window.className, window.title, style, 0, 0, window.width, window.height, nullptr, nullptr, instance, nullptr);
			if (!window.hndl)
			{
				err.code = ERR_CRWIN;
				err.message = L"CreateWindowW failed: Can not create window.";
			}
		}
		else
		{
			err.code = ERR_CRWIN_AWR;
			err.message = L"AdjustWindowRect failed: Can not create window.";
		}
	}
}
