#ifndef PPM_HPP
#define PPM_HPP

#include <iostream>
#include "../utils/reader.hpp"
#include "image.hpp"


class PPM : public IMAGE{
public:
    PPM(char* data, int size);
};

#endif