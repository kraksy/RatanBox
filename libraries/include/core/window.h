#include <core/core.h>

namespace engine
{
	struct Window
	{
		GLFWwindow* window;
		int Width;
		int height;

		static Window* createWindow(int width, int height, const char* title, bool fullScreenMode = false);
		static void freeWindow(Window* window);
		void close();
	};
}
