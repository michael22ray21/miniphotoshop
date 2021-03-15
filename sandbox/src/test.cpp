#include <iostream>
#include <fstream>
#include "utils/loader.cpp"
#include "utils/writer.cpp"
#include "structure/bmp.cpp"
#include "structure/raw.cpp"
#include "structure/pbm.cpp"
#include "structure/pgm.cpp"
#include "structure/ppm.cpp"
using namespace std;

int main(){
    int size;
    char* bytes = fileLoader("../images/sample.raw", &size);
    RAW pbm = RAW(bytes, size);
    printf("File size : %d\nHeight : %d\nWidth : %d\nBits per Pixel : %d\n", pbm.fileSize, pbm.height, pbm.width, pbm.bitCount);
    // writeRAW("test.raw", pbm);
    return 0;
}