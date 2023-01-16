#include <iostream>

#include <GLFW/glfw3.h>

#include "core/Engine.h"

int main(void)
{

    std::cout << "Hello";
    Engine engine = Engine::get();

    engine.init();

    /* Loop until the user closes the window */
    while (engine.window.shouldUpdate())
    {
        engine.update();

        std::cout << engine.fps << "\n";
    }

    engine.window.terminate();
    return 0;
}