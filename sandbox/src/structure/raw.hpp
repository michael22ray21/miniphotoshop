#ifndef RAW_HPP
#define RAW_HPP

#include "../utils/reader.hpp"
#include "image.hpp"

class RAW : public IMAGE
{
public:
    RAW(std::string filename);
    RAW(const RAW &image) : IMAGE(image){};
};
#endif