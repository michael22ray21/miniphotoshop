#include "pgm.hpp"

PGM::PGM(char* bytes, int size){
    int pointer = 0;
    std::string signature = nextString(bytes, size, &pointer);
    int width = nextInt(bytes, size, &pointer);
    int height = nextInt(bytes, size, &pointer);
    int maxValue = nextInt(bytes, size, &pointer);

    this->height = height;
    this->width = width;
    this->bitCount = 8;
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

    if (bytes[0] == 'P' && bytes[1] == '2') {
        // ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                uchar gray = (int) ((nextInt(bytes, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
                pixels[i][j] = gray;
            }
        }
    } else if (bytes[0] == 'P' && bytes[1] == '5') {
        // BINARY
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                uchar gray = bytes[pointer];
                pixels[i][j] = gray;
                pointer += 1;
            }
        }
    }
}