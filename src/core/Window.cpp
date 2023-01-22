#include <GL/glew.h>

#include "Window.h"
#include <iostream>
#include <stdio.h>

#include <GLFW/glfw3.h>

#include "Engine.h"

void GLAPIENTRY Window::MessageCallback(GLenum source,
                                        GLenum type,
                                        GLuint id,
                                        GLenum severity,
                                        GLsizei length,
                                        const GLchar *message,
                                        const void *userParam)
{
    std::fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
                 (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
                 type, severity, message);
}

int Window::init()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW failed to initialize!\n";
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    glfwSwapInterval(0);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout << "GLEW failed to initialize!\n";
        terminate();
        return -1;
    }

    std::cout << "Window initialized\n";

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

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