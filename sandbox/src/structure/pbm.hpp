#ifndef PBM_HPP
#define PBM_HPP

#include "../utils/reader.hpp"
#include "image.hpp"


class PBM : public IMAGE{
public:
    PBM(std::string filename);
    PBM(const PBM &image) : IMAGE(image){};
};

#endif