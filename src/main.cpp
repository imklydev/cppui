#include "rendering/rendering.h"
#include "event_handling/get_events.h"

int main()
{
    InitRenderingBackend();

    CreateSDLWindow();

    bool running = true;
    while (running)
    {
        event = GetEvents();

        if (event.quit)
        {
            running = false;
        }

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    QuitRenderingBackend();
}