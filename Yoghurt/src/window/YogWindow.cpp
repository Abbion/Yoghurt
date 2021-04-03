#include "YogWindow.h"
#include "..\logger\YogLogger.h"

namespace yog {
	Window::Window(int width, int height)
	{
		if (!glfwInit())
		{
			LOG_CF << "Error while Initialize GLFW";
			return;
		}

		m_window = glfwCreateWindow(width, height, "Test", NULL, NULL);

		if (!m_window)
		{
			LOG_CF << "Error while creating window";
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_window);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::isClosed()
	{
		return glfwWindowShouldClose(m_window);
	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(m_window);
	}
}