#include "Window.h"

#include <iostream>

#include <GLFW/glfw3.h>

int Window::init()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW failed to initialize!\n";
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "GLFW failed to create window!\n";
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    std::cout << "Window initialized\n";

    glViewport(0, 0, width, height);

    return 0;
}

bool Window::shouldUpdate()
{
    return !glfwWindowShouldClose(window);
}

void Window::terminate()
{
    glfwTerminate();
}