#include "pbm.hpp"

PBM::PBM(char* bytes, int size){
    int pointer = 0;
    std::string signature = nextString(bytes, size, &pointer);
    int width = nextInt(bytes, size, &pointer);
    int height = nextInt(bytes, size, &pointer);

    this->height = height;
    this->width = width;
    this->bitCount = 1;
    this->fileSize = size;
    this->pixels = (uchar**) malloc(height*sizeof(uchar*));
    for (int i = 0; i < height; i++){
        this->pixels[i] = (uchar*) malloc(width*sizeof(uchar));
    }

    this->header = (char*) malloc(sizeof(char)*(pointer));
    this->headSize = pointer;

    for(int i = 0; i < pointer; i++){
        this->header[i] = bytes[i];
    }
    if (bytes[0] == 'P' && bytes[1] == '1') {
        // ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
            uchar gray;
            if (nextInt(bytes, size, &pointer) == 0)
                gray = 255;
            else
                gray = 0;
            pixels[i][j] = gray;
            }
        }
    } else if (bytes[0] == 'P' && bytes[1] == '4') {
        // BINARY
        int bitPos = 7;
        for (int i = 0; i < height; i++) {
            if (bitPos != 7) {
                bitPos = 7;
                pointer += 1;
            }
            for (int j = 0; j < width; j++) {
                uchar byte = bytes[pointer];
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
