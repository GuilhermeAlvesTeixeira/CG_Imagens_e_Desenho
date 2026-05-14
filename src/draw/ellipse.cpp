#include <cmath>

#include "ellipse.h"
#include "image.h"

constexpr float PI  = 3.141592653589793f;

namespace Draw {

    void ellipse(Image& image, int cx, int cy, int a, int b, uint32_t color) {

        float delta = 1.0f;

        for (int ang = 0; ang <= 90; ang+=delta) {
            
            float rad = ang * PI / 180.f;

            int x = a * cos(rad);
            int y = b * sin(rad);

            image.setPixel(cx + x, cy + y, color);
            image.setPixel(cx - x, cy + y, color);
            image.setPixel(cx + x, cy - y, color);
            image.setPixel(cx - x, cy - y, color);
        }
    }

   void ellipseBresenham(Image& image, int cx, int cy, int a, int b, uint32_t color){
        // Erro (x,y) = b²x² + a²y² - a²b²

        //Região 1 (maior variação em y)
        for (int x = a, y=0; b*b*x > a*a*y; y++) {

            image.setPixel(cx + x, cy + y, color);
            image.setPixel(cx - x, cy + y, color);
            image.setPixel(cx + x, cy - y, color);
            image.setPixel(cx - x, cy - y, color); 
        
            int a2 = a*a; int b2 = b*b;

            int erro_r = std::abs(b2 * x*x + a2 * (y+1) * (y+1) - a2*b2);
            int erro_l = std::abs(b2*(x-1)*(x-1)+a2*(y+1)*(y+1) - a2*b2);

            // escolhe qual é o mehlor
            if (erro_l < erro_r) {
                x--;
            }
        }
        // Região 2 (maior variação em x)

        for(int x = 0, y = b; b*b*x < a*a*y; x++) {
            image.setPixel(cx + x, cy + y, color);
            image.setPixel(cx - x, cy + y, color);
            image.setPixel(cx + x, cy - y, color);
            image.setPixel(cx - x, cy - y, color);

            int a2 = a*a; int b2 = b*b;

            // escolhe qual é o mehlor
            int erro_r = std::abs(b2*(x+1)*(x+1)+a2*(y)*(y) - a2*b2);
            int erro_l = std::abs(b2 * (x+1)*(x+1) + a2 * (y-1) * (y-1) - a2*b2);
            
            if(erro_l < erro_r) {
                y--;
            }
        }
  
   }

}
