//
// Created by kraks on 30/07/2024.
//

#include "CoreRender.h"

void CoreRender::Render(CoreGlobals::win32_offscreen_buffer *buffer, int XOffset, int YOffset) {
    auto *Row = (CoreGlobals::uint8 *)buffer->Memory;
    for (int Y = 0; Y < buffer->Height; ++Y)
    {
        auto *Pixel = (CoreGlobals::uint32 *)Row;
        for (int X = 0; X < buffer->Width; ++X)
        {
            CoreGlobals::uint8 Blue = (X + XOffset);
            CoreGlobals::uint8 Green = (Y + YOffset);
            *Pixel++ = ((Green << 8) | Blue);
        }
        Row += buffer->Pitch;
    }
}
