#ifndef BMP_HPP
#define BMP_HPP

#include <iostream>
#include "../utils/reader.hpp"
#include "image.hpp"


class BMP : public IMAGE{
public:
    BMP(char* bytes, int size);
};

#endif