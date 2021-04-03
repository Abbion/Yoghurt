#include <iostream>
#include "../logger/YogLogger.h"
#include "../window/YogWindow.h"

int main()
{

    yog::Logger::init();
    yog::Window test(800, 600);

    while (!test.isClosed())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        test.swapBuffers();
        glfwPollEvents();
    }

    yog::Logger::terminate();
    
	return 0;
}