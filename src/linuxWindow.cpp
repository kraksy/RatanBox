
#include <X11/Xlib.h>
#include <logger.h>

static bool running;
static logger log;

int main(void)
{
	log.log("linux window here");
	Display *display;
	Window window;
	XEvent event;

	display = XOpenDisplay(NULL);
	if (display == NULL)
	{
		log.log("failed to open display");
		exit(1);
	}

	return 0;
}
