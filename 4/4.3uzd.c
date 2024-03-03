#include <stdio.h>

int main() {

    int a, b, c;

    printf("This is a program where the user enters three non-negative integers (a, b, c).\nThe program must print the cth number fc, where fc=fc-1+fc-2 and f0 = a and f1 = b.\nIf a=0 and b=1, fc is the cth number of the famous Fibonacci sequence.\n\n");
    printf("Enter three non-negative integers (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);
    printf("The numbers have been entered in successfully!\n");

    if (c == 0) {
        printf("The %dth number in the sequence is: %d\n", c, a);
        return 0;
    } else if (c == 1) {
        printf("The %dth number in the sequence is: %d\n", c, b);
        return 0;
    }

    int prev = a, current = b, next;
    for (int i = 2; i <= c; i++) {
        next = prev + current;
        prev = current;
        current = next;
    }

    printf("The %dth number in the sequence is: %d\n", c, current);
    return 0;
}
