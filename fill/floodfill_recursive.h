#pragma once 

#include "image.h"

namespace Fill {

    void floodFillRecursive(Image& image, int x, int y, int color);
    void floodFill(Image& image, int x, int y, int oldColor, int color);
}