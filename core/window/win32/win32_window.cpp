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

// stoped at ep 5

#define internal static
#define local_persist static
#define global_variable static

struct win32_offscreen_buffer
{
  BITMAPINFO Info;
  void *Memory;
  int Width;
  int Height;
  int Pitch;
  int BytesPerPixel;
};

global_variable bool Running;
global_variable win32_offscreen_buffer GlobalBackBuffer;

global_variable BITMAPINFO BitmapInfo;
global_variable void *BitmapMemory;
global_variable int BitmapWidth;
global_variable int BitmapHeight;
global_variable int BytesPerPixel = 4;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

struct win32_window_dimension
{
  int Width;
  int Height;
};

win32_window_dimension
GetWindowDimension(HWND Window)
{
  win32_window_dimension Result;

  RECT ClientRectangle;
  GetClientRect(Window, &ClientRectangle);
  Result.Width = ClientRectangle.right - ClientRectangle.left;
  Result.Height = ClientRectangle.bottom - ClientRectangle.top;

  return(Result);
}

internal void
Render(win32_offscreen_buffer Buffer, int XOffset, int YOffset)
{
  uint8 *Row = (uint8 *)Buffer.Memory;
  for (int Y = 0; Y < Buffer.Height; ++Y)
  {
    uint32 *Pixel = (uint32 *)Row;
    for (int X = 0; X < Buffer.Width; ++X)
    {
      uint8 Blue = (X + XOffset);
      uint8 Green = (Y + YOffset);
      *Pixel++ = ((Green << 8) | Blue);
    }
    Row += Buffer.Pitch;
  }
}

internal void
Win32ResizeDIBSection(win32_offscreen_buffer *Buffer, int Width, int Height)
{

  if (Buffer->Memory)
  {
    VirtualFree(Buffer->Memory, 0, MEM_RELEASE);
  }

  Buffer->Width = Width;
  Buffer->Height = Height;

  Buffer->Info.bmiHeader.biSize = sizeof(Buffer->Info.bmiHeader);
  Buffer->Info.bmiHeader.biWidth = Buffer->Width;
  Buffer->Info.bmiHeader.biHeight = -Buffer->Height;
  Buffer->Info.bmiHeader.biPlanes = 1;
  Buffer->Info.bmiHeader.biBitCount = 32;
  Buffer->Info.bmiHeader.biCompression = BI_RGB;

  int BitmapMemorySize = Buffer->Width * Buffer->Height * Buffer->BytesPerPixel;
  Buffer->Memory = VirtualAlloc(0, BitmapMemorySize, MEM_COMMIT, PAGE_READWRITE);
  Buffer->Pitch = Width * BytesPerPixel;
  
}

internal void
Win32DisplayBufferInWindow(HDC DeviceContext, 
                          int WindowWidth, int WindowHeight,
                          win32_offscreen_buffer Buffer,
                          int X, int Y, int Width, int Height)
{

  StretchDIBits(DeviceContext,
    /*
    X, Y, Width, Height, 
    X, Y, Width, Height, 
    */
    0, 0, Buffer.Width, Buffer.Height,
    0, 0, WindowWidth, WindowHeight,
    Buffer.Memory,
    &Buffer.Info,
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
      win32_window_dimension Dimension = GetWindowDimension(window);
	    Win32ResizeDIBSection(&GlobalBackBuffer, Dimension.Width , Dimension.Height);
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

   win32_window_dimension Dimension = GetWindowDimension(window);

   Win32DisplayBufferInWindow(DeviceContex, Window.Window, Window.Height,
                    GlobalBackBuffer,
                    X, Y, Width, Height);
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

  WindowClass.style = CS_HREDRAW|CS_VREDRAW;
  WindowClass.lpfnWndProc = Win32MainWindowCallback;
  WindowClass.hInstance = hInstance;
  // WindowClass.hIcon;
  WindowClass.lpszClassName = "TestClass";

  if (RegisterClass(&WindowClass))
  {
    HWND Window = 
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
      if (Window)
      {
        int XOffset = 0;
        int YOffset = 0;

        Running = true;
        while(Running)
        {
          MSG Message;
          while(PeekMessage(&Message,0,0,0,PM_REMOVE))
          {
            if (Message.message == WM_QUIT)
            {
              Running = false;
            }

            TranslateMessage(&Message);
            DispatchMessage(&Message);
          }
          
          Render(GlobalBackBuffer, XOffset, YOffset);
          HDC DeviceContext = GetDC(Window);
          
          Win32DisplayBufferInWindow(DeviceContext, ClientRectangle, GlobalBackBuffer
           0, 0, WindowWidth, WindowHeight);
          ReleaseDC(Window, DeviceContext);
          ++XOffset;
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
