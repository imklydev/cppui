#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "rendering/rendering.h"

#include "misc.h"

// Color
extern void SetDrawColor(SDL_Color color);

// Shapes
extern void DrawRect(Vector2 pos, Vector2 size, bool filled);

// Images
extern void DrawImage(Vector2 pos, Vector2 size, SDL_Texture *texture);

// Text
SDL_Texture *CreateTextTexture(std::string text, TTF_Font *font, Color color);

void DrawText(SDL_Texture *texture, Vector2 pos, Vector2 size);