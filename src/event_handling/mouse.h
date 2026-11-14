#pragma once
#include "misc.h"
#include "event.h"

#include <SDL3/SDL.h>

class mouse
{
public:
    Vector2 pos;

    bool left_clicked;
    bool right_clicked;
};

extern mouse Mouse;

extern void UpdateMouseFrame(Event event);