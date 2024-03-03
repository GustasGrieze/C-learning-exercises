#include <stdio.h>

// Function to compute GCD of two numbers
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// Function to compute LCM of two numbers using their GCD
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    printf("This is a program where the user enters three natural numbers (a, b, c).\nThe program must print two numbers - the greatest common divisor (GCD) and least common multiple (GCM) of the 3 numbers (a, b, c)\n\n");
    int a, b, c;

    printf("Please enter three natural numbers (a, b, c)\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("The integers have been entered in successfully!\n");

    // Calculate GCD and LCM of the three numbers
    int gcdValue = gcd(a, gcd(b, c));
    int lcmValue = lcm(a, lcm(b, c));

    printf("GCD of %d, %d, and %d is: %d\n", a, b, c, gcdValue);
    printf("LCM of %d, %d, and %d is: %d\n", a, b, c, lcmValue);
    return 0;
}
