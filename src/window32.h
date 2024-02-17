

#pragma once

#include <iostream>
#include <windows.h>

class window32
{
public:
      window32(/* args */);
      ~window32();
      void create_context();
      void create_window(HINSTANCE instance);
      void center_window();
      void set_fullscreen();
      void set_window_title();
      void set_window_size();
      void set_window_position();
      void resize_window();
      void close_window();
};

window32::window32(/* args */)
{
}

window32::~window32()
{
}

void window32::create_window(HINSTANCE instance)
{
      
}
