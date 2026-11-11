#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "log.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern void InitRenderingBackend();

extern void CreateSDLWindow();

extern void QuitRenderingBackend();
