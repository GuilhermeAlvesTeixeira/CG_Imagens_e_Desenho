#include <SDL2/SDL.h>
#include <iostream>
#include <line.h>
#include <rectangle.h>
#include <circle.h>
#include <ellipse.h>
#include <vector>

#include "fill/floodfill_recursive.h"
#include "fill/floodfill_stack.h"
#include "fill/scanline.h"

#include "geometry/point.h"

#include "../include/image.h"

enum class RenderMode {
    VERTICAL_HORIZONTAL_LINE,
    DDA,
    BRESENHAM_LINE,
    RECTANGLE,
    CIRCLE_ANGULAR,
    CIRCLE_BRESENHAM,
    ELLIPSE_ANGULAR,
    ELLIPSE_BRESENHAM,

    FLOODFILL_RECURSIVE,
    FLOODFILL_STACK,
    SCANLINE
};

void printMenu() {
    std::cout <<
    "[1] Vertical & Horizontal Line\n"
    "[2] DDA Line\n"
    "[3] Bresenham Line\n"
    "[4] Rectangle\n"
    "[5] Circle Angular\n"
    "[6] Circle Bresenham\n"
    "[7] Ellipse Angular\n"
    "[8] Ellipse Bresenham\n"
    "[9] Flood Fill Recursive\n"
    "[0] Flood Fill Stack\n"
    "[S] Scanline\n";
}

//.:: Main ::.
int main() {

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Erro ao inicializar SDL" << '\n';
        return 1;
    }

    const int WIDTH = 800; const int HEIGHT = 600;

    SDL_Window* window = SDL_CreateWindow("Atividade 03", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH , HEIGHT ,0);

    if(!window) {
        std::cout << "Erro de janela" << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    //.: SETUP :.
    Image image(WIDTH, HEIGHT);
    
    bool running = true;
    SDL_Event event;

    RenderMode mode = RenderMode::FLOODFILL_RECURSIVE;
    printMenu();
    std::cout << "\033[32mModo atual: Flood Fill Recursive\033[0m\n";

    int mouseX = 0; int mouseY = 0;

    while(running) {
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) {
                running = false;
            }

            if(event.type == SDL_KEYDOWN) {
                switch(event.key.keysym.sym) {

                    case SDLK_1:
                        mode = RenderMode::VERTICAL_HORIZONTAL_LINE;
                        printMenu();
                        std::cout << "\033[32mModo atual: VERTICAL AND HORIZONTAL LINE\033[0m\n";
                        break;

                    case SDLK_2:
                        mode = RenderMode::DDA;
                        printMenu();
                        std::cout << "\033[32mModo atual: DDA Line\033[0m\n";
                        break;
        
                    case SDLK_3:
                        mode = RenderMode::BRESENHAM_LINE;
                        printMenu();
                        std::cout << "\033[32mModo atual: Bresenham Line\033[0m\n";
                        break;
                    
                    case SDLK_4:
                        mode = RenderMode::RECTANGLE;
                        printMenu();
                        std::cout << "\033[32mModo atual: Rectangle\033[0m\n";
                        break;

                    case SDLK_5:
                        mode = RenderMode::CIRCLE_ANGULAR;
                        printMenu();
                        std::cout << "\033[32mModo atual: Circle Angular\033[0m\n";
                        break;

                    case SDLK_6:
                        mode = RenderMode::CIRCLE_BRESENHAM;
                        printMenu();
                        std::cout << "\033[32mModo atual: Circle Bresenham\033[0m\n";
                        break;

                    case SDLK_7:
                        mode = RenderMode::ELLIPSE_ANGULAR;
                        printMenu();
                        std::cout << "\033[32mModo atual: Ellipse Angular\033[0m\n";
                        break;

                    case SDLK_8:
                        mode = RenderMode::ELLIPSE_BRESENHAM;
                        printMenu();
                        std::cout << "\033[32mModo atual: Ellipse Bresenham\033[0m\n";
                        break;
                    case SDLK_9:
                        mode = RenderMode::FLOODFILL_RECURSIVE;
                        printMenu();
                        std::cout << "\033[32mModo atual: Flood Fill Recursive\033[0m\n";
                        break;

                    case SDLK_0:
                        mode = RenderMode::FLOODFILL_STACK;
                        printMenu();
                        std::cout << "\033[32mModo atual: Flood Fill Stack\033[0m\n";
                        break;

                    case SDLK_s:
                        mode = RenderMode::SCANLINE;
                        printMenu();
                        std::cout << "\033[32mModo atual: Scanline\033[0m\n";
                        break;
                }
                std::cout << "\n";
            }
        }

        SDL_GetMouseState(&mouseX, &mouseY);
        image.clear(0xFF000000);

        //.:: Testes ::.

        /*// 1) Reta horizontal e vertical
        Draw::horizontalLine(image, 0, WIDTH, mouseY, 0xFF00FF00);
        Draw::verticalLine(image, mouseX, 0, HEIGHT, 0xFFFF0000);
        */
        
        // 2) Reta DDA
        //Draw::lineDDA(image,WIDTH/2,HEIGHT/2,mouseX,mouseY,0xFFFFFFFF);

        // 3) Reta Bresenham
        //Draw::lineBresenham1Oc(image, 100, 100, mouseX, mouseY, 0xFFFFFFFF);
        //Draw::lineBresenham(image, WIDTH/2, HEIGHT/2, mouseX, mouseY, 0xFF9944BB);
        
        // 4) Retangulo 
        //Draw::rectangle(image, mouseX, mouseY, 300, 300, 0xFFFFFFFF);
        
        // 5) Circulo Angular
        //Draw::circle(image, mouseX , mouseY, 150, 0xFFFFFFFF);

        // 6) Circulo Bresenham
        //int r = std::abs(mouseX - WIDTH/2);
        //Draw::circleBresenham(image,WIDTH/2, HEIGHT/2, r, 0xFFFFFFFF);

        // 7) Ellipse comum 
        //int a = std::abs(mouseX - WIDTH / 2);
        //int b = std::abs(mouseY - HEIGHT / 2);

        //Draw::ellipse(image,WIDTH/2,HEIGHT/2,a,b,0xFFFFFFFF);

        // 8) Ellipse de Bresenham
        //int a = std::abs(mouseX - WIDTH / 2);
        //int b = std::abs(mouseY - HEIGHT / 2);

        //Draw::ellipseBresenham(image, WIDTH/2, HEIGHT/2, a, b, 0xFFFFFFFF);
        
        //image.setPixel(400,300,0xFFFFFFFF);

        switch(mode) {

            case RenderMode::VERTICAL_HORIZONTAL_LINE:
                Draw::horizontalLine(image, 0, WIDTH, mouseY, 0xFF00FF00);
                Draw::verticalLine(image, mouseX, 0, HEIGHT, 0xFFFF0000);
                break;

            case RenderMode::DDA:
                Draw::lineDDA(image, WIDTH/2, HEIGHT/2, mouseX, mouseY, 0xFFFFFFFF);
                break;

            case RenderMode::BRESENHAM_LINE:
                Draw::lineBresenham(image, WIDTH/2, HEIGHT/2, mouseX, mouseY, 0xFF00FF00);
                break;
            
            case RenderMode::RECTANGLE:
                Draw::rectangle(image, mouseX, mouseY, 300, 300, 0xFFFFFFFF);
                break;

            case RenderMode::CIRCLE_ANGULAR: {
                int r = std::abs(mouseX - WIDTH/2);
                Draw::circle(image, WIDTH/2, HEIGHT/2, r, 0xFFFFFF00);
                break;
            }

            case RenderMode::CIRCLE_BRESENHAM: {
                int r = std::abs(mouseX - WIDTH/2);
                Draw::circleBresenham(image, WIDTH/2, HEIGHT/2, r, 0xFF00FFFF);
                break;
            }

            case RenderMode::ELLIPSE_ANGULAR: {
                int a = std::abs(mouseX - WIDTH/2);
                int b = std::abs(mouseY - HEIGHT/2);
                Draw::ellipse(image, WIDTH/2, HEIGHT/2, a, b, 0xFFF00FFF);
                break;
            }

            case RenderMode::ELLIPSE_BRESENHAM: {
                int a = std::abs(mouseX - WIDTH/2);
                int b = std::abs(mouseY - HEIGHT/2);
                Draw::ellipseBresenham(image, WIDTH/2, HEIGHT/2, a, b, 0xFFFFFFFF);
                break;
            }
            case RenderMode::FLOODFILL_RECURSIVE: {
                Draw::rectangle(image,175,125,450,350,0xFFFFFFFF);
                Fill::floodFillRecursive(image,400,300,0xFFFF0000);
                break;
            }
            case RenderMode::FLOODFILL_STACK: {
                Draw::rectangle(image,mouseX,mouseY,200,100,0xFFFFFFFF);
                Fill::floodFillStack(image,mouseX+10,mouseY+10,0xFF00FF00);
                break;
            }
            case RenderMode::SCANLINE: {
                std::vector<Geometry::Point> triangulo = {
                    {200,50},
                    {325,225},
                    {75,225}
                };

                // centroide 
                // xc = soma(xi) / n , onde n é o tama
                // yc = smoa(yi) / n
                
                int sumX = 0;
                int sumY = 0;

                for(const auto& p : triangulo) {
                    sumX += p.x;
                    sumY += p.y;
                }
                
                // centros do triangulo
                int centerX_t = sumX / triangulo.size();
                int centerY_t = sumY / triangulo.size();
                //std::cout << centerX << "," << centerY << std::endl;
                
                std::vector<Geometry::Point> triangulo_translate;
                for(const auto& p : triangulo) {
                    /*
                    std::cout<< "( " << (p.x + (mouseX - centerX_t)) << " )" 
                    << ",( " << (p.y + (mouseY - centerY_t))<< " ) " << std::endl ;
                    */
                    triangulo_translate.push_back({
                        p.x + (mouseX - centerX_t),
                        p.y + (mouseY - centerY_t)
                    });
                }
                
                Fill::scanline(image,triangulo_translate,0xFFFFFF00);
 
                // CASO DA RETA HORIZONTAL (TRAPEZIO)
                std::vector<Geometry::Point> trapezio_descendente = {
                    {450,100},
                    {650,100},
                    {750,350},
                    {350,350}
                };

                sumX = 0;
                sumY = 0;

                for(const auto& p : triangulo) {
                    sumX += p.x;
                    sumY += p.y;
                }
                
                // centros dos trapezios
                int centerX_trap = sumX / trapezio_descendente.size();
                int centerY_trap = sumY/ trapezio_descendente.size();

                std::vector<Geometry::Point> trapezio_translate;
                for(const auto& p : trapezio_descendente) {
                    
                    /*
                    std::cout<< "( " << (p.x + (mouseX - centerX_trap)) << " )" 
                    << ",( " << (p.y + (mouseY - centerY_trap))<< " ) " << std::endl ;
                    */
                    trapezio_translate.push_back({
                        p.x + (-mouseX + centerX_trap),
                        p.y + (mouseY - centerY_trap)
                    });
                }
                
                Fill::scanline(image,trapezio_translate,0xFF00FFFF);
                
                break;
            }

        }
        
        SDL_UpdateTexture(texture, nullptr, image.data(), WIDTH * sizeof(int));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}