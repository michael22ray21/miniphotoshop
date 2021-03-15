#include "raw.hpp"
RAW::RAW(char* bytes, int size){
    int pointer = 0;
    int width = nextInt(bytes, size, &pointer);
    int height = nextInt(bytes, size, &pointer);

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

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        uchar gray = nextInt(bytes, size, &pointer);
        this->pixels[i][j] = gray;
      }
    }
};
