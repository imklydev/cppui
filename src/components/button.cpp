#include "button.h"
#include "event_handling/mouse.h"
#include "rendering/drawing.h"

ButtonComponent::ButtonComponent(std::function<void()> on_click, Color color, std::vector<Component *> children) : PanelComponent(color, children), on_click(on_click) {}

void ButtonComponent::draw(Vector2 pos)
{
    PanelComponent::draw(pos);
}

void ButtonComponent::update()
{
    if (Mouse.left_clicked)
    {
        if (Mouse.pos.x >= this->pos.x && Mouse.pos.x <= this->pos.x + this->size.x)
        {
            if (Mouse.pos.y >= this->pos.y && Mouse.pos.y <= this->pos.y + this->size.y)
            {
                this->on_click();
            }
        }
    }

    PanelComponent::update();
}

ButtonComponent *Button(std::function<void()> on_click, Color color, std::vector<Component *> children)
{
    return new ButtonComponent(on_click, color, children);
}