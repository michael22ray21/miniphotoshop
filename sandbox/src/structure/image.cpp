#include "image.hpp"

IMAGE::IMAGE(std::string filename){};

IMAGE::IMAGE(const IMAGE &image){
    this->bitCount = image.bitCount;
    this->fileSize = image.fileSize;
    this->headSize = image.headSize;
    this->height = image.height;
    this->width = image.width;

    if (image.pixels == NULL){
        this->r = (uchar**) malloc(image.height*sizeof(uchar*));
        this->g = (uchar**) malloc(image.height*sizeof(uchar*));
        this->b = (uchar**) malloc(image.height*sizeof(uchar*));
        for (int i = 0; i < image.height; i++){
            this->r[i] = (uchar*) malloc(image.width*sizeof(uchar));
            this->g[i] = (uchar*) malloc(image.width*sizeof(uchar));
            this->b[i] = (uchar*) malloc(image.width*sizeof(uchar));
        }
        for (int i = 0; i < image.height; i++){
            for (int j = 0; j < image.width; j++){
                this->r[i][j] = image.r[i][j];
                this->g[i][j] = image.g[i][j];
                this->b[i][j] = image.b[i][j];
            }
        }
    } else {
        this->pixels = (uchar**) malloc(image.height*sizeof(uchar*));
        for (int i = 0; i < image.height; i++){
            this->pixels[i] = (uchar*) malloc(image.width*sizeof(uchar));
        }
        for (int i = 0; i < image.height; i++){
            for (int j = 0; j < image.width; j++){
                this->pixels[i][j] = image.pixels[i][j];
            }
        }
    }

    this->header = (char*) malloc(sizeof(char)*image.headSize);
    for (int i = 0; i < image.headSize; i++){
        this->header[i] = image.header[i];
    }
};

IMAGE::~IMAGE(){
    for (int i = 0; i < this->height; i++) {
        free(this->pixels[i]);
    }
    free(this->pixels);
};
