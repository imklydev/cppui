#include "margin_container.h"

MarginContainerComponent::MarginContainerComponent(int margin, std::vector<Component *> children) : VerticalContainerComponent(children), margin(margin)
{
}

void MarginContainerComponent::draw(Vector2 pos)
{
    VerticalContainerComponent::draw(pos + Vector2(this->margin, this->margin));
    this->size = this->size + Vector2(this->margin*2, this->margin*2);
}

MarginContainerComponent *MarginContainer(int margin, std::vector<Component *> children)
{
    return new MarginContainerComponent(margin, children);
}