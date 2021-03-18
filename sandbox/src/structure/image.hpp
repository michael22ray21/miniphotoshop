#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <fstream>
#include <iostream>
#include "../utils/reader.hpp"
#define uchar unsigned char

class IMAGE{
public:
    int width, height, bitCount, fileSize, headSize, depth;
    char* header;
    uchar** pixels;
    uchar*** rgbPixels;

    IMAGE(std::string filename);
    IMAGE(const IMAGE &image);

    ~IMAGE();
};
#endif