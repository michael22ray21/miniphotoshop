#include "ppm.hpp"

PPM::PPM(char* bytes, int size){
    int pointer = 0;
    std::string signature = nextString(bytes, size, &pointer);
    int width = nextInt(bytes, size, &pointer);
    int height = nextInt(bytes, size, &pointer);
    int maxValue = nextInt(bytes, size, &pointer);

    this->height = height;
    this->width = width;
    this->bitCount = 24;
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

    if (bytes[0] == 'P' && bytes[1] == '3') {
    //   ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                this->r[i][j] = (int) ((nextInt(bytes, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
                this->g[i][j] = (int) ((nextInt(bytes, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
                this->b[i][j] = (int) ((nextInt(bytes, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
            }
        }
    } else if (bytes[0] == 'P' && bytes[1] == '6') {
    //   BINARY
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                this->r[i][j] = bytes[pointer];
                this->g[i][j] = bytes[pointer + 1];
                this->b[i][j] = bytes[pointer + 2];
                pointer += 3;
            }
        }
    }
}