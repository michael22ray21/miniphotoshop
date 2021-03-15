#include "image.hpp"

IMAGE::~IMAGE(){
    for (int i = 0; i < this->height; i++) {
        free(this->pixels[i]);
    }
    free(this->pixels);
};
