#include "ppm.hpp"

PPM::PPM(std::string filename) : IMAGE(filename){
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
    int pointer = 0;
    std::string signature = nextString(data, size, &pointer);
    int width = nextInt(data, size, &pointer);
    int height = nextInt(data, size, &pointer);
    int maxValue = nextInt(data, size, &pointer);


    this->height = height;
    this->width = width;
    this->bitCount = 24;
    this->fileSize = size;
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


    if (data[0] == 'P' && data[1] == '3') {
    //   ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (int k = 0; k < 3; k++){
                    this->rgbPixels[i][j][k] = (int) ((nextInt(data, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
                }
            }
        }
    } else if (data[0] == 'P' && data[1] == '6') {
    //   BINARY
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                this->rgbPixels[i][j][0] = data[pointer];
                this->rgbPixels[i][j][0] = data[pointer+1];
                this->rgbPixels[i][j][0] = data[pointer+2];
                pointer += 3;
            }
        }
    }
}