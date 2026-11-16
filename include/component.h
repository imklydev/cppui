#pragma once

#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include "misc.h"
#include "log.h"
#include "window.h"

// Definitions for Component::resize()
#define NO_CHANGE -2
#define NO_CHANGE -2

// The base Component class
class Component;

class Component
{
protected:
    std::vector<Component *> cached_components;
    std::vector<std::function<void()>> queued_operations;

    Vector2 pos;
    Vector2 override_size = {-1, -1};

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

    virtual void draw(Vector2 pos)
    {
        if (override_size == Vector2{-1, -1})
        {
            return;
        }

        if (override_size.x != NO_CHANGE)
        {
            size.x = override_size.x;
        }

        if (override_size.y != NO_CHANGE)
        {
            size.y = override_size.y;
        }

        // Update values to account for window resizing if needed
        if (override_size.x == WINDOW_WIDTH)
        {
            size.x = Window.width;
        }

        if (override_size.y == WINDOW_HEIGHT)
        {
            size.y = Window.height;
        }
    };

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

    Component *resize(Vector2 new_size)
    {
        override_size = new_size;
        return this;
    }
};