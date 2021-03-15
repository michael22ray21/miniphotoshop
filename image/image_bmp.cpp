#include <iostream>
#include "utils.cpp"

class ImagePBM
{
private:
    unsigned short int header;
    unsigned int size;
    unsigned int image_head;
    unsigned short int width, height, bpp;
    unsigned int** pixels;
public:
    ImagePBM(const char* filename);
    ~ImagePBM();
};

ImagePBM::ImagePBM(const char* filename){
    FILE *fp;
    int i, j;
    unsigned short int M, N;
    if((fp=fopen(filename, "rb"))==NULL)
    {
        printf("Arsip tidak ada");
        exit(0);
    }
    fread(&M, sizeof(unsigned short int), 1, fp); /* baca tinggi citra */
    fread(&N, sizeof(unsigned short int), 1, fp); /* baca lebar citra */
    pixels = alokasi(M, N, bpp) /* alokasi memori matriks untuk citra f */
    if(f==NULL)
    { 
        printf("Memori tidak cukup");
        exit(0);
    }
    /* baca data citra baris demi baris */
    for(i=0; i<M; i++)
    {
    /* baca data citra baris ke-i */
    fread(f[i], sizeof(citraunsigned char), N, fp);
    }
    close(fp);
}

ImagePBM::~ImagePBM()
{
}
