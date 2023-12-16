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
  MessageBoxA(0, "lmao" , "title" , MB_OK | MB_ICONINFORMATION);
  test();
  return(0);
}
