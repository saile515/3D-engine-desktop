#pragma once

#include <chrono>
#include "Window.h"
#include "Scene.h"

class Engine
{
public:
    Window *window;
    Scene scene;
    float deltaTime;
    int fps;

    static Engine &get();
    void init();
    void update();

private:
    Engine();
    std::chrono::steady_clock::time_point perfBuffer[60];
};