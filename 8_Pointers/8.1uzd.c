#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size, int low, int high) {
    if (size <= 0 || high < low) {
        return NULL;
    }

    int* newArray = (int*)malloc(size * sizeof(int));
    if (newArray == NULL) {
        return NULL;
    }

    for (int* ptr = newArray; ptr < newArray + size; ptr++) {
        *ptr = low + rand() % (high - low + 1);
    }

    return newArray;
}

int main() {
    srand((unsigned int)time(NULL));

    int size = 10;
    int low = 1;
    int high = 100;

    int* myArray = createArray(size, low, high);
    if (myArray != NULL) {
        printf("New array: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", *(myArray + i));
        }
        printf("\n");
    } else {
        printf("Failed to create the array.\n");
    }

    free(myArray);

    return 0;
}
