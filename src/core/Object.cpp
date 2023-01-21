#include "Object.h"

#include "Component.h"
#include "../components/Transform.h"

Object::Object()
{
    components.push_back(new Transform());
}

void Object::addComponent(Component *component)
{
    component->parent = this;
    components.push_back(component);
}

void Object::update() {}