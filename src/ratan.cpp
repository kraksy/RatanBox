
#include <windows.h> // be warry of error cuz windows libs //MICROSOFT
#include <iostream>

#include <player.cpp>
#include <logger.h>

static logger log;
static bool Running;

LRESULT CALLBACK WndProc(
    HWND hWnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
      PAINTSTRUCT ps;
      HDC hdc;

      switch (message)
      {
      case WM_DESTROY:
      {
            running = false;
            PostQuitMessage(0);
            break;
      }
      case WM_SIZE:
            break;
      case WM_PAINT:
      {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            TextOut(hdc, 5, 5, "Hello, World!", 13);
            EndPaint(hWnd, &ps);
      }
      default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
      }
      return 0;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
      WNDCLASSEX wc;
      MSG msg;

      HWND hwnd = CreateWindowEx(
          0,
          "WindowClass",
          "Win32",
          WS_OVERLAPPEDWINDOW,
          CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
          NULL,
          NULL,
          hInstance,
          NULL);

      wc.cbSize = sizeof(WNDCLASSEX);
      wc.style = CS_HREDRAW | CS_VREDRAW;
      wc.lpfnWndProc = WndProc;
      wc.cbClsExtra = 0;
      wc.cbWndExtra = 0;
      wc.hInstance = hInstance;
      wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
      wc.hCursor = LoadCursor(NULL, IDC_ARROW);
      wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
      wc.lpszMenuName = NULL;
      wc.lpszClassName = "WindowClass";
      wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

      if (!RegisterClassEx(&wc))
      {
            log.log("Window Registration Failed!");
            if (hwnd)
            {
                  Running = true;
                  MSG msg = {};

                  while (GetMessage(&msg, NULL, 0, 0))
                  {
                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                  }

                  ShowWindow(hwnd, nCmdShow);
                  UpdateWindow(hwnd);
            }
            else
            {
                  log.log("Window Creation Failed!");
            }

            return 1;
      }

      while (GetMessage(&msg, NULL, 0, 0))
      {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
      }

      return (int)msg.wParam;
}