#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include "../utils/reader.hpp"
#define uchar unsigned char

class IMAGE{
public:
    int width, height, bitCount, fileSize, headSize;
    char* header;
    uchar** pixels;
    uchar** r;
    uchar** g;
    uchar** b;

    ~IMAGE();
};
#endif