#pragma once

#include <functional>

#include "component.h"

#include "panel.h"

// A component that can detect if it has been clicked.
class ButtonComponent : public PanelComponent
{
private:
    std::function<void()> on_click;

public:
    ButtonComponent(std::function<void()> on_click, Color color, std::vector<Component *> children);

    void update() override;
    void draw(Vector2 pos) override;
};

// Creates a Button component
extern ButtonComponent *Button(std::function<void()> on_click, Color color, std::vector<Component *> children);