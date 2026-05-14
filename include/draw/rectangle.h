#pragma once

#include <cstdint>

class Image;

namespace Draw {
    void rectangle(Image& image, int x, int y, int width, int height, uint32_t color);
}