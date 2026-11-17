#pragma once

#include "component.h"

// A component that arranges its children to be centered
class CenteredHorizontalContainerComponent : public Component
{
public:
    CenteredHorizontalContainerComponent(std::vector<Component *> children);

    void draw(Vector2 pos) override;
};

// Creates a CenteredHorizontalContainer component
extern CenteredHorizontalContainerComponent *CenteredHorizontalContainer(std::vector<Component *> children);