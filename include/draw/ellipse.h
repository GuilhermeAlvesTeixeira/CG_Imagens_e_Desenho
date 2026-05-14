#pragma once

#include <cstdint>


class Image;

namespace Draw {

    void ellipse(Image& image, int cx, int cy, int rx, int ry, uint32_t color);
    void ellipseBresenham(Image& image, int cx, int cy, int a, int b, uint32_t color);

}