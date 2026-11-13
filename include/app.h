#pragma once

#include "component.h"

#include "theme.h"
#include "log.h"
#include "misc.h"

#include "text.h"

// The App class, the parent of all of your components rendered to the screen
class App : public Component
{
public:
    App(std::vector<Component *> children) : Component(children) {}
};

extern App Application();