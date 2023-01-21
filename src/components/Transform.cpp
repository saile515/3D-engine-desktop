#include "Transform.h"

#include <glm/vec3.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

Transform::Transform()
{
    updateMatrix();
}

void Transform::updateMatrix()
{
    matrix = glm::translate(matrix, glm::vec3(position.x, position.y, position.z));
    matrix = glm::scale(matrix, glm::vec3(scale.x, scale.y, scale.z));

    matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
}
