#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <fstream>
#include <iostream>
#include "../utils/reader.hpp"
#define ushort unsigned short

class IMAGE{
public:
    int width, height, bitCount, fileSize, headSize;
    char* header;
    ushort** pixels;
    ushort** r;
    ushort** g;
    ushort** b;

    ~IMAGE();
};
#endif