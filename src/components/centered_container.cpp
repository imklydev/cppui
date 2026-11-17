#include "centered_container.h"
#include "rendering/drawing.h"

CenteredContainerComponent::CenteredContainerComponent(std::vector<Component *> children) : Component(children)
{
}

void CenteredContainerComponent::draw(Vector2 pos)
{
    this->pos = pos;

    float max_child_width = 0;
    float total_child_height = 0;

    for (Component *child : children)
    {
        if (child->size.x > max_child_width)
        {
            max_child_width = child->size.x;
        }

        total_child_height += child->size.y;
    }

    size.x = std::max(size.x, max_child_width);
    size.y = std::max(size.y, total_child_height);

    Component::draw(pos);

    Vector2 child_pos = pos;
    child_pos.y += (size.y - total_child_height) / 2;

    for (Component *child : children)
    {
        // Center each child horizontally within the container
        child->draw(child_pos + Vector2((size.x - child->size.x) / 2, 0));
        child_pos.y += child->size.y;
    }
    
}

CenteredContainerComponent *CenteredContainer(std::vector<Component *> children)
{
    return new CenteredContainerComponent(children);
}