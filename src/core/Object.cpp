#include "Object.h"

#include "../components/Transform.h"

Object::Object()
{
    components.push_back(new Transform());
}