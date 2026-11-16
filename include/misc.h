#pragma once

struct Vector2
{
    float x, y;

    Vector2 operator+(Vector2 v) const
    {
        return {x + v.x, y + v.y};
    }

    Vector2 operator-(Vector2 v) const
    {
        return {x - v.x, y - v.y};
    }

    bool operator==(Vector2 v) const
    {
        return x == v.x && y == v.y;
    }

    bool operator!=(Vector2 v) const
    {
        return !(*this == v);
    }
};

struct Vector2i
{
    int x, y;

    Vector2i operator+(Vector2i v) const
    {
        return {x + v.x, y + v.y};
    }

    Vector2i operator-(Vector2i v) const
    {
        return {x - v.x, y - v.y};
    }

    bool operator==(Vector2i v) const
    {
        return x == v.x && y == v.y;
    }

    bool operator!=(Vector2i v) const
    {
        return !(*this == v);
    }
};

#include <cstdint>
struct Color
{
    std::uint8_t r, g, b, a;
};