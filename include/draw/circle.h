#pragma once

#include <cstdint>

class Image;

namespace Draw {
    void circle(Image& image, int cx, int cy, int r, uint32_t color);
    void circleBresenham(Image& image, int cx, int cy, int r, uint32_t color);
}