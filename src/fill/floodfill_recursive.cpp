#include "fill/floodfill_recursive.h"

namespace Fill {
    void floodFillRecursive(Image& image, int x, int y, int color) {
        if (x < 0 || x >= image.getWidth() || y < 0 || y >= image.getHeight()) return;

        int oldColor = image.getPixel(x,y);

        if (oldColor != color) {
            // inicia o algoritmo recrusivo substituindo a cor anterior
            floodFill(image, x, y, oldColor, color);
        }
        return;
    } 

    void floodFill(Image& image, int x, int y, int oldColor, int color ) {
        if (x < 0 || x >= image.getWidth() || y < 0 || y >= image.getHeight()) return;

        if (image.getPixel(x,y) != oldColor ) return;
        
        image.setPixel(x, y, color);

        floodFill(image, x - 1, y, oldColor, color); 
        floodFill(image, x + 1, y, oldColor, color); 
        floodFill(image, x, y - 1, oldColor, color); 
        floodFill(image, x, y + 1, oldColor, color);
        
    }
}
