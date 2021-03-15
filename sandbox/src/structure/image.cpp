#include "image.hpp"

IMAGE::IMAGE(std::string filename){};

IMAGE::IMAGE(const IMAGE &image){
    this->bitCount = image.bitCount;
    this->fileSize = image.fileSize;
    this->headSize = image.headSize;
    this->height = image.height;
    this->width = image.width;

    if (image.pixels == NULL){
        this->rgbPixels = (uchar***) malloc(image.height*sizeof(uchar**));
        for (int i = 0; i < image.height; i++){
            this->rgbPixels[i] = (uchar**) malloc(image.width*sizeof(uchar*));
            for (int j = 0; j < image.width; j++){
                this->rgbPixels[i][j] = (uchar*) malloc(3*sizeof(uchar));
            }
        }
        for (int i = 0; i < image.height; i++){
            for (int j = 0; j < image.width; j++){
                for (int k = 0; k < 3; k++){
                    this->rgbPixels[i][j][k] = image.rgbPixels[i][j][k];
                }
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
    if (this->pixels == NULL){
        for (int i = 0; i < this->height; i++){
            for (int j = 0; j < this->width; j++){
                free(this->rgbPixels[i][j]);
            }
            free(this->rgbPixels[i]);
        }
        free(this->rgbPixels);
    } else {
        for (int i = 0; i < this->height; i++) {
            free(this->pixels[i]);
        }
        free(this->pixels);
    }
};
