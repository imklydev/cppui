#include "horizontal_container.h"
#include "rendering/drawing.h"

HorizontalContainerComponent::HorizontalContainerComponent(std::vector<Component *> children) : Component(children)
{
}

void HorizontalContainerComponent::draw(Vector2 pos)
{
    this->pos = pos;

    Vector2 child_pos = pos;
    float max_child_width = 0;
    float max_child_height = 0;

    for (Component *child : children)
    {
        child->draw(child_pos);
        child_pos.x += child->size.x;

        if (child->size.y > max_child_height)
        {
            max_child_height = child->size.y;
        }

        if (child->size.x > max_child_width)
        {
            max_child_width = child->size.x;
        }
    }

    size = child_pos - pos;

    size.x = std::max(size.x, max_child_width);
    size.y = std::max(size.y, max_child_height);
}

HorizontalContainerComponent *HorizontalContainer(std::vector<Component *> children)
{
    return new HorizontalContainerComponent(children);
}