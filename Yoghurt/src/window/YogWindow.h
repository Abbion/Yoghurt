#ifndef _YOG_WINDOW_H_
#define _YOG_WINDOW_H_
#include "GLFW/glfw3.h"

namespace yog {
	class Window
	{
	public:
		Window(int width, int height);
		~Window();

		bool isClosed();
		void swapBuffers();
	private:
		GLFWwindow* m_window = nullptr;
	};

}


#endif // !_YOG_WINDOW_H_
