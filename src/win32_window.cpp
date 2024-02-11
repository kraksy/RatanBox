#include <windows.h>
#include <iostream>
#include <stdint.h>

/*
  this code is just a training code to understand how to create a window in windows
  and how to draw on the window
  the code is not complete and is not meant to be used in any project
  it is just a training code

  handmadehero.org is the source of the code
*/

// stoped at 36:03 ep 4

#define internal static
#define local_persist static
#define global_variable static

global_variable bool Running;

global_variable BITMAPINFO BitmapInfo;
global_variable void *BitmapMemory;
global_variable int BitmapWidth;
global_variable int BitmapHeight;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

internal void
Win32ResizeDIBSection(int Width, int Height)
{

  if (BitmapMemory)
  {
    VirtualFree(BitmapMemory, 0, MEM_RELEASE);
  }

  BitmapWidth = Width;
  BitmapHeight = Height;

  BitmapInfo.bmiHeader.biSize = sizeof(BitmapInfo.bmiHeader);
  BitmapInfo.bmiHeader.biWidth = BitmapWidth;
  BitmapInfo.bmiHeader.biHeight = -BitmapHeight;
  BitmapInfo.bmiHeader.biPlanes = 1;
  BitmapInfo.bmiHeader.biBitCount = 32;
  BitmapInfo.bmiHeader.biCompression = BI_RGB;

  int BytesPerPixel = 4;
  int BitmapMemorySize = BitmapWidth * BitmapHeight * BytesPerPixel;
  BitmapMemory = VirtualAlloc(0, BitmapMemorySize, MEM_COMMIT, PAGE_READWRITE);

  int pitch = Width * BytesPerPixel;
  uint8 *Row = (uint8 *)BitmapMemory;
  for (int Y = 0; Y < BitmapHeight; ++Y)
  {
    uint8 *Pixel = (uint8 *)Row;
    for (int X = 0; X < BitmapWidth; ++X)
    {
      *Pixel = 0;
      ++Pixel;

      *Pixel = 0;
      ++Pixel;

      *Pixel = 255;
      ++Pixel;

      *Pixel = 0;
      ++Pixel;
    }
    Row += pitch;
  }

}

internal void
Win32UpdateWindow(HDC DeviceContext, RECT *WindowRect, int X, int Y, int Width, int Height)
{
  int WindowWidth = WindowRect->right - WindowRect->left;
  int WindowHeight = WindowRect->bottom - WindowRect->top;
  StretchDIBits(DeviceContext,
    /*
    X, Y, Width, Height, 
    X, Y, Width, Height, 
    */
    0, 0, BitmapWidth, BitmapHeight,
    0, 0, WindowWidth, WindowHeight,
    BitmapMemory,
    &BitmapInfo,
    DIB_RGB_COLORS, SRCCOPY);
}

LRESULT CALLBACK Win32MainWindowCallback(
  HWND window,
  UINT message,
  WPARAM WParam,
  LPARAM LParam
)
{
  LRESULT Result = 0;

  switch (message)
  {
    // if done this way , vars gonna be exclusive in the code blocks
   case WM_SIZE:
   {
	    RECT ClientRectangle;
	    GetClientRect(window, &ClientRectangle);
	    int Height = ClientRectangle.bottom - ClientRectangle.top; 
    	int Width = ClientRectangle.right - ClientRectangle.left; 
	    Win32ResizeDIBSection(Width, Height);
   } break; 

   case WM_DESTROY:
   {
    Running = false;
    OutputDebugStringA("WM_DESTROY\n");
   } break;

   case WM_CLOSE:
   {
    Running = false;
    OutputDebugStringA("WM_CLOSE\n");
   } break;

   case WM_ACTIVATEAPP:
   {
    OutputDebugStringA("WM_ACTIVATEAPP\n");
   } break;

  case WM_PAINT:
  {
   PAINTSTRUCT Paint;
   HDC DeviceContex = BeginPaint(window, &Paint);
   int X = Paint.rcPaint.left;
   int Y = Paint.rcPaint.top;
   int Height = Paint.rcPaint.bottom - Paint.rcPaint.top; 
   int Width = Paint.rcPaint.right - Paint.rcPaint.left; 

    RECT ClientRectangle;
    GetClientRect(window, &ClientRectangle);

   Win32UpdateWindow(DeviceContex, &ClientRectangle, X, Y, Width, Height);
   EndPaint(window, &Paint);
  }break;

   default:
   { 
    // OutputDebugStringA("default\n");
    Result = DefWindowProc(window, message, WParam, LParam);
   } break;
  }

  return(Result);
}

int CALLBACK WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     commandLine,
  int       showCode
)
{
  
  WNDCLASS WindowClass = {};     
  WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
  WindowClass.lpfnWndProc = Win32MainWindowCallback;
  WindowClass.hInstance = hInstance;
  // WindowClass.hIcon;
  WindowClass.lpszClassName = "TestClass";

  if (RegisterClass(&WindowClass))
  {
    HWND WindowHandle = 
      CreateWindowExA
      (
        0,
        WindowClass.lpszClassName,
        "test",
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0,
        0,
        hInstance,
        0
      );
      if (WindowHandle)
      {
        Running = true;
        while(Running)
        {
          MSG Message;
          BOOL MessageResult = GetMessage(&Message,0,0,0);
          if (MessageResult > 0)
          {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
          }
          else
          {
            break;
          }
        }
      }
      else
      {
      }
  }
  else
  {
  }

  return(0);
}
