#include <stdio.h>

int getFactorial(int number);

int main() {
    int number, result;

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    result = getFactorial(number);

    if (result != 0) {
        printf("Factorial of %d is %d\n", number, result);
    } else {
        printf("Cannot compute the factorial of a negative number.\n");
    }

    return 0;
}

int getFactorial(int number) {
    if (number == 0) {
        return 1;
    } else if (number < 0) {
        return 0;
    } else {
        return number * getFactorial(number - 1);
    }
}
