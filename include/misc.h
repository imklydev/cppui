#pragma once

struct Vector2 {
    float x, y;
};

struct Vector2i {
    int x, y;
};

#include <cstdint>
struct Color
{
    std::uint8_t r, g, b, a;
};