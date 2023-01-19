#define GLEW_STATIC
#include <GL/glew.h>

#include "Scene.h"

#include <iostream>

#include <GLFW/glfw3.h>

#include "Engine.h"

Scene::Scene()
{
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f,
        -1.0f,
        0.0f,
        1.0f,
        -1.0f,
        0.0f,
        0.0f,
        1.0f,
        0.0f,
    };

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void Scene::update()
{
    /* Poll for and process events */
    glfwPollEvents();

    // TODO: update objects here

    render();

    /* Swap front and back buffers */
    glfwSwapBuffers(Engine::get().window->getGLFWWindow());
}

void Scene::render()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // 1st attribute buffer : vertices
    // glEnableVertexAttribArray(0);
    // glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // glVertexAttribPointer(
    //     0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
    //     3,        // size
    //     GL_FLOAT, // type
    //     GL_FALSE, // normalized?
    //     0,        // stride
    //     (void *)0 // array buffer offset
    // );
    // // Draw the triangle !
    // glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    // glDisableVertexAttribArray(0);
}