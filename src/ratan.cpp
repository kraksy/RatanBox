
#include <iostream>
#include <player.cpp>
#include <logger.h>
#include <SDL2/SDL.h> 

static logger log;

/*
      this code is for game im working on

      all code written here is marked as what the game will be 

      author: Krek 
*/

static bool Running;

int innit()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        log.print(log.ERROR_LEVEL, std::string(SDL_GetError()));
        return 1;
    }
    return 0;
}