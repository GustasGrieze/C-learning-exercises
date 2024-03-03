#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Enter positive numbers one at a time. When you're done, enter a negative number to stop.\n");

    int numbers[1000];
    int count = 0;

    while (1)
        {
        printf("\nEnter a positive number (or negative to stop): ");
        int num;
        scanf("%d", &num);
        while (getchar() != '\n');

        if (num < 0)
        {
            printf("\nYou entered a negative number. Data collection stopped.\n");
            break;
        }
        else
        {
            numbers[count++] = num;
        }
    }

    printf("\nPrime numbers you've entered:\n");


    for (int i = 0; i < count; i++)
        {
        int currentNum = numbers[i];
        if (currentNum <= 1) continue;

        bool isPrime = true;
        for (int j = 2; j * j <= currentNum; j++)
            {
            if (currentNum % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            bool alreadyPrinted = false;
            for (int k = 0; k < i; k++)
            {
                if (numbers[k] == currentNum)
                {
                    alreadyPrinted = true;
                    break;
                }
            }

            if (!alreadyPrinted)
            {
                printf("%d ", currentNum);
            }
        }
    }
    return 0;
}
