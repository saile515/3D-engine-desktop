#pragma once

#include <GL/glew.h>

#include "../objects/Camera.h"

class Scene
{
public:
    Camera *camera;
    void init();

    void update();

private:
    GLuint vertexbuffer;
    GLuint programID;
    void render();
};