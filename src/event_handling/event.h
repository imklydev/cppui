#pragma once

struct Event
{
    bool quit = false;
    int scroll = 0;

    bool left_clicked = false;
    bool right_clicked = false;
};

inline Event event;