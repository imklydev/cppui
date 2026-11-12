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
    

    virtual void update() {};
    virtual void draw(Vector2 pos)
    {
        for (Component *child : children)
        {
            child->draw(pos);
        }
    };
};