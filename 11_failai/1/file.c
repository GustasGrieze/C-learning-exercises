// file.c
#include "file.h"
#include <stdio.h>

void saveToFile(const char* filename, const int* array, size_t size) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) return;

    fwrite(&size, sizeof(size), 1, file);
    fwrite(array, sizeof(int), size, file);
    fclose(file);
}

int* loadFromFile(const char* filename, size_t* size) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) return NULL;

    fread(size, sizeof(*size), 1, file);
    int* array = (int*) malloc(*size * sizeof(int));
    fread(array, sizeof(int), *size, file);
    fclose(file);
    return array;
}
