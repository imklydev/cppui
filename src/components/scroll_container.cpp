#include "scroll_container.h"
#include "rendering/drawing.h"

#include "window.h"

#include "event_handling/mouse.h"

ScrollContainerComponent::ScrollContainerComponent(std::vector<Component *> children) : VerticalContainerComponent(children)
{
}

void ScrollContainerComponent::update()
{
    scroll += Mouse.scroll * sensitivity;

    if (scroll < -size.y + Window.height)
    {
        scroll = -size.y + Window.height;
    }

    if (scroll > 0)
    {
        scroll = 0;
    }
}

void ScrollContainerComponent::draw(Vector2 pos)
{
    VerticalContainerComponent::draw(pos + Vector2(0, scroll));
}

ScrollContainerComponent *ScrollContainer(std::vector<Component *> children)
{
    return new ScrollContainerComponent(children);
}