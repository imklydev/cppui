#pragma once

#include <vector>
#include <string>
#include "misc.h"

// The base Component class
class Component;

class Component
{
public:
    std::vector<Component *> children;
    Vector2 size;

    Component(std::vector<Component *> children = {}) : children(children) {}

    virtual void update() {};
    virtual void draw(Vector2 pos)
    {
        // Draw, align, and order children
        Vector2 child_pos = pos;

        for (Component *child : children)
        {
            child->draw(child_pos);
            child_pos.y += child->size.y;
        }
    };
};