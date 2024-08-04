//
// Created by kraks on 04/08/2024.
//

#include <windows.h>
#include <winuser.h>

#include <CoreGlobals.h>

const char CLASSNAME[] = "project";
static CoreGlobals::Window win;

static MSG message = {};
static BOOL bRet;

static bool running;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wp, LPARAM lp);

void setupClass(HINSTANCE hInstance)
{
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = CLASSNAME;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc))
    {
        DWORD error = GetLastError();
        if (error == 0)
        {
            printf("Failed to register window class, but GetLastError returned 0. An unknown issue occurred.\n");
        }
        else
        {
            printf("Failed to register window class. Error code: %lu\n", error);
        }
    }
    else
    {
        printf("Window class registered successfully.\n");
    }
}

int WINAPI WinMain
        (
                HINSTANCE instance,
                HINSTANCE prevInstance,
                LPSTR cmd,
                int nShowCmd
                )
{
    setupClass(instance);
    win = CoreGlobals::initWindow(instance, CLASSNAME, "project");
    ShowWindow(win.window, nShowCmd);
    UpdateWindow(win.window);

    if(running)
    {
        while ((bRet = GetMessage(&message, NULL, 0, 0)) != 0)
        {
            if (bRet == -1)
            {
                break;
            }
            else
            {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }
        }
        if (message.wParam <= INT_MAX)
        {
            return static_cast<int>(message.wParam);
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

LRESULT CALLBACK WindowProc
        (
                HWND hwnd,
                UINT uMsg,
                WPARAM wParam,
                LPARAM lParam
        )
{
    LRESULT result = 0;
    switch(uMsg)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT paintStruct;
            HDC hdc = BeginPaint(hwnd, &paintStruct);
            ReleaseDC(hwnd, hdc);
            EndPaint(hwnd, &paintStruct);
            break;
        }
        case WM_SIZE:
        {
            OutputDebugStringA("WM_SIZE\n");
            break;
        }
        case WM_ACTIVATEAPP:
        {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
            break;
        }
        case WM_DESTROY:
        {
            running = false;
            OutputDebugStringA("WM_DESTROY\n");
            break;
        }
        case WM_CLOSE:
        {
            DestroyWindow(hwnd);
            running = false;
            OutputDebugStringA("WM_CLOSE\n");
            break;
        }
        default:
        {
            result = DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }

    return(result);
}