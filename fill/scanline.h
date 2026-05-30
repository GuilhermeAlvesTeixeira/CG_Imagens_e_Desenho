#pragma once 

#include <vector>

#include "image.h"
#include "geometry/point.h"

// polígono é um vector de pontos
namespace Fill {
    void scanlineFill(Image& image, const std::vector<Point>& polygon, int color);
}
    
