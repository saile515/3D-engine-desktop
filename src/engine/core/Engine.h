#pragma once

#include <chrono>
#include <math.h>

#include "Scene.h"
#include "../input/InputHandler.h"

class Engine
{
public:
    Scene scene;
    InputHandler inputHandler;
    float deltaTime;
    float fps;

    void update()
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
    }

private:
    std::chrono::steady_clock::time_point perfBuffer[60];
};