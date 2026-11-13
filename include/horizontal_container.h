#pragma once

#include "component.h"

// A component that arranges its children horizontally
class HorizontalContainerComponent : public Component
{
public:
    HorizontalContainerComponent(std::vector<Component *> children);

    // Draw, align, and order children
    void draw(Vector2 pos) override;
};

// Creates a HorizontalContainer component
extern HorizontalContainerComponent *HorizontalContainer(std::vector<Component *> children);