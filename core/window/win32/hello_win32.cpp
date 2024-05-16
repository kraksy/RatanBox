
#include <windows.h>
#include <windowsx.h>

struct
{	int Width;
	int Heigh;
	WNDCLASS WindowClass;
	bool Running;
}Window;

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	LRESULT Result = 0;

	switch (uMsg)
	{
            case WM_DESTROY:
            {
                  Window.Running = false;
                  OutputDebugStringA("WM_DESTROY\n");
            } break;

            case WM_CLOSE:
            {
                  Window.Running = false;
                  OutputDebugStringA("WM_CLOSE\n");
            } break;

            case WM_ACTIVATEAPP:
            {
                  OutputDebugStringA("WM_ACTIVATEAPP\n");
            } break;

            case WM_PAINT:
            {
                  PAINTSTRUCT ps;
                  HDC hdc = BeginPaint(hwnd, &ps);

                  // All painting occurs here, between BeginPaint and EndPaint.

                  FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

                  EndPaint(hwnd, &ps);
            }break;

            default:
            {
                  // OutputDebugStringA("default\n");
                  Result = DefWindowProc(hwnd, uMsg, wParam, lParam);
            } break;
	}

	return(Result);
}

HWND InitWindow(HINSTANCE hInstance,LPCTSTR classname, LPCTSTR title)
{	HWND hwnd = CreateWindowExA(
		0,
		classname,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		0,
		0,
		hInstance,
		0
	);
	return hwnd;
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
{
	Window.Heigh = 1200;
	Window.Width = 1200;
	Window.WindowClass.style = CS_HREDRAW | CS_VREDRAW;
	//.lpfnWndProc = Win32MainWindowCallback;
	Window.WindowClass.hInstance = hInstance;
	// WindowClass.hIcon;
	Window.WindowClass.lpszClassName = "TestClass";
	
	HWND window = InitWindow(hInstance, Window.WindowClass.lpszClassName, "demo");
	if (window)
	{
		Window.Running = true;

		if (Window.Running) 
		{
			ShowWindow(window, nShowCmd);
			MSG msg = { };

			while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					Window.Running = false;
				}

				TranslateMessage(&msg);
				DispatchMessage(&msg);

				// rest of the loop is for drawing  and updating
			}
		}
	}
	else
	{
            OutputDebugStringA("Window creation failed\n");
            return(-1);
	}
	return(0);
}