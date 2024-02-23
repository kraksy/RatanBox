
#include <iostream>
#include <windowx11.h>

/*
    this is the code for the game engine ratan box 
    and its only game for now , the game engine will use my own libs 
   
    by krek; // 2024
*/

static bool running = true;

int main()
{   
    windowx11 win;

    win.dis = XOpenDisplay(NULL);

    if(win.dis == NULL)
    {
        printf("cannot connect");
        exit(0);
    }

    win.root = DefaultRootWindow(win.win);

    if (win.vi == NULL)
    {
        printf("no visuals");
    }
    

    win.win = XCreateWindow(win.dis, win.root, 0, 0, 600, 600, 0, win.vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &win.swa);
}
