#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "misc.h"

// The base Component class
class Component;

class Component
{
protected:
    bool reupdate_size_to_fit_children = false;

public:
    std::vector<Component *> children;
    Vector2 size;

    Component(std::vector<Component *> children = {}) : children(children) {}

    virtual void update() {};
    virtual void draw(Vector2 pos) {};
};