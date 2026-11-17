#pragma once

#include "component.h"

// A component that arranges its children to be centered
class CenteredContainerComponent : public Component
{
public:
    CenteredContainerComponent(std::vector<Component *> children);

    void draw(Vector2 pos) override;
};

// Creates a CenteredContainer component
extern CenteredContainerComponent *CenteredContainer(std::vector<Component *> children);