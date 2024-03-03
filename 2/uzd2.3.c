#include <stdio.h>

int main()
{
    int value;
    printf("Iveskite skaiciu: ");
    scanf("%d", &value);
    printf("Skaicius yra %s", ((value % 2) == 0) ? "Lyginis" : "Nelyginis");
    return 0;
}
