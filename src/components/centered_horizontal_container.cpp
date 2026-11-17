#include "centered_horizontal_container.h"
#include "rendering/drawing.h"

CenteredHorizontalContainerComponent::CenteredHorizontalContainerComponent(std::vector<Component *> children) : Component(children)
{
}

void CenteredHorizontalContainerComponent::draw(Vector2 pos)
{
    this->pos = pos;

    Vector2 child_pos = pos;
    float max_child_height = 0;

    // Make the containers height be the maximum height of its children
    for (Component *child : children)
    {
        if (child->size.y > max_child_height)
        {
            max_child_height = child->size.y;
        }
    }
    size.y = max_child_height;

    // to make sure the children are centered with the correct size taken in consideration
    Component::draw(pos);

    // Draw the children centered
    for (Component *child : children)
    {
        child->draw(child_pos + Vector2(0, (size.y - child->size.y) / 2));
        child_pos.x += child->size.x;
    }

    size.x = child_pos.x - pos.x;

    Component::draw(pos);
}

CenteredHorizontalContainerComponent *CenteredHorizontalContainer(std::vector<Component *> children)
{
    return new CenteredHorizontalContainerComponent(children);
}