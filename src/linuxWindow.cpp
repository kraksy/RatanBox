
#include <iostream>
#include <X11/Xlib.h>
#include <logger.h>

/*
	code for window management on linux 
	its done in x11
	
	by krek; 
*/

static bool running;
static logger log;

#define internal static
#define local_persist static
#define global_variable static

global_variable Display *display;
global_variable Window window;
global_variable XEvent event;
global_variable GC gc;
global_variable KeySym key;
global_variable char text[255];

global_variable Bool running;

int main(void)
{
	
	display = XOpenDisplay("gah");

	if (display == NULL)
	{
		log.print(log.ERROR_LEVEL, "window failed to create");
		exit(1);
	}

	window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, 400, 300, 0, 0, WhitePixel(display, 0));
	XSelectInput(display, window, ExposureMask | KeyPressMask);
	gc = XCreateGC(display, window, 0, NULL);
	XSetForeground(display, gc, BlackPixel(display, 0));
	XMapWindow(display, window);

	if (running)
	{
		char tmp[512];
		scanf("%s",tmp);
		printf("%s",tmp);

		XNextEvent(display, &event);

		if (event.type == Expose) {
            XDrawString(display, window, gc, 10, 10, "Hello, X11!", 12);
        }

        if (event.type == KeyPress) {
            closeWindow();
        }
	}
	else 
	{
		closeWindow();
	}

}

void closeWindow()
{
	log.print(log.INFO_LEVEL, "window is closing");
	XFreeGC(display, gc);
	XDestroyWindow(display, window);
	XCloseDisplay(display);
	exit(1);
}