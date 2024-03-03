#include <stdio.h>
#include <stdlib.h>

// Function to find the largest file
const char* findLargestFile(int argc, char *argv[]) {
    FILE *file;
    const char *largestFileName = NULL;
    long largestSize = -1;
    long fileSize;

    for (int i = 1; i < argc; i++) {
        file = fopen(argv[i], "rb");
        if (file == NULL) {
            printf("Could not open file %s\n", argv[i]);
            continue;
        }

        fseek(file, 0, SEEK_END);
        fileSize = ftell(file);
        fclose(file);

        if (fileSize > largestSize) {
            largestSize = fileSize;
            largestFileName = argv[i];
        }
    }

    return largestFileName;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    const char *largestFile = findLargestFile(argc, argv);
    if (largestFile != NULL) {
        printf("The largest file is: %s\n", largestFile);
    } else {
        printf("No valid files were provided or could be opened.\n");
    }

    return 0;
}

