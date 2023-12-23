#include <windows.h>
#include <iostream>

void test(void)
{
  std::cout << "test passed";
}

int CALLBACK WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
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
