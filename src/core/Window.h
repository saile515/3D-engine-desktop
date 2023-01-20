#pragma once

#include <GL/glew.h>

#include <GLFW/glfw3.h>

class Window
{
public:
    int width = 640;
    int height = 480;
    const char* title = "Engine";
    GLFWwindow* window;

    int init();

    bool shouldUpdate();

    void terminate();

    GLFWwindow* getGLFWWindow();

private:
    static void GLAPIENTRY MessageCallback(GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        const void* userParam);
};