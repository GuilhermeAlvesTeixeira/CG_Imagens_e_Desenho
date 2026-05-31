#include <cmath>
#include <algorithm>
#include "draw/line.h"
#include "fill/scanline.h"

namespace Fill {
    void scanline(Image& image, const std::vector<Geometry::Point>& polygon, int color) {
        
        if(polygon.size() < 3) return;

        //Verificar ymin e ymax
        int ymin = polygon[0].y;
        int ymax = polygon[0].y;

        for(const auto& p : polygon) {
            ymin = std::min(ymin, p.y);
            ymax = std::max(ymax, p.y);
        }

        // Percorrer scanlines
        for(int y = ymin; y <= ymax; y++) {
            std::vector<float> intersections;

            for(int i=0; i < polygon.size(); i++) {
                // polygon[0] = A
                // polygon[1] = B
                // polygon[2] = C  
                Geometry::Point p1 = polygon[i];   // i = 2 -> polygon[2] = C
                Geometry::Point p2 = polygon[(i+1) % polygon.size()]; // i = 2 -> polygon[2+1 % 3] -> polygon[0] = A

                // caso especial da reta horizontal
                if(p1.y == p2.y) {
                    //intersections.push_back(p1.x);
                    //intersections.push_back(p2.x);

                    continue;
                }
                
                // garantir superioridade de p1
                if(p1.y > p2.y) {
                    Geometry::Point temp = p1;
                    p1 = p2;
                    p2 = temp;
                }
                
                // verifica se a scanline cruza a aresta
                if(y < p1.y || y > p2.y) {
                    continue;
                }

                // equação do slide 12
                float t = static_cast<float>(y - p1.y) / static_cast<float>(p2.y - p1.y);
                float x = p1.x + t * (p2.x - p1.x);

                intersections.push_back(x);
            }

            //ordena
            std::sort(intersections.begin(), intersections.end());

            // preenche entre pares consecutivos
            for(int i = 0; i+1 < intersections.size(); i+=2) {
                int x1 = static_cast<int>(std::round(intersections[i]));
                int x2 = static_cast<int>(std::round(intersections[i+1]));

                Draw::horizontalLine(image,x1,x2,y,color);
            }
 
        }
    }
}