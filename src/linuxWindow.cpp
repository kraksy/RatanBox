
#include <iostream>
#include <X11/Xlib.h>
#include <logger.h>

#include <sokol_gfx.h>
#include <sokol_app.h>
#include <sokol_glue.h>

#define SOKOL_IMPL or
#define SOKOL_GFX_IMPL

#define SOKOL_GLCORE33
#define SOKOL_GLES3
#define SOKOL_D3D11
#define SOKOL_METAL
#define SOKOL_WGPU
#define SOKOL_DUMMY_BACKEND

#define SOKOL_ASSERT(c)
#define SOKOL_UNREACHABLE()
#define SOKOL_API_IMPL              
#define SOKOL_TRACE_HOOKS           
#define SOKOL_EXTERNAL_GL_LOADER

/*                        
    #ratan
	ratan window implementation for linux 
	made with `x11` , and sokol header files  
	
	// add 3d api context // probably opengl

	by krek; // 2023 
*/

#define internal static
#define local_persist static
#define global_variable static

global_variable Display *display;
global_variable Window window;
global_variable XEvent event;
global_variable GC gc;
global_variable KeySym key;
global_variable logger log;
global_variable char text[255];

global_variable Bool running;


static int closeWindow()
{
	log.print(log.INFO_LEVEL, "window is closing");
	XFreeGC(display, gc);
	XDestroyWindow(display, window);
	XCloseDisplay(display);
	exit(1);
}

int main(void)
{
	display = XOpenDisplay("gah");

	sg_setup(&(sg_desc){
        .logger.func = slog_func,
    });


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