#include "window.h"

#include "rendering/rendering.h"

void UpdateWindowInfoValues()
{
    SDL_GetWindowSize(window, &Window.width, &Window.height);
}