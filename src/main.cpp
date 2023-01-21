#include <iostream>

#include "core/Engine.h"

#include "core/Object.h"
#include "components/Mesh.h"
#include "components/Shader.h"

int main(void)
{
    Engine engine = Engine::get();
    engine.init();

    Object obj;

    Mesh mesh;
    obj.addComponent(&mesh);

    Shader shader = Shader("../../../assets/shaders/vertex.glsl", "../../../assets/shaders/fragment.glsl");
    obj.addComponent(&shader);

    engine.scene->add(&obj);

    /* Loop until the user closes the window */
    while (engine.window->shouldUpdate())
    {
        engine.update();

        std::cout << engine.fps << "\n";
    }

    engine.window->terminate();
    return 0;
}