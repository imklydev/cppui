#pragma once

struct Vector2
{
    float x, y;

    Vector2 operator-(Vector2 v) const
    {
        return {x - v.x, y - v.y};
    }
};

struct Vector2i
{
    int x, y;

    Vector2i operator-(Vector2i v) const
    {
        return {x - v.x, y - v.y};
    }
};

#include <cstdint>
struct Color
{
    std::uint8_t r, g, b, a;
};