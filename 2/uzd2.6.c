#include <stdio.h>

int main()
{
    int x, y, z;
    int max = 0, min = 0;
    printf("Iveskite 3 realiuosius skaicius: ");
    scanf("%d %d %d", &x, &y, &z);
    max = x;

    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 123;
    y = 912;
    z = -82;
    printf("Turetu gautis Didziausia 912, maziausia -82\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = -800;
    y = 0;
    z = -98;
    printf("Turetu gautis Didziausia 0, maziausia -800\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 758;
    y = -7537;
    z = -753;
    printf("Turetu gautis Didziausia 758, maziausia -7537\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 874;
    y = 912;
    z = 444;
    printf("Turetu gautis Didziausia 912, maziausia 444\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 478;
    y = 4547;
    z = -487;
    printf("Turetu gautis Didziausia 4547, maziausia -487\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 156;
    y = 84169;
    z = -529;
    printf("Turetu gautis Didziausia 84169, maziausia -529\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = -725;
    y = 752;
    z = 4789;
    printf("Turetu gautis Didziausia 4789, maziausia -725\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 1251;
    y = -4985;
    z = 781;
    printf("Turetu gautis Didziausia 1251, maziausia -4985\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 48979;
    y = -554;
    z = -78415;
    printf("Turetu gautis Didziausia 48979, maziausia -78415\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 478;
    y = 269;
    z = 847;
    printf("Turetu gautis Didziausia 847, maziausia 269\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 9458;
    y = -724;
    z = -72;
    printf("Turetu gautis Didziausia 9458, maziausia -724\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 487;
    y = 927;
    z = -478;
    printf("Turetu gautis Didziausia 927, maziausia -478\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = -87;
    y = 1;
    z = 1;
    printf("Turetu gautis Didziausia 1, maziausia -87\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    x = 0;
    y = 0;
    z = 0;
    printf("Turetu gautis Didziausia 0, maziausia 0\n\n\n");
    max = ((x > y) && (x > z) ? (x) : ((y > z) ? (y) : (z)));
    min = ((x < y) && (x < z) ? (x) : ((y < z) ? (y) : (z)));
    printf("Didziausia reiksme: %d\n", max);
    printf("Maziausia reiksme: %d\n\n", min);

    return 0;
}
