#include <fstream>
#include "../structure/raw.hpp"
#include "../structure/bmp.hpp"
#include "../structure/pbm.hpp"
#include "../structure/pgm.hpp"
#include "../structure/ppm.hpp"
#define uchar unsigned char

void writeRAW(std::string filename, RAW raw){
    std::ofstream of{filename, std::ios_base::binary };
    if (of){
        for (int i = 0; i < raw.headSize; i++){
            of.write((const char*) &raw.header[i], sizeof(raw.header[i]));
        }
        
        for (int i = 0; i < raw.height; i++){
            for (int j = 0; j < raw.width; j++){
                of.write((const char*) &raw.pixels[i][j], sizeof(raw.pixels[i][j]));
            }
        }
    }
    of.close();
};