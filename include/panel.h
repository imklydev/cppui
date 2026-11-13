#pragma once

#include "component.h"

// A component that has a background
class PanelComponent : public Component
{
private:
    Color color;

public:
    PanelComponent(Color color, std::vector<Component *> children);

    void draw(Vector2 pos) override;
};

// Creates a Panel component
extern PanelComponent *Panel(Color color, std::vector<Component *> children);