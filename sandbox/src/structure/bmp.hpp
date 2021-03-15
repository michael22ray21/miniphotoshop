#ifndef BMP_HPP
#define BMP_HPP

#include "../utils/reader.hpp"
#include "image.hpp"


class BMP : public IMAGE{
public:
    BMP(std::string filename);
    BMP(const BMP &image) : IMAGE(image){};
};

#endif