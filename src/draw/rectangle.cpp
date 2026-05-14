#include "rectangle.h"
#include "line.h"
#include "image.h"

namespace Draw {

    /*
               x,y -------------- x+width, y
                   |             |
                   |             |
                   |             |
        x,y+height |_____________| x+width, y+height
    */

    void rectangle(Image& image, int x, int y, int width, int height, uint32_t color) {
        // top
        horizontalLine(image,x, x+width,y, color);
        
        // left
        verticalLine(image, x, y, y+height, color);

        // bottom
        horizontalLine(image, x, x+width, y+height, color);

        // right
        verticalLine(image,x+width,y,y+height, color);
    }
}