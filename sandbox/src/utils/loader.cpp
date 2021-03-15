#include "loader.hpp"

char* imageLoader(std::string filename){
    std::ifstream image_file;
    image_file.open(filename, std::ios::in | std::ios::binary);
    if (image_file.is_open()) {
        // retrieving file size
        image_file.seekg(0, std::ios::end);
        std::streampos size = image_file.tellg();
        image_file.seekg(0, std::ios::beg);

        char* data = new char[size];
        image_file.read(data, size);
        image_file.close();
        return data;
    }
    return NULL;
}

int getFileSize(std::string filename){
    std::ifstream image_file;
    image_file.open(filename, std::ios::in | std::ios::binary);
    if (image_file.is_open()) {
        // retrieving file size
        image_file.seekg(0, std::ios::end);
        std::streampos size = image_file.tellg();
        return size;
    }
    return NULL;
}
