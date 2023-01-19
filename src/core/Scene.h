#pragma once

class Scene
{
public:
    void update();
    Scene();

private:
    GLuint vertexbuffer;
    void render();
};