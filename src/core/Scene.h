#pragma once

#include <GL/glew.h>

class Scene
{
public:
    void init();

    void update();

private:
    GLuint vertexbuffer;
    GLuint programID;
    void render();
};