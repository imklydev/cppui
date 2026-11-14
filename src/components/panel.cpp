#include "panel.h"
#include "rendering/drawing.h"

PanelComponent::PanelComponent(Color color, std::vector<Component *> children) : VerticalContainerComponent(children), color(color)
{
}

void PanelComponent::draw(Vector2 pos)
{
    SetDrawColor(this->color);
    DrawRect(pos, this->size);

    VerticalContainerComponent::draw(pos);
}

PanelComponent *Panel(Color color, std::vector<Component *> children)
{
    return new PanelComponent(color, children);
}