#include <stdio.h>

long getFileSize(char *fileName) {
    FILE *file = fopen(fileName, "rb");

    if (file == NULL) {
        return -1;
    }

    fseek(file, 0, SEEK_END);

    long size = ftell(file);

    fclose(file);

    return size;
}

int main() {
    char *fileName = "example.txt";
    long size = getFileSize(fileName);

    if (size != -1) {
        printf("The size of the file '%s' is %ld bytes.\n", fileName, size);
    } else {
        printf("Failed to determine the size of the file '%s'.\n", fileName);
    }

    return 0;
}
