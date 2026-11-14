#include "image.h"
#include "rendering/drawing.h"

ImageComponent::ImageComponent(std::string path, Vector2 size) : size(size)
{
    this->image_texture = CreateImageTexture(path);
}

void ImageComponent::draw(Vector2 pos)
{
    DrawImage(pos, this->size, this->image_texture);
}

ImageComponent *Image(std::string path, Vector2 size)
{
    return new ImageComponent(path, size);
}