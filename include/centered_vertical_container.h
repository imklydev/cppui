#pragma once

#include "component.h"

// A component that arranges its children to be centered
class CenteredVerticalContainerComponent : public Component
{
public:
    CenteredVerticalContainerComponent(std::vector<Component *> children);

    void draw(Vector2 pos) override;
};

// Creates a MarginContainer component
extern CenteredVerticalContainerComponent *CenteredVerticalContainer(std::vector<Component *> children);