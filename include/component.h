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
    bool reupdate_size_to_fit_children = false;

public:
    std::vector<Component *> children;
    Vector2 size;

    Component(std::vector<Component *> children = {}) : children(children) {}

    virtual void update() {};
    virtual void draw(Vector2 pos)
    {
        // Draw, align, and order children
        Vector2 child_pos = pos;
        float max_child_width = 0;
        float max_child_height = 0;

        for (Component *child : children)
        {
            child->draw(child_pos);
            child_pos.y += child->size.y;

            if (child->size.y > max_child_height)
            {
                max_child_height = child->size.y;
            }

            if (child->size.x > max_child_width)
            {
                max_child_width = child->size.x;
            }
        }

        if (reupdate_size_to_fit_children)
        {
            size = child_pos - pos;

            size.x = std::max(size.x, max_child_width);
            size.y = std::max(size.y, max_child_height);
        }
    };
};