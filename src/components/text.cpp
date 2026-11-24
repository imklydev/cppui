#include "text.h"
#include "rendering/drawing.h"

TTF_Font *GetFont(std::string path, float font_size)
{
    if ((TTF_WasInit() == 0) && !TTF_Init())
    {
        error("SDL_ttf (font handling library) could not initialize");
    }

    return TTF_OpenFont(path.c_str(), font_size);
}

TextComponent::TextComponent(std::string text, TTF_Font *font, Color color)
{
    this->current_color = color;
    this->current_font = font;

    this->text_texture = CreateTextTexture(text, font, color);

    int w, h;
    if (TTF_GetStringSizeWrapped(this->current_font, text.c_str(), text.size(), 0, &w, &h))
    {
        this->size.x = static_cast<float>(w);
        this->size.y = static_cast<float>(h);
    }
}

void TextComponent::draw(Vector2 pos)
{
    if (this->text_texture)
    {
        DrawText(this->text_texture, pos, this->size);
    }

    Component::draw(pos);
}

void TextComponent::ChangeText(std::string text)
{
    SDL_DestroyTexture(this->text_texture);
    this->text_texture = CreateTextTexture(text, this->current_font, this->current_color);

    int w, h;
    if (TTF_GetStringSizeWrapped(this->current_font, text.c_str(), text.size(), 0, &w, &h))
    {
        this->size.x = static_cast<float>(w);
        this->size.y = static_cast<float>(h);
    }
}

TextComponent *Text(std::string text, TTF_Font *font, Color color)
{
    return new TextComponent(text, font, color);
}