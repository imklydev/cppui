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
    }

    return e;
}