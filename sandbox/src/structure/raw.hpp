#ifndef RAW_HPP
#define RAW_HPP

#include <iostream>
#include "../utils/reader.hpp"
#include "image.hpp"

class RAW : public IMAGE
{
public:
    RAW(char* bytes, int size);
};
#endif