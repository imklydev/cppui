#pragma once

struct Event {
    bool quit = false;

    bool left_clicked = false;
    bool right_clicked = false;
};

inline Event event;