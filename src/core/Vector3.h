#pragma once

class Transform;

class Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3(float X, float Y, float Z);
    Vector3(float X, float Y, float Z, Transform *Transform);

    void setX(float X);
    void setY(float Y);
    void setZ(float Z);
    void setXYZ(float val);
    void set(float X, float Y, float Z);

private:
    Transform *transform;
};