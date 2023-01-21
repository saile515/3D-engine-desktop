#pragma once

class Object;

class Component
{
public:
    Object *parent;

    Component();

    virtual void update();
};