#ifndef PPM_HPP
#define PPM_HPP

#include "../utils/reader.hpp"
#include "image.hpp"


class PPM : public IMAGE{
public:
    PPM(std::string filename);
    PPM(const PPM &image) : IMAGE(image){};
};

#endif