#include <core/core.h>

namespace RatanBox
{
	struct Window
	{
		GLFWwindow* window;
		int CurrentWidth;
		int Currentheight;
		bool fullscreen;

		static Window* createWindow(int CurrentWidth, int Currentheight,const char* title, bool fullscreen);
		static void freeWindow(Window* window);
		void close();

	};

}
