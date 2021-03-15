#include <iostream>

void **alokasi(int M, int N, int UkuranElemen)
/* Mengalokasikan memori untuk matriks M x N. Setiap elemen matriks berukuran UkuranElemen byte */
{
    int i;
    void **larik = (void**)xalloc(M * sizeof(void *)); /* buat array M elemen */
    for (i=0; i<M; i++)
    larik[i] = (void*)xalloc(N * UkuranElemen);
    return larik;
}

void *xalloc(unsigned ukuran)
/* Mengalokasikan memori dan memeriksa apakah alokasi memori berhasil */
{
    void *p = malloc(ukuran);
    if (p==NULL)
    {
    printf("Memori tidak cukup untuk alokasi matriks");
    exit(0);
    }
    return p;
}
