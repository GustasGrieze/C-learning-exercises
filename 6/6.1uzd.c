#include <stdio.h>

int main() {
    unsigned long long factorial = 1;
    int num, result;

    printf("This program calculates the factorial of a positive number.\n");

    printf("Please enter a positive number: ");
    result = scanf("%d", &num);
    while(getchar() != '\n');

    while (result != 1 || num < 0) {
        if (result != 1) {
            printf("Invalid input. Please enter a number.\n");
        } else if (num < 0) {
            printf("Invalid input. Number should be positive.\n");
        }

        printf("Please enter a positive number: ");
        result = scanf("%d", &num);
        while(getchar() != '\n');
    }

    printf("Data successfully scanned.\n");

    int i = 1;
    while(i <= num) {
        factorial *= i;
        i++;
    }

    printf("Factorial of %d is %llu\n", num, factorial);

    FILE *outFile = fopen("out.txt", "w");
    if (outFile) {
        fprintf(outFile, "Factorial of %d is %llu\n", num, factorial);
        fclose(outFile);
    } else {
        printf("Error writing to out.txt\n");
    }

    return 0;
}
