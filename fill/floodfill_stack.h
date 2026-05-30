#pragma once 

#include "image.h"

namespace Fill {
    
    struct FloodFillParameters {
        FloodFillParameters(Image& i, int o, int c) : image(i), oldColor(o), color(c) {}
        Image& image;
        int oldColor;
        int color;
    };
    
    void floodFillStack(Image& image, int x, int y, int color);
    void floodFill(FloodFillParameters& params, int x, int y);
}
