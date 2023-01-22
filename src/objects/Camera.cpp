#include "Camera.h"

#include "../components/Transform.h"

Camera::Camera()
{
    Transform *transform = getComponent<Transform>();

    transform->position.setZ(10);
}

void Camera::update()
{
    viewMatrix = glm::inverse(getComponent<Transform>()->matrix);
}