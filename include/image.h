#pragma once

#include <vector>
#include <cstdint>

class Image {
    private:
        int width;
        int height;
        std::vector<int> pixels;   // os meus pixels tem 32 bits de memória (4bytes)
        
        int index(int x, int y) const {
            return y * width + x;
        }

    public:
        Image(int w, int h);
        void clear (int color);
        void setPixel (int x, int y, int color);
        int getPixel(int x, int y) const;
        int getWidth() const;
        int getHeight() const;
        const int* data() const;
};