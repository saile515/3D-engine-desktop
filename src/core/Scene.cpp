#include "Scene.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Engine.h"
#include "Window.h"
#include "Object.h"
#include "../objects/Camera.h"
#include "../components/Mesh.h"
#include "../utils/loadShader.h"

void Scene::init()
{
    camera = new Camera();
    add(camera);
}

void Scene::update()
{
    /* Poll for and process events */
    glfwPollEvents();

    for (int i = 0; i < children.size(); i++)
    {
        children[i]->update();
    }

    render();

    /* Swap front and back buffers */
    glfwSwapBuffers(Engine::get().window->getGLFWWindow());
}

void Scene::render()
{
    glClearColor(0.49020f, 0.82745f, 0.98824f, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < children.size(); i++)
    {
        Mesh *mesh = children[i]->getComponent<Mesh>();

        if (mesh)
        {
            mesh->render();
        }
    }
}

void Scene::add(Object *object)
{
    children.push_back(object);
}