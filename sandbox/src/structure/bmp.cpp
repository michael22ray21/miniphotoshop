#include "bmp.hpp"

BMP::BMP(char* data, int size){
    int pointer = 10;
    int offset = nextInt32(data, size, &pointer);
    int headerSize = nextInt32(data, size, &pointer);
    int width, height, planes, bitCount;
    if (headerSize == 12) {
        width = nextInt16(data, size, &pointer);
        height = nextInt16(data, size, &pointer);
        planes = nextInt16(data, size, &pointer);
        bitCount = nextInt16(data, size, &pointer);
    } else if (headerSize == 40 || headerSize == 64) {
        width = nextInt32(data, size, &pointer);
        height = nextInt32(data, size, &pointer);
        planes = nextInt16(data, size, &pointer);
        bitCount = nextInt16(data, size, &pointer);
    }
    
    pointer = offset;
    // Assign acquired data to object
    this->height = height;
    this->width = width;
    this->bitCount = bitCount;
    this->fileSize = size;
    this->r = (ushort**) malloc(height*sizeof(ushort*));
    this->g = (ushort**) malloc(height*sizeof(ushort*));
    this->b = (ushort**) malloc(height*sizeof(ushort*));
    for (int i = 0; i < height; i++){
        this->r[i] = (ushort*) malloc(width*sizeof(ushort));
        this->g[i] = (ushort*) malloc(width*sizeof(ushort));
        this->b[i] = (ushort*) malloc(width*sizeof(ushort));
    }

    this->header = (char*) malloc(sizeof(short)*(pointer));
    this->headSize = pointer;
    for(int i = 0; i < pointer; i++){
        this->header[i] = data[i];
    }

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            if (bitCount == 24) {
                ushort b = data[pointer];
                ushort g = data[pointer + 1];
                ushort r = data[pointer + 2];
                this->r[i][j] = r;
                this->g[i][j] = g;
                this->b[i][j] = b;
                pointer += 3;
            } else if (bitCount == 8) {
                ushort b = data[pointer];
                ushort g = data[pointer];
                ushort r = data[pointer];
                this->r[i][j] = r;
                this->g[i][j] = g;
                this->b[i][j] = b;
                pointer += 1;
            }
        }
    }
}