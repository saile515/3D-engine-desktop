#include "Engine.h"

#include <iostream>
#include <chrono>

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
    scene->init();
}

void Engine::update()
{
    // Calculate delta time and update perfBuffer
    std::chrono::high_resolution_clock::time_point perf = std::chrono::high_resolution_clock::now();

    deltaTime = float(std::chrono::duration_cast<std::chrono::microseconds>(perf - perfBuffer[59]).count()) / 1000000;

    for (int i = 1; i < 60; i++)
    {
        perfBuffer[i - 1] = perfBuffer[i];
    }

    perfBuffer[59] = perf;

    // Calculate FPS
    fps = int(1000000 / (float(std::chrono::duration_cast<std::chrono::microseconds>(perfBuffer[59] - perfBuffer[0]).count()) / 60));

    scene->update();
}