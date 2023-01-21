#pragma once

#include <glm/mat4x4.hpp>

#include "../core/Component.h"
#include "../core/Vector3.h"

class Transform : public Component
{
public:
    Vector3 position = Vector3(0, 0, 0, this);
    Vector3 rotation = Vector3(0, 0, 0, this);
    Vector3 scale = Vector3(1, 1, 1, this);
    glm::mat4 matrix = glm::mat4(1.0f);

    void updateMatrix();

    Transform();
};