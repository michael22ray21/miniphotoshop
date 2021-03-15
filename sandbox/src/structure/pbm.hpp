#ifndef PBM_HPP
#define PBM_HPP

#include <iostream>
#include "../utils/reader.hpp"
#include "image.hpp"


class PBM : public IMAGE{
public:
    PBM(char* bytes, int size);
};

#endif