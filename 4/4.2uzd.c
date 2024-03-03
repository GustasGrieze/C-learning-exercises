#include <stdio.h>

int main()
{

    int a, b, c;
    printf("This program asks you to enter three integers (a, b, c).\nIt then prints all positive integers from of the interval (a; b] that are divisible by the number c with a remainder of 1.\n\n");
    printf("Please enter three integers (a, b, c)\n");
    scanf("%d %d %d", &a, &b, &c);


    // Check if c is zero
    if (c == 0) {
        printf("c cannot be zero!\n");
        return 0;
    }
    printf("The numbers have been entered successfully!!\n");

    printf("Numbers in the interval (%d; %d] that are positive and divisible by %d with a remainder of 1 are:\n", a, b, c);


    for (int i = a + 1; i <= b; i++) {
        if (i % c == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}
