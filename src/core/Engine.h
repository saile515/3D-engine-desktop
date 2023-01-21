#pragma once

#include <ctime>
#include "Window.h"
#include "Scene.h"

class Engine
{
public:
    Window *window;
    Scene *scene;
    double deltaTime;
    int fps;

    static Engine &get();
    void init();
    void update();

private:
    Engine();
    std::clock_t perfBuffer[60];
};