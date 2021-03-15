#include "loader.hpp"

char* fileLoader(std::string filename, int* filesize){
    std::ifstream image_file;
    image_file.open(filename, std::ios::in | std::ios::binary);
    if (image_file.is_open()) {
        // retrieving file size
        image_file.seekg(0, std::ios::end);
        std::streampos size = image_file.tellg();
        image_file.seekg(0, std::ios::beg);

        char* bytes = new char[size];
        image_file.read(bytes, size);
        image_file.close();
        *filesize = size;
        return bytes;
    }
    return NULL;
}
