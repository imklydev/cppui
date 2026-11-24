#pragma once

#include "component.h"

struct SDL_Texture;

// A component that displays an image
class ImageComponent : public Component
{
private:
    SDL_Texture *image_texture;

public:
    ImageComponent(std::string path, Vector2 size);

    Component *resize(Vector2 new_size) override;

    void draw(Vector2 pos) override;
};

// Creates a Image component
extern ImageComponent *Image(std::string path, Vector2 size);