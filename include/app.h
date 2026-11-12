#pragma once

#include "component.h"

#include "theme.h"
#include "text.h"

// The App class, the parent of all of your components rendered to the screen
class App : public Component
{
public:
    std::vector<Component *> children;

    App(std::vector<Component *> children) : children(children) {}

    void draw(Vector2 pos) override
    {
        for (Component *child : children)
        {
            child->draw(pos);
        }
    };
};

extern App Application();