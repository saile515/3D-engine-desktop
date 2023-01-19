#include "Scene.h"

#include <iostream>

#include <GLFW/glfw3.h>

#include "Engine.h"

void Scene::update()
{
    /* Poll for and process events */
    glfwPollEvents();

    // TODO: update objects here

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    render();

    /* Swap front and back buffers */
    glfwSwapBuffers(Engine::get().window->getGLFWWindow());
}

void Scene::render()
{
}