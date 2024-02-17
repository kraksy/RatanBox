
#include <windows.h>
#include <iostream>

/*
    this is the code for the game engine ratan box 
    and its only game for now , the game engine will use my own libs 
   
    by krek; // 2024
*/

static bool running = true;

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
    

    while (running)
    {





        running = false;
    }
}

