#pragma once

#include <string>
#include <vector>

#include <iostream>

class Component;

class Object
{
public:
    std::string uuid;
    std::vector<Component *> components;

    Object();

    void addComponent(Component *component);

    template <typename T>
    T *getComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
        for (int i = 0; i < components.size(); i++)
        {
            if (T *ptr = dynamic_cast<T *>(components[i]))
            {
                return ptr;
            }
            else
            {
                continue;
            }
        }

        return nullptr;
    };

    virtual void update();
};