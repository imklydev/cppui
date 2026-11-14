#include "mouse.h"

mouse Mouse;

void UpdateMouseFrame(Event event)
{
    Mouse.left_clicked = event.left_clicked;
    Mouse.right_clicked = event.right_clicked;
    SDL_GetMouseState(&Mouse.pos.x, &Mouse.pos.y);
}