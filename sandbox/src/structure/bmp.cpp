#include "bmp.hpp"

BMP::BMP(char* bytes, int size){
    int pointer = 10;
    int offset = nextInt32(bytes, size, &pointer);
    int headerSize = nextInt32(bytes, size, &pointer);
    int width, height, planes, bitCount;
    if (headerSize == 12) {
        width = nextInt16(bytes, size, &pointer);
        height = nextInt16(bytes, size, &pointer);
        planes = nextInt16(bytes, size, &pointer);
        bitCount = nextInt16(bytes, size, &pointer);
    } else if (headerSize == 40 || headerSize == 64) {
        width = nextInt32(bytes, size, &pointer);
        height = nextInt32(bytes, size, &pointer);
        planes = nextInt16(bytes, size, &pointer);
        bitCount = nextInt16(bytes, size, &pointer);
    }
    
    pointer = offset;
    // Assign acquired data to object
    this->height = height;
    this->width = width;
    this->bitCount = bitCount;
    this->fileSize = size;
    this->r = (uchar**) malloc(height*sizeof(uchar*));
    this->g = (uchar**) malloc(height*sizeof(uchar*));
    this->b = (uchar**) malloc(height*sizeof(uchar*));
    for (int i = 0; i < height; i++){
        this->r[i] = (uchar*) malloc(width*sizeof(uchar));
        this->g[i] = (uchar*) malloc(width*sizeof(uchar));
        this->b[i] = (uchar*) malloc(width*sizeof(uchar));
    }

    this->header = (char*) malloc(sizeof(char)*(pointer));
    this->headSize = pointer;
    for(int i = 0; i < pointer; i++){
        this->header[i] = bytes[i];
    }

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            if (bitCount == 24) {
                uchar b = bytes[pointer];
                uchar g = bytes[pointer + 1];
                uchar r = bytes[pointer + 2];
                this->r[i][j] = r;
                this->g[i][j] = g;
                this->b[i][j] = b;
                pointer += 3;
            } else if (bitCount == 8) {
                uchar b = bytes[pointer];
                uchar g = bytes[pointer];
                uchar r = bytes[pointer];
                this->r[i][j] = r;
                this->g[i][j] = g;
                this->b[i][j] = b;
                pointer += 1;
            }
        }
    }
}