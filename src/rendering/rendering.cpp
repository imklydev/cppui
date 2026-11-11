#include "rendering.h"

SDL_Window *window;
SDL_Renderer *renderer;

void InitRenderingBackend()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        error("SDL (the rendering backend) could not initialize");
    }

    if (!TTF_Init())
    {
        error("SDL_ttf (font handling library) could not initialize");
    }
}

void CreateSDLWindow()
{
    window = SDL_CreateWindow("Application", 800, 800, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, nullptr);
}

void QuitRenderingBackend()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    TTF_Quit();
}