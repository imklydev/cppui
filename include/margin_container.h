#pragma once

#include "component.h"

#include "vertical_container.h"

// A component that vertically arranges its children, with margin around the container
class MarginContainerComponent : public VerticalContainerComponent
{
private:
    int margin;

public:
    MarginContainerComponent(int margin, std::vector<Component *> children);

    void draw(Vector2 pos) override;
};

// Creates a MarginContainer component
extern MarginContainerComponent *MarginContainer(int margin, std::vector<Component *> children);