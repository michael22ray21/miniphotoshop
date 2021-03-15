#include "pbm.hpp"

PBM::PBM(char* data, int size){
    int pointer = 0;
    std::string signature = nextString(data, size, &pointer);
    int width = nextInt(data, size, &pointer);
    int height = nextInt(data, size, &pointer);

    this->height = height;
    this->width = width;
    this->bitCount = 1;
    this->fileSize = size;
    this->pixels = (ushort**) malloc(height*sizeof(ushort*));
    for (int i = 0; i < height; i++){
        this->pixels[i] = (ushort*) malloc(width*sizeof(ushort));
    }

    this->header = (char*) malloc(sizeof(short)*(pointer));
    this->headSize = pointer;

    for(int i = 0; i < pointer; i++){
        this->header[i] = data[i];
    }
    if (data[0] == 'P' && data[1] == '1') {
        // ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
            ushort gray;
            if (nextInt(data, size, &pointer) == 0)
                gray = 255;
            else
                gray = 0;
            pixels[i][j] = gray;
            }
        }
    } else if (data[0] == 'P' && data[1] == '4') {
        // BINARY
        int bitPos = 7;
        for (int i = 0; i < height; i++) {
            if (bitPos != 7) {
                bitPos = 7;
                pointer += 1;
            }
            for (int j = 0; j < width; j++) {
                ushort byte = data[pointer];
                pixels[i][j] = (byte & (1 << bitPos)) ? 0 : 255;
                if (bitPos == 0) {
                    bitPos = 7;
                    pointer += 1;
                } else {
                    bitPos--;
                }
            }
        }
    }
}
