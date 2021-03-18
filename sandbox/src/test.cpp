#include <iostream>
#include <fstream>
// #include "utils/loader.cpp"
#include "utils/writer.cpp"
#include "structure/structure.hpp"
#include "operations/operations.hpp"
#include "filter/filtering.hpp"
using namespace std;

void printBytes(IMAGE* source, int x, int y){
    int height = (y > source->height) ? source->height : y;
    int width = (x > source->width) ? source->width : x;
    int i, j;
    if (source->depth == 1){
        for(i = 0; i < height; i++){
            for(j = 0; j < width; j++){
                printf("%d\t", source->pixels[i][j]);
            }
            printf("\n");
        }
    } else {
        for(i = 0; i < height; i++){
            for(j = 0; j < width; j++){
                printf("[%d %d %d]", 
                source->rgbPixels[i][j][0],
                source->rgbPixels[i][j][1],
                source->rgbPixels[i][j][2]);
            }
            printf("\n");
        }
    }
}

int main(){
    PGM pbm = PGM("../images/barbara.ascii.pgm");
    printf("File size : %d\nHeight : %d\nWidth : %d\nBits per Pixel : %d\n", 
    pbm.fileSize, pbm.height, pbm.width, pbm.bitCount);
    int** hist = createHistogramDistribution(&pbm);
    printBytes(&pbm, 5, 5);
    // applyFilterConvolutionStrategy(&pbm, loadKernel("gaussian7"));
    applyHistogramEqualization(&pbm);

    printf("\n");
    printBytes(&pbm, 5, 5);
    // writeRAW("test.raw", pbm);
    return 0;
}