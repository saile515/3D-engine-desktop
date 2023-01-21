#include "Mesh.h"

#include <GL/glew.h>
#include <glm/mat4x4.hpp>

#include "../core/Engine.h"
#include "../core/Scene.h"
#include "../objects/Camera.h"
#include "Shader.h"
#include "Transform.h"

Mesh::Mesh()
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
    glGenBuffers(1, &vertexBuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void Mesh::render()
{
    Shader *shader = parent->getComponent<Shader>();

    glUseProgram(shader->programInfo.program);

    glEnableVertexAttribArray(shader->programInfo.attributes.vertexPosition);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
        shader->programInfo.attributes.vertexPosition, // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                                             // size
        GL_FLOAT,                                      // type
        GL_FALSE,                                      // normalized?
        0,                                             // stride
        (void *)0                                      // array buffer offset
    );

    Camera *camera = Engine::get().scene->camera;
    glm::mat4 modelMatrix = parent->getComponent<Transform>()->matrix;

    glm::mat4 MVPMatrix = camera->projectionMatrix * camera->viewMatrix * modelMatrix;

    glUniformMatrix4fv(shader->programInfo.uniforms.MVPMatrix, 1, GL_FALSE, &MVPMatrix[0][0]);

    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}