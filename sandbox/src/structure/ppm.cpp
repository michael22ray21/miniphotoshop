#include "ppm.hpp"

PPM::PPM(char* data, int size){
    int pointer = 0;
    std::string signature = nextString(data, size, &pointer);
    int width = nextInt(data, size, &pointer);
    int height = nextInt(data, size, &pointer);
    int maxValue = nextInt(data, size, &pointer);

    this->height = height;
    this->width = width;
    this->bitCount = 24;
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

    if (data[0] == 'P' && data[1] == '3') {
    //   ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                this->r[i][j] = (int) ((nextInt(data, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
                this->g[i][j] = (int) ((nextInt(data, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
                this->b[i][j] = (int) ((nextInt(data, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
            }
        }
    } else if (data[0] == 'P' && data[1] == '6') {
    //   BINARY
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                this->r[i][j] = data[pointer];
                this->g[i][j] = data[pointer + 1];
                this->b[i][j] = data[pointer + 2];
                pointer += 3;
            }
        }
    }
}