#include "pbm.hpp"

PBM::PBM(std::string filename) : IMAGE(filename){
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

    this->height = height;
    this->width = width;
    this->bitCount = 1;
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
    if (data[0] == 'P' && data[1] == '1') {
        // ASCII
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
            uchar gray;
            if (nextInt(data, size, &pointer) == 0)
                gray = 255;
            else
                gray = 0;
            pixels[i][j] = gray;
            }
        }
    } else if (data[0] == 'P' && data[1] == '4') {
        // BINARY
        int bitPos = 7;
        for (int i = 0; i < height; i++) {
            if (bitPos != 7) {
                bitPos = 7;
                pointer += 1;
            }
            for (int j = 0; j < width; j++) {
                uchar byte = data[pointer];
                pixels[i][j] = (byte & (1 << bitPos)) ? 0 : 255;
                if (bitPos == 0) {
                    bitPos = 7;
                    pointer += 1;
                } else {
                    bitPos--;
                }
            }
        }
    }
}
