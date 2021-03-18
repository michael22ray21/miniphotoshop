#include "pgm.hpp"

PGM::PGM(std::string filename) : IMAGE(filename){
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
    this->bitCount = 8;
    this->depth = 1;
    this->fileSize = size;
    this->pixels = (uchar**) malloc(height*sizeof(uchar*));
    for (int i = 0; i < height; i++){
        this->pixels[i] = (uchar*) malloc(width*sizeof(uchar));
    }

    this->header = (char*) malloc(sizeof(char)*(pointer));
    this->headSize = pointer;

    for(int i = 0; i < pointer; i++){
        this->header[i] = data[i];
    }

    if (data[0] == 'P' && data[1] == '2') {
        // ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                // uchar gray = (int) ((nextInt(data, size, &pointer) * 1.0 / maxValue) * 255) & 0xFF;
                uchar gray = nextInt(data, size, &pointer);
                pixels[i][j] = gray;
            }
        }
    } else if (data[0] == 'P' && data[1] == '5') {
        // BINARY
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                uchar gray = data[pointer];
                pixels[i][j] = gray;
                pointer += 1;
            }
        }
    }
}