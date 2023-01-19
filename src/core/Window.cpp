#define GLEW_STATIC
#include <GL/glew.h>

#include "Window.h"
#include <iostream>

#include <GLFW/glfw3.h>

#include "Engine.h"

Window::Window()
{
}

int Window::init()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW failed to initialize!\n";
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        std::cout << "GLFW failed to create window!\n";
        terminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout << "GLEW failed to initialize!\n";
        terminate();
        return -1;
    }

    std::cout << "Window initialized\n";

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

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

GLFWwindow *Window::getGLFWWindow()
{
    return window;
}