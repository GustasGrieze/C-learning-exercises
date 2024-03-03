// file.c
#include "file.h"
#include <stdio.h>

int saveCount = 0;
int loadCount = 0;

void saveArrayToFile(int array[], int size, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }

    fwrite(array, sizeof(int), size, file);
    fclose(file);
    saveCount++;
}

void loadArrayFromFile(int array[], int size, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Unable to open file for reading.\n");
        return;
    }

    fread(array, sizeof(int), size, file);
    fclose(file);
    loadCount++;
}
