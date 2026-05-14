#include <cmath>

#include "circle.h"
#include "image.h"

constexpr float PI  = 3.141592653589793f;
constexpr int STEPS = 360;

namespace Draw {

    void circle(Image& image, int cx, int cy, int r, uint32_t color) {
        
        for(int i = 0; i < STEPS; i++) {

            float angle = 2.0f * PI * i / STEPS;

            int x = cx + r * std::cos(angle);
            int y = cy + r * std::sin(angle);

            image.setPixel(x,y,color);
        }
    }

    void circleBresenham(Image& image, int cx, int cy, int r, uint32_t color) {
        int x = 0;
        int y = r;
        int dM = 3 - 2 * r; // dM = 5/4 - r -> dm = 10/4 - 2r -> dm = 3 - 2r
        while(x <= y) {

            image.setPixel(cx + x, cy + y, color);
            image.setPixel(cx - x, cy + y, color);
            image.setPixel(cx + x, cy - y, color);
            image.setPixel(cx - x, cy - y, color);
            image.setPixel(cx + y, cy + x, color);
            image.setPixel(cx - y, cy + x, color);
            image.setPixel(cx + y, cy - x, color);
            image.setPixel(cx - y, cy - x, color);

            if(dM < 0) {
                dM += 4 * x + 6;
            } else {
                dM += 4 * (x - y) + 10;
                y--;
            }
            x++;
        }
    }
}
