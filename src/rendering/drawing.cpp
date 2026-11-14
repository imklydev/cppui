#include "drawing.h"

// Color
void SetDrawColor(Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

// Shapes
void DrawRect(Vector2 pos, Vector2 size, bool filled)
{
    SDL_FRect rect = {pos.x, pos.y, size.x, size.y};

    if (filled)
    {
        SDL_RenderFillRect(renderer, &rect);
    }
    else
    {
        SDL_RenderRect(renderer, &rect);
    }
}

// Images
SDL_Texture *CreateImageTexture(std::string path)
{
    return IMG_LoadTexture(renderer, path.c_str());
}

void DrawImage(Vector2 pos, Vector2 size, SDL_Texture *texture)
{
    SDL_FRect rect = {pos.x, pos.y, size.x, size.y};

    SDL_RenderTexture(renderer, texture, nullptr, &rect);
}

// Text
SDL_Texture *CreateTextTexture(std::string text, TTF_Font *font, Color color)
{
    SDL_Color SDLColor = {color.r, color.g, color.b, color.a};
    SDL_Surface *text_surface = TTF_RenderText_Blended(font, text.c_str(), 0, SDLColor);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_DestroySurface(text_surface);

    return text_texture;
}

void DrawText(SDL_Texture *texture, Vector2 pos, Vector2 size)
{
    SDL_FRect rect = {pos.x, pos.y, size.x, size.y};
    SDL_RenderTexture(renderer, texture, nullptr, &rect);
}