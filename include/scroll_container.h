#pragma once

#include "component.h"

#include "vertical_container.h"

// A component that allows scrolling to move its children
class ScrollContainerComponent : public VerticalContainerComponent
{
private:
    float sensitivity = 10;
    float scroll = 0;

public:
    ScrollContainerComponent(std::vector<Component *> children);

    void update() override;
    void draw(Vector2 pos) override;
};

// Creates a ScrollContainer component
extern ScrollContainerComponent *ScrollContainer(std::vector<Component *> children);