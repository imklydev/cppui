#pragma once

#include "component.h"

class CustomComponent : public Component
{
private:
    Component *custom_component = nullptr;

public:
    virtual Component *body() = 0;

    void draw(Vector2 pos) override
    {
        this->pos = pos;

        if (custom_component == nullptr)
        {
            custom_component = body();
        }

        custom_component->draw(pos);

        size = custom_component->size;
    };
};
