#include "text.h"
#include "rendering/drawing.h"

TTF_Font *GetFont(std::string path, float font_size)
{
    return TTF_OpenFont(path.c_str(), font_size);
}

TextComponent::TextComponent(std::string text, TTF_Font *font, Color color)
{
    this->text_texture = CreateTextTexture(text, font, color);
    
    int w, h;
    if (TTF_GetStringSize(font, text.c_str(), text.size(), &w, &h)) {
        this->text_size.x = static_cast<float>(w);
        this->text_size.y = static_cast<float>(h);
    }
}

void TextComponent::draw(Vector2 pos)
{
    if (this->text_texture)
    {
        DrawText(this->text_texture, pos, this->text_size);
    }

    Component::draw(pos);
}

TextComponent *Text(std::string text, TTF_Font *font, Color color)
{
    return new TextComponent(text, font, color);
}