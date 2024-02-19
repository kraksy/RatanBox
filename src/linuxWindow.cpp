
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xtos.h>
#include <fmt/core.h>

/*                        
    #ratan

	by krek; // 2023 
*/

#define internal static
#define local_persist static
#define global_variable static

global_variable Display *dis;
global_variable Window win;
global_variable XEvent event;
global_variable GC gc;
global_variable int screen;

global_variable KeySym key;
global_variable char text[255];


global_variable Bool running;

int closeWindow()
{
	XFreeGC(dis, gc);
	XDestroyWindow(dis, win);
	XCloseDisplay(dis);
	exit(1);
}

int initWindow()
{
	unsigned long black,white;
	dis=XOpenDisplay((char *)0);
   	screen=DefaultScreen(dis);
	black=BlackPixel(dis,screen),	
	white=WhitePixel(dis, screen);  
   	win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,	
		200, 300, 5, white, black);

	XSetStandardProperties(dis,win,"My Window","HI!",None,NULL,0,NULL);

	XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);

	gc=XCreateGC(dis, win, 0,0);        

	XSetBackground(dis,gc,white);
	XSetForeground(dis,gc,black);

	XClearWindow(dis, win);
	XMapRaised(dis, win);
	return 1;
}

int main(void)
{

}