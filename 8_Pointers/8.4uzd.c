#include <stdio.h>

int splitData(int *originalArray, int originalSize, int firstPartSize, int **firstArray, int **secondArray) {
    if (originalArray == NULL || firstPartSize <= 0 || firstPartSize >= originalSize || *firstArray != NULL || *secondArray != NULL) {
        return -1;
    }

    *firstArray = (int*)malloc(firstPartSize * sizeof(int));
    if (*firstArray == NULL) {
        return -1;
    }

    *secondArray = (int*)malloc((originalSize - firstPartSize) * sizeof(int));
    if (*secondArray == NULL) {
        free(*firstArray);
        *firstArray = NULL;
        return -1;
    }


    for (int i = 0; i < firstPartSize; ++i) {
        (*firstArray)[i] = originalArray[i];
    }


    for (int i = 0; i < originalSize - firstPartSize; ++i) {
        (*secondArray)[i] = originalArray[i + firstPartSize];
    }

    return 0;
}

int main() {
    int originalArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]);
    int firstPartSize = 5;
    int *firstArray = NULL;
    int *secondArray = NULL;

    if (splitData(originalArray, originalSize, firstPartSize, &firstArray, &secondArray) == 0) {
        printf("First array: ");
        for (int i = 0; i < firstPartSize; i++) {
            printf("%d ", firstArray[i]);
        }
        printf("\nSecond array: ");
        for (int i = 0; i < originalSize - firstPartSize; i++) {
            printf("%d ", secondArray[i]);
        }
        printf("\n");
    } else {
        printf("Failed to split the array.\n");
    }

    free(firstArray);
    free(secondArray);

    return 0;
}

