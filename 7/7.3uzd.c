#include <stdio.h>
#include <stdlib.h>

int getPositiveNumber(char *msg) {
    int number;
    char input[50];
    int conversionStatus;

    do {
        printf("%s", msg);
        fgets(input, 50, stdin);
        conversionStatus = sscanf(input, "%d", &number);
    } while (conversionStatus != 1 || number <= 0);

    return number;


}

int main() {
    int positiveNumber = getPositiveNumber("Please enter a positive number: ");
    printf("You entered: %d\n", positiveNumber);
    return 0;
}

