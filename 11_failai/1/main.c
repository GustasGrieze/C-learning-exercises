// main.c
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100;  // Random numbers between 0 and 99
    }
}

void printArray(const int* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int arraysAreEqual(const int* arr1, const int* arr2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

int main() {
    const size_t SIZE = 10;
    int m1[SIZE];
    int* m2;
    size_t loadedSize;

    srand(time(NULL));  // Seed for random number generation

    fillArray(m1, SIZE);
    printArray(m1, SIZE);

    saveToFile("data.bin", m1, SIZE);

    m2 = loadFromFile("data.bin", &loadedSize);
    if (m2 != NULL) {
        printArray(m2, loadedSize);

        if (arraysAreEqual(m1, m2, SIZE)) {
            printf("all good\n");
        } else {
            printf("something's wrong\n");
        }

        free(m2);
    } else {
        printf("Error loading file\n");
    }

    return 0;
}
