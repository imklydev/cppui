#pragma once

#include "component.h"

#include "text.h"
#include "panel.h"
#include "vertical_container.h"
#include "horizontal_container.h"

#include "theme.h"
#include "log.h"
#include "misc.h"

// The App class, the parent of all of your components rendered to the screen
class App : public VerticalContainerComponent
{
public:
    App(std::vector<Component *> children) : VerticalContainerComponent(children) {}

    void draw(Vector2 pos) override
    {
        VerticalContainerComponent::draw(pos);
    };
};

extern App Application();