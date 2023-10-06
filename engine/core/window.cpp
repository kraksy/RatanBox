#include "core/window.h"

namespace engine
{
	void Window::close()
	{
		if (window != nullptr)
		{
			glfwWindowShouldClose(window);
		}
	}
















}
