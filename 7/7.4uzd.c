#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10
#define LOW 1
#define HIGH 100

void generateArray(int data[], int size, int low, int high) {
    srand((int)time(NULL));

    for (int i = 0; i < size; i++) {
        data[i] = rand() % (high - low + 1) + low;
    }
}

int main() {
    int myArray[SIZE];
    generateArray(myArray, SIZE, LOW, HIGH);
    printf("Values of the array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}
