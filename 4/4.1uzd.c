#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c = 0;
    int determinant = 0;
    double x1, x2 = 0;
    printf("This program takes in 3 integers and solves the equations ax^2+bx+c=0\n");
    printf("Please enter 3 integers\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("The integers have been successfully entered\n");
    determinant = (b*b) - (4 * a * c);
    if(determinant > 0)
    {
        x1 = (-b + sqrt(determinant)) / (2*a);
        x2 = (-b - sqrt(determinant)) / (2*a);
        printf("The integers %d %d %d have 2 solutions %lf %lf (D > 0)", a, b, c, x1, x2);
    }
    else if(determinant == 0)
    {
        x1 = (-b) / (2*a);
        printf("The integers %d %d %d have 1 solution %lf (D = 0)", a, b, c, x1);
    }
    else
    {
        printf("The integers %d %d %d don't have any real solutions (D < 0)", a, b, c);
    }

    return 0;
}
