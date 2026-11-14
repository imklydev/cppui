#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "misc.h"

// The base Component class
class Component;

class Component
{
protected:
    Vector2 pos;

public:
    std::vector<Component *> children;
    Vector2 size;

    Component(std::vector<Component *> children = {}) : children(children) {}

    virtual void update()
    {
        for (Component *child : children)
        {
            child->update();
        }
    };
    virtual void draw(Vector2 pos) {};

    void AddChild(Component *component)
    {
        children.push_back(component);
    }
};