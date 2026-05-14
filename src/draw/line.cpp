#include <cmath>

#include "line.h"
#include "image.h"

namespace Draw{

    void horizontalLine(Image& image, int x1, int x2, int y, uint32_t color) {
        if( x1 > x2 ) {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }

        for (int x = x1; x <= x2; x++) {
            image.setPixel(x,y,color);
        }
    }

    void verticalLine(Image& image, int x, int y1, int y2, uint32_t color) {

        if (y1 > y2) {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }

        for (int y = y1; y <= y2; y++) {
            image.setPixel(x,y,color);
        }
    }

    void lineDDA(Image& image, int x1, int y1, int x2, int y2, uint32_t color) {
        int dx = x2 - x1;
        int dy = y2 - y1;

        //Calculo do maior deslocamento
        int deltaMax = std::max(std::abs(dx), std::abs(dy));

        //Calcular incrementos
        float xInc = dx / (float) deltaMax;
        float yInc = dy / (float) deltaMax;

        float x = x1;
        float y = y1;

        for (int i = 0; i <= deltaMax; ++i) {
            image.setPixel(std::round(x), std::round(y), color);
            x+= xInc; y+=yInc;
        }
        
    }

    /*
        lembrando do algoritmo: 
        calcular coeficientes - a = dy; b=dx; c= dot(x(x1,y1),y(x2,y2))
        teremos a equação: 4x - 8y + 4 = 0 

        dada a equação da reta (eq1), criamos uma "função distância"
        a.p_x + b.p_y + c = 0 -> d(P) = a.p_x + b.p_y + c

        Quanto ao sinal:
        pontos na reta:        d(P) é igual a 0
        pontos acima da reta:  d(P) é negativo
        pontos abaixo da reta: d(P) é positivo

        obs: a medida que d(P) equivale a um hiperplano
            - Quanto maior o módulo de d(P), mais afastado estará P da reta

        Equação do hiperplano
        Δ = p * n - p1 * n  | n = (Δy, -Δx)
    */

    // LIMITAÇÕES: SÓ FUNCIONA PARA O PRIMEIRO OCTANTE
    void lineBresenham1Oc(Image& image, int x1, int y1, int x2, int y2, uint32_t color) {
        // Considerando o primeiro octante
        // partida = (x,y)
        // E       = (x+1, y)
        // NE      = (x+1, y+1)

        //Equação do hiperplano
        //Δ = p * n - p1 * n  | n = (Δy, -Δx)
        
        int a = y2 - y1;
        int b = -(x2 - x1);

        int dM = 2*a + b;

        //Ponto inicial (d(P))
        int x = x1; int y = y1;

        for (; x < x2; x++) {
            image.setPixel(x,y,color);

            if ( dM > 0) {
                y++;
                dM += 2*a + 2*b;
            }
            else {
                dM += 2*a;
            }
        }
    }

    void lineBresenham(Image& image, int x1, int y1, int x2, int y2, uint32_t color) {
        /*
            1) Descobrir os sinais para informar direção da reta
            2) Considerar dx e dy em magnitude
            3) Considerar caso da reta horizontal dominante e caso da reta vertical dominante
        */

       // sinais
       int sb, sa;

       if (x2 >= x1) {
            sb = 1;
       } else {
            sb = -1;
       }

       if (y2 >= y1) {
            sa = 1;
       } else {
            sa = -1;
       }

       // magintude
       int b = std::abs(x2 - x1);
       int a = std::abs(y2 - y1);

       // caso da reta mais horizontal (variação em x é maior que a variação em y)
       if(b >= a) {
            int dM = 2 * b - a;

            int x = x1; int y = y1;

            while (x != x2) {
                image.setPixel(x,y,color);

                if(dM > 0) {
                    y+=sa;
                    dM += 2 * a - 2 * b;
                } else {
                    dM += 2 * a;
                }
                x += sb;
            }
            image.setPixel(x2, y2, color);
       }

       // Caso reta mais vertical
       else {
          int dM = 2 * b - a;
          int x = x1; int y = y1;

          while(y != y2) {
            image.setPixel(x,y,color);
            
            if(dM > 0) {
                x += sb;
                dM += 2 * b - 2 * a;
            } else {
                dM += 2 * b;
            }
            y += sa;
          }
          image.setPixel(x2, y2, color);
       }
    }
}