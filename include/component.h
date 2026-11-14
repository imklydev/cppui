#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "misc.h"
#include "log.h"

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

    Component *GetChild(int idx)
    {
        if (idx >= 0 && idx < children.size())
        {
            return children[idx];
        }

        error("GetChild(int idx): idx out of bounds");
        return this;
    }
};