#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    printf("Iveskite 3 realiuosius skaicius: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("Pirmo reiskinio atsakymas: %f\n", x + 4 * y + pow(z, 3));
    printf("Antro reiskinio atsakymas: %f", (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3));

    return 0;
}
