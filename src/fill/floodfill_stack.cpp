#include <vector>
#include "fill/floodfill_stack.h"
#include "geometry/point.h"

namespace Fill {

     void floodFillStack(Image& image, int x, int y, int color) {
        if (x < 0 || x >= image.getWidth() || y < 0 || y >= image.getHeight()) return;

        int oldColor = image.getPixel(x,y);

        if (oldColor != color) {
            
            FloodFillParameters params (image, oldColor, color);
            floodFill(params, x, y);
        }
        return;
     }


    void floodFill(FloodFillParameters& params, int x, int y) {
        std::vector<Geometry::Point> stack;
        stack.push_back({x,y});

        while(!stack.empty()) {
            // lê e remove o topo da pilha
            Geometry::Point point = stack.back();
            stack.pop_back();

            //como não implementei um setPixel safe, devemos:

            // verificar limites
            if (point.x < 0 || point.x >= params.image.getWidth() || point.y < 0 || point.y >= params.image.getHeight()) {
                continue;
            }

            // verificar pertencimento à região
            if(params.image.getPixel(point.x, point.y) != params.oldColor) {
                continue;
            }

            // Só aí pintamos o pixel
            params.image.setPixel(point.x, point.y, params.color);

            // inundações
            stack.push_back({point.x - 1, point.y});
            stack.push_back({point.x + 1, point.y});
            stack.push_back({point.x, point.y - 1});
            stack.push_back({point.x, point.y + 1});

        }

    }
}