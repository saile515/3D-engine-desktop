#pragma once

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../core/Object.h"
#include "../components/Transform.h"

class Camera : public Object
{
public:
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);
    glm::mat4 viewMatrix;

    Camera();

    void update();
};