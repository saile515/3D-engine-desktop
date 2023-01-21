#pragma once

#include <vector>

#include <GL/glew.h>

#include "Object.h"
#include "../objects/Camera.h"

class Scene
{
public:
    Camera *camera;
    std::vector<Object *> children;

    void init();

    void update();

    void add(Object *object);

private:
    void render();
};