#pragma once

#include "component.h"

struct TTF_Font;
struct SDL_Texture;

typedef TTF_Font *Font;

extern TTF_Font *GetFont(std::string path, float font_size);

// A component that displays text
class TextComponent : public Component
{
private:
    SDL_Texture *text_texture;

public:
    TextComponent(std::string text, TTF_Font *font, Color color);

    void draw(Vector2 pos) override;
};

// Creates a text component
extern TextComponent *Text(std::string text, TTF_Font *font, Color color);