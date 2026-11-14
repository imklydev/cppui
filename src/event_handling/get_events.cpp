#include "get_events.h"

Event GetEvents()
{
    Event e;

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            e.quit = true;
        }

        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                e.left_clicked = true;
            } else if(event.button.button == SDL_BUTTON_RIGHT)
            {
                e.right_clicked = true;
            }
        }
    }

    return e;
}