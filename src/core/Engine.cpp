#include "Engine.h"

#include <iostream>

#include <math.h>

#include "Window.h"
#include "Scene.h"

Engine::Engine()
{
    window = new Window();
    scene = new Scene();
}

Engine &Engine::get()
{
    static Engine instance;
    return instance;
}

void Engine::init()
{
    window->init();
}

void Engine::update()
{
    // Calculate delta time and update perfBuffer
    std::clock_t perf = std::clock();

    deltaTime = ((perf - perfBuffer[59]) / 1000);

    for (int i = 1; i < 60; i++)
    {
        perfBuffer[i - 1] = perfBuffer[i];
    }

    perfBuffer[59] = perf;

    // Calculate FPS
    fps = floorf(1000 / ((perfBuffer[59] - perfBuffer[0]) / 60));

    scene->update();
}