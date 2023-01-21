#include "Camera.h"

#include "../components/Transform.h"

Camera::Camera()
{
    Transform *transform = getComponent<Transform>();

    transform->position.setZ(10);
}