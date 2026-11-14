#pragma once

#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include "misc.h"
#include "log.h"

// The base Component class
class Component;

class Component
{
protected:
    std::vector<Component *> cached_components;
    std::vector<std::function<void()>> queued_operations;

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

        for (std::function<void()> &op : queued_operations)
        {
            op();
        }
        queued_operations.clear();
    };
    virtual void draw(Vector2 pos) {};

    void AddChild(Component *component)
    {
        queued_operations.push_back(
            [this, component]()
            {
                cached_components.push_back(component);
                children.push_back(cached_components[cached_components.size() - 1]);
            });
    }

    Component *GetChild(int idx)
    {
        if (idx >= 0 && idx < children.size())
        {
            return children[idx];
        }

        error("GetChild(int idx): idx out of bounds");
        return nullptr;
    }
};