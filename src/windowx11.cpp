
#include "window32.h"

void
windowx11::DrawAQuad() {
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-1., 1., -1., 1., 1., 20.);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);

 glBegin(GL_QUADS);
  glColor3f(1., 0., 0.); glVertex3f(-.75, -.75, 0.);
  glColor3f(0., 1., 0.); glVertex3f( .75, -.75, 0.);
  glColor3f(0., 0., 1.); glVertex3f( .75,  .75, 0.);
  glColor3f(1., 1., 0.); glVertex3f(-.75,  .75, 0.);
 glEnd();
} 

void 
windowx11::test_draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(  1.0f,  0.0f, 0.0f);
		glVertex3f( 0.0f, -1.0f, 0.0f);
		glColor3f(  0.0f,  1.0f, 0.0f);
		glVertex3f(-1.0f,  1.0f, 0.0f);
		glColor3f(  0.0f,  0.0f, 1.0f);
		glVertex3f( 1.0f,  1.0f, 0.0f);
	glEnd();
}

void 
windowx11::resize_GL(int w, int h)
{
	glViewport(0, 0, w, h);
}

bool 
windiwx11::should_close()
{
	if (!running)
	{
		return true;
	}
	else
	{
		return false;
	}
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

void
windowx11::get_colours()
{
    XColor tmp;

	XParseColor(dis, DefaultColormap(dis,screen), "chartreuse", &tmp);
	XAllocColor(dis,DefaultColormap(dis,screen),&tmp);
	chartreuse=tmp.pixel;
}

void 
windowx11::create_colormap()
{
    int i;
	Colormap cmap;
	XColor tmp[255];

	for(i=0;i<255;i++) {
		tmp[i].pixel=i;
		tmp[i].flags=DoRed|DoGreen|DoBlue;
		tmp[i].red=i*256;
		tmp[i].blue=i*256;
		tmp[i].green=i*256;
	}	
	cmap=XCreateColormap(dis,RootWindow(dis,screen),
		DefaultVisual(dis,screen),AllocAll);
	XStoreColors(dis, cmap, tmp,255);
	XSetWindowColormap(dis,win,cmap);
}