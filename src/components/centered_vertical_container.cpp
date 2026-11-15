#include "centered_vertical_container.h"
#include "rendering/drawing.h"

CenteredVerticalContainerComponent::CenteredVerticalContainerComponent(std::vector<Component *> children) : Component(children)
{
}

void CenteredVerticalContainerComponent::draw(Vector2 pos)
{
    this->pos = pos;

    Vector2 child_pos = pos;
    float max_child_width = 0;

    // Make the containers width be the maximum width of its children
    for (Component *child : children)
    {
        if (child->size.x > max_child_width)
        {
            max_child_width = child->size.x;
        }
    }
    size.x = max_child_width;

    // Draw the children centered
    for (Component *child : children)
    {
        child->draw(child_pos + Vector2((size.x - child->size.x) / 2, 0));
        child_pos.y += child->size.y;
    }

    size.y = child_pos.y - pos.y;
}

CenteredVerticalContainerComponent *CenteredVerticalContainer(std::vector<Component *> children)
{
    return new CenteredVerticalContainerComponent(children);
}