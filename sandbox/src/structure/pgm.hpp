#ifndef PGM_HPP
#define PGM_HPP

#include <iostream>
#include "../utils/reader.hpp"
#include "image.hpp"


class PGM : public IMAGE{
public:
    PGM(std::string filename);
};

#endif