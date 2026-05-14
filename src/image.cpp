#include "image.h"

Image::Image(int w, int h) : width(w), height(h), pixels (w * h, 0) {

}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

void Image::clear(int color) {
    std::fill(pixels.begin(), pixels.end(), color);
}

void Image::setPixel(int x, int y, int color) {
   
    //Para evitar os benditos erros de segmentação...
    if(x < 0 ||y < 0 ||x >= width ||y >= height) {
        return;
    }

    pixels[index(x,y)] = color;
}

int Image::getPixel(int x, int y) const {
    return pixels[index(x,y)];
}

const int* Image::data() const {
    return pixels.data();
}



