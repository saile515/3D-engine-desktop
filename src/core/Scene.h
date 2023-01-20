#pragma once

class Scene
{
public:
    void init();

    void update();

private:
    GLuint vertexbuffer;
    void render();
};