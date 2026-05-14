#pragma once 

#include <cstdint>

class Image;

namespace Draw {

    void horizontalLine(Image& image, int x1, int  x2, int  y, uint32_t color);
    void verticalLine(Image& image, int  x, int  y1, int y2, uint32_t color);
    void lineDDA(Image& image, int x1, int y1, int x2, int y2, uint32_t color);

    // LIMITAÇÕES: SÓ FUNCIONA PARA O PRIMEIRO OCTANTE
    void lineBresenham1Oc(Image& image, int x1, int y1, int x2, int y2, uint32_t color);
    // considera todos os octantes
    void lineBresenham(Image& image, int x1, int y1, int x2, int y2, uint32_t color);
}