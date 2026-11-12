#include "rendering/rendering.h"
#include "event_handling/get_events.h"
#include "app.h"

int main()
{
    InitRenderingBackend();

    CreateSDLWindow();

    App app = Application();

    bool running = true;
    while (running)
    {
        event = GetEvents();

        if (event.quit)
        {
            running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        app.update();
        app.draw({0, 0});

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    QuitRenderingBackend();
}