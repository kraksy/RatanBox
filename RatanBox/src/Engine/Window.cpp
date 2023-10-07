#include <core/core.h>
#include <core/Window.h>

namespace RatanBox
{

	// gonna rewrite
	void Window::createWindow







	void Window::createWindow(int width, int height, const char* title, bool fullScreenMode)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		Window* win = new Window();
		GLFWmonitor* primaryMonitor = fullScreenMode ? glfwGetPrimaryMonitor() : nullptr;
		win->window = glfwCreateWindow(width, height, title, primaryMonitor, nullptr);
		if (win->window == nullptr)
		{
			printf("Failed to create GLFW window\n");
			glfwTerminate();
			return nullptr;
		}
		glfwMakeContextCurrent(win->window);

		return res;

	}

	void Window::freeWindow(Window* window)
	{
		if (window)
		{
			glfwDestroyWindow(window->nativeWindow);
			delete window;
		}
	}

	void Window::close()
	{
		if (nativeWindow != nullptr)
		{
			glfwSetWindowShouldClose(nativeWindow, GLFW_TRUE);
		}
	}
}
