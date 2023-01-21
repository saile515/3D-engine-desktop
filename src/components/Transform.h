#pragma once

#include <glm/mat4x4.hpp>

#include "../core/Component.h"
#include "../core/Vector3.h"

class Transform : public Component
{
public:
    Vector3 position = Vector3(0, 0, 0);
    Vector3 rotation = Vector3(0, 0, 0);
    Vector3 scale = Vector3(1, 1, 1);
    glm::mat4 matrix;

    Transform();

private:
    void updateMatrix();
};