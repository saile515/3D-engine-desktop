#include "Vector3.h"

#include "../components/Transform.h"

Vector3::Vector3(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

Vector3::Vector3(float X, float Y, float Z, Transform *Transform)
{
    x = X;
    y = Y;
    z = Z;
    transform = Transform;
}

void Vector3::setX(float X)
{
    x = X;
    transform->updateMatrix();
}

void Vector3::setY(float Y)
{
    y = Y;
    transform->updateMatrix();
}

void Vector3::setZ(float Z)
{
    z = Z;
    transform->updateMatrix();
}

void Vector3::setXYZ(float val)
{
    x = val;
    y = val;
    z = val;
    transform->updateMatrix();
}

void Vector3::set(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
    transform->updateMatrix();
}