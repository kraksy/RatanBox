#include <windows.h>
#include <iostream>
#include <vec1.h>

LRESULT CALLBACK MainWindowCallback(
  HWND window,
  UINT message,
  WPARAM WParam,
  LPARAM LParam
)
{
  switch (Message)
  {
    // if done this way , vars gonna be exclusive in the code blocks
   case WM_SIZE:
   {
   } break; 

   case WM_DESTROY:
   {
   } break;

   case WM_CLOSE:
   {
   } break;

   case WM_ACTIVATEAPP:
   {
   } break;

   default:
   { 
   } break;
  }
}

void test(void)
{
  std::cout << "test passed";
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
    WindowClass.lpfnWndProc = ;
    WindowClass.hInstance = hInstance;
    // WindowClass.hIcon;
    WindowClass.lpszClassName = L"TestClass";

  MessageBoxA(0, "lmao" , "title" , MB_OK | MB_ICONINFORMATION);
  test();
  return(0);
}