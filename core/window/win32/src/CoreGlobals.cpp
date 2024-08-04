//
// Created by kraks on 29/07/2024.
//

#include "CoreGlobals.h"

CoreGlobals::Window CoreGlobals::initWindow(HINSTANCE instance, LPCTSTR className,  LPCTSTR title) {
    auto win = *new CoreGlobals::Window;

    HWND hwnd = CreateWindowEx(
            0,
            className,
            title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            NULL,
            NULL,
            instance,
            NULL
    );
    if (hwnd == NULL)
    {
        DWORD error = GetLastError();
        OutputDebugStringA("Failed to create window. Error code: ");
        char buffer[256];
        sprintf_s(buffer, "%lu", error);
        OutputDebugStringA(buffer);
        exit(-1);
    }
    else
    {
        win.window = hwnd;
        return win;
    }
}

void CoreGlobals::deleteWindow(CoreGlobals::Window *win) {
    delete(&win);
}

CoreGlobals::Vec2 CoreGlobals::GetWindowDimension(HWND Window) {
    CoreGlobals::Vec2 Result;
    RECT ClientRectangle;
    GetClientRect(Window, &ClientRectangle);
    Result.x = ClientRectangle.right - ClientRectangle.left;
    Result.y = ClientRectangle.bottom - ClientRectangle.top;

    return(Result);
}

void CoreGlobals::Win32ResizeDIBSection(CoreGlobals::win32_offscreen_buffer *Buffer, int Width, int Height) {
    if (Buffer->Memory) {
        VirtualFree(Buffer->Memory, 0, MEM_RELEASE);
        Buffer->Memory = 0;
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
    int bytesPerPixel = 4;
    Buffer->Pitch = Width * bytesPerPixel;

}

void CoreGlobals::Win32DisplayBufferInWindow(HDC DeviceContext, int WindowWidth, int WindowHeight,
                                             CoreGlobals::win32_offscreen_buffer Buffer, int X, int Y, int Width,
                                             int Height)
{
    StretchDIBits(DeviceContext,
                  X, Y, Buffer.Width, Buffer.Height,
                  0, 0, Buffer.Width, Buffer.Height,
                  Buffer.Memory,
                  &Buffer.Info,
                  DIB_RGB_COLORS, SRCCOPY);
}

bool CoreGlobals::WindowResize(HWND win, WPARAM wParam, LPARAM lParam) {
    int width = LOWORD(lParam);
    int height = HIWORD(lParam);


    return false;
}

