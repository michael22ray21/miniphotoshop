#include "loader.hpp"
#include "../structure/image.hpp"

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
