#include <stdio.h>

int main()
{
    int s, n;

    printf("This program finds pairs of numbers in an array whose product equals a given value.\n");

    printf("\nEnter the desired product (s): ");
    scanf("%d", &s);

    do
    {
        printf("Enter how many positive numbers you'd like to provide (n): ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("Please enter a positive value for 'n'.\n");
        }
    } while (n <= 0);

    int x[n];
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Enter a positive value for x[%d]: ", i);
            scanf("%d", &x[i]);
            if (x[i] <= 0)
            {
                printf("The value should be positive. Please try again.\n");
            }
        } while (x[i] <= 0);
    }

    printf("\nChecking pairs whose product equals %d...\n", s);

    int found = 0;
    for (int i = 0; i < n; i++)
        {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] * x[j] == s)
            {
                printf("Pair found: (%d, %d)\n", x[i], x[j]);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("No pairs found whose product equals %d.\n", s);
    }

    return 0;
}
