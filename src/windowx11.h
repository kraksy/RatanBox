
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

/*
    https://github.com/gamedevtech/X11OpenGLWindow/blob/master/X11.cpp#L272
    https://www.khronos.org/opengl/wiki/Programming_OpenGL_in_Linux:_GLX_and_Xlib
*/

class windowx11
{
public:
    bool running;

    Display *dis;
    Window win; 
    Window root;

    XVisualInfo             *vi;
    Colormap                cmap;
    XSetWindowAttributes    swa;
    GLXContext              glc;
    XWindowAttributes       gwa;
    XEvent event;
    GC gc;
    int screen;

    KeySym key;
    char text[255]; // input shit

    windowx11();
    ~windowx11();

    void create_window(); // v 
    bool should_close(); // v

    void set_fullscreen(); 
    void center_window();

    void DrawAQuad();
    void test_draw(); // v
    void draw_text();

    void redraw_window();

    void close_window(); // v
    void resize_GL(int w, int h); 

    void read_inputs();

    void get_colours(); // v
    void create_colormap(); // v
};

windowx11::windowx11()
{
}

windowx11::~windowx11()
{
}
