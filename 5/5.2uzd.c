#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

int main()
{
    int a, b, c;
    int array[ARRAY_SIZE];
    int range, randomValue;

    srand(time(NULL));

    printf("This program will generate an array of random numbers within your specified range.\n");

    do
    {
        printf("\nEnter the lower limit (a) of the range: ");
        scanf("%d", &a);
        printf("Enter the upper limit (b) of the range: ");
        scanf("%d", &b);
        if (a >= b)
        {
            printf("The lower limit should be less than the upper limit. Please try again.\n");
        }
    } while (a >= b);

    do
    {
        printf("Enter how many random numbers between %d and %d you'd like to generate (up to 1000): ", a, b);
        scanf("%d", &c);
        if (c <= 0 || c > 1000)
        {
            printf("You can only generate between 1 and 1000 numbers. Please try again.\n");
        }
    } while (c <= 0 || c > 1000);


    range = b - a + 1;
    for (int i = 0; i < c; i++)
    {
        randomValue = a + (rand() % range);
        array[i] = randomValue;
    }

    printf("\nGenerated numbers:\n");
    for (int i = 0; i < c; i++)
    {
        printf("%d ", array[i]);
        if ((i+1) % 10 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}
