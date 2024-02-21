
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class windowx11
{
public:
    Display *dis;
    Window win;
    XEvent event;
    GC gc;
    int screen;

    KeySym key;
    char text[255]; // input shit

    struct windowx
    {
        Display* dis,
        Window par, // idk
        int x,
        int y,
        unsigned int width,
        unsigned int height,
        unsigned int border_width,
        unsigned long border,
        unsigned long background
    } windowx;

    windowx11();
    ~windowx11();

    void create_window();
    bool should_close();

    void set_fullscreen();
    void center_window();

    void test_draw();
    void close_window();
};

windowx11::windowx11()
{
}

windowx11::~windowx11()
{
}

void
windowx11::close_window()
{
    XFreeGC(dis, gc);
	XDestroyWindow(dis, win);
	XCloseDisplay(dis);
}

void
windowx11::create_window()
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
}