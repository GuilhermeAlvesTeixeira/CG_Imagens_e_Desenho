#include <SDL2/SDL.h>
#include <iostream>
#include <line.h>
#include <rectangle.h>
#include <circle.h>
#include <ellipse.h>

#include "../include/image.h"

enum class RenderMode {
    VERTICAL_HORIZONTAL_LINE,
    DDA,
    BRESENHAM_LINE,
    RECTANGLE,
    CIRCLE_ANGULAR,
    CIRCLE_BRESENHAM,
    ELLIPSE_ANGULAR,
    ELLIPSE_BRESENHAM
};

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

    RenderMode mode = RenderMode::BRESENHAM_LINE;
    std::cout << "Bresenham Line\n";

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
                        std::cout << "VERTICAL AND HORIZONTAL LINE";
                        break;

                    case SDLK_2:
                        mode = RenderMode::DDA;
                        std::cout << "DDA Line";
                        break;
        
                    case SDLK_3:
                        mode = RenderMode::BRESENHAM_LINE;
                        std::cout << "Bresenham Line";
                        break;
                    
                    case SDLK_4:
                        mode = RenderMode::RECTANGLE;
                        std::cout << "Rectangle";
                        break;

                    case SDLK_5:
                        mode = RenderMode::CIRCLE_ANGULAR;
                        std::cout << "Circle Angular";
                        break;

                    case SDLK_6:
                        mode = RenderMode::CIRCLE_BRESENHAM;
                        std::cout << "Circle Bresenham";
                        break;

                    case SDLK_7:
                        mode = RenderMode::ELLIPSE_ANGULAR;
                        std::cout << "Ellipse Angular";
                        break;

                    case SDLK_8:
                        mode = RenderMode::ELLIPSE_BRESENHAM;
                        std::cout << "Ellipse Bresenham";
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