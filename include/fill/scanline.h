#pragma once 

#include <vector>

#include "image.h"
#include "geometry/point.h"

// polígono é um vector de pontos
namespace Fill {
    void scanline(Image& image, const std::vector<Geometry::Point>& polygon, int color);
}
    
