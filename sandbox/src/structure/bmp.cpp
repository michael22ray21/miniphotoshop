#include "bmp.hpp"

BMP::BMP(std::string filename) : IMAGE(filename){
    std::ifstream image_file;
    char* data;
    int size;
    image_file.open(filename, std::ios::in | std::ios::binary);
    if (image_file.is_open()) {
        // retrieving file size
        image_file.seekg(0, std::ios::end);
        std::streampos filesize = image_file.tellg();
        image_file.seekg(0, std::ios::beg);

        data = new char[filesize];
        size = filesize;
        image_file.read(data, filesize);
        image_file.close();
    }
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
    this->depth = 3;
    this->rgbPixels = (uchar***) malloc(this->height*sizeof(uchar**));
    for (int i = 0; i < this->height; i++){
        this->rgbPixels[i] = (uchar**) malloc(this->width*sizeof(uchar*));
        for (int j = 0; j < this->width; j++){
            this->rgbPixels[i][j] = (uchar*) malloc(3*sizeof(uchar));
        }
    }

    this->header = (char*) malloc(sizeof(char)*(pointer));
    this->headSize = pointer;
    for(int i = 0; i < pointer; i++){
        this->header[i] = data[i];
    }

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            if (bitCount == 24) {
                this->rgbPixels[i][j][0] = data[pointer];
                this->rgbPixels[i][j][1] = data[pointer+1];
                this->rgbPixels[i][j][2] = data[pointer+2];
                pointer += 3;
            } else if (bitCount == 8) {
                this->rgbPixels[i][j][0] = data[pointer];
                this->rgbPixels[i][j][1] = data[pointer];
                this->rgbPixels[i][j][2] = data[pointer];
                pointer += 1;
            }
        }
    }
}