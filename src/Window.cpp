#include <windows.h>
#include <iostream>

// update: 2021-07-07

#define internal static
#define local_persist static
#define global_variable static

static bool Running;

internal void
Win32ResizeDIBSection(int Width, int Height)
  {
  HBITMAP CreateDIBSection(
  HDC              hdc,
  const BITMAPINFO *pbmi,
  UINT             usage,
  VOID             **ppvBits,
  HANDLE           hSection,
  DWORD            offset
  );

}

internal void
Win32UpdateWindow(HDC DeviceContext, RECT *WindowRect, int X, int Y, int Width, int Height)
{
  StretchDIBits(
  HDC              hdc,
  int              xDest,
  int              yDest,
  int              DestWidth,
  int              DestHeight,
  int              xSrc,
  int              ySrc,
  int              SrcWidth,
  int              SrcHeight,
  const VOID       *lpBits,
  const BITMAPINFO *lpbmi,
  UINT             iUsage,
  DWORD            rop
  );
}

LRESULT CALLBACK MainWindowCallback(
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
    HDC DeviceContex = BeginPaint(
      window, &Paint
    );
    int X = Paint.rcPaint.left;
    int Y = Paint.rcPaint.top;
    int Height = Paint.rcPaint.bottom - Paint.rcPaint.top; 
    int Width = Paint.rcPaint.right - Paint.rcPaint.left; 
    static DWORD Operation = WHITENESS;
    PatBlt(DeviceContex, X, Y, Width, Height ,Operation);
    if(Operation = WHITENESS)
    {
      Operation = BLACKNESS;
    }
    else
    {
      Operation = WHITENESS;
    }
    EndPaint(
      window, &Paint
    );
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
  WindowClass.lpfnWndProc = MainWindowCallback;
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
