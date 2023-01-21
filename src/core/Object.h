#pragma once

#include <string>
#include <vector>

#include "Component.h"

class Object
{
public:
    std::string uuid;
    std::vector<Component *> components;

    void addComponent(Component *component);

    template <typename T>
    T getComponent();

    void update();

    Object();
};