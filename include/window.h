#pragma once

// (hopefully) temporary
// These are hard coded values that any function can recognize and
// take Window.width or Window.height on their own so they have updated values.
#define WINDOW_WIDTH -154231
#define WINDOW_HEIGHT -154232

class WindowInfo
{
public:
    int height, width;
};

inline WindowInfo Window;

extern void UpdateWindowInfoValues();