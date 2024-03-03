#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    printf("This program will calculate the sum, average, smallest (minimum) and largest (maximum) values of the numbers entered\n");

    printf("Please enter how many integers you would like!\n");
    scanf("%d", &n);
    double numbers[n];

    printf("Now enter %d real numbers\n", n);

    for(int i=0; i<n; i++)
    {
        scanf("%lf", &numbers[i]);
    }

    printf("The numbers have been entered succesfully!\n");

    double sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += numbers[i];
    }

    double average = 0;
    average = (double)sum / n;


    double max = numbers[0];
    for(int i=0; i<n; i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }


    double min = numbers[0];
    for(int i=0; i<n; i++)
    {
        if(numbers[i] < min)
        {
            min = numbers[i];
        }
    }


    printf("The sum of the numbers is %lf\nThe average of the numbers is %lf\nThe largest number is %lf\nThe smallest number is %lf", sum, average, max, min);

    return 0;
}
