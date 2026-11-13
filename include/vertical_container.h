#pragma once

#include "component.h"

// A component that arranges its children vertically
class VerticalContainerComponent : public Component
{
public:
    VerticalContainerComponent(std::vector<Component *> children);

    // Draw, align, and order children
    void draw(Vector2 pos) override;
};

// Creates a VerticalContainer component
extern VerticalContainerComponent *VerticalContainer(std::vector<Component *> children);