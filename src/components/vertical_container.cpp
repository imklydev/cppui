#include "panel.h"
#include "rendering/drawing.h"

VerticalContainerComponent::VerticalContainerComponent(std::vector<Component *> children) : Component(children)
{
    this->reupdate_size_to_fit_children = true;
}

VerticalContainerComponent *VerticalContainer(std::vector<Component *> children)
{
    return new VerticalContainerComponent(children);
}