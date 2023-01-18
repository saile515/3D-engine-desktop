#include "Engine.h"

#include <iostream>

#include <math.h>

Engine::Engine()
{
}

Engine &Engine::get()
{
    static Engine instance;
    return instance;
}

void Engine::init()
{
    window.init();
}

void Engine::update()
{
    // Calculate delta time and update perfBuffer
    std::chrono::steady_clock::time_point perf = std::chrono::steady_clock::now();

    deltaTime = ((perf - perfBuffer[59]) / 1000).count();

    for (int i = 1; i < 60; i++)
    {
        perfBuffer[i - 1] = perfBuffer[i];
    }

    perfBuffer[59] = perf;

    // Calculate FPS
    fps = floorf((perfBuffer[59] - perfBuffer[0]).count());

    scene.update();
}