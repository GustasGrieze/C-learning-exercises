#include <stdio.h>

int main()
{
    // apibrėžia masyvą, galinti sutalpinti 10 elementų, tame pačiame sakinyje inicializuodama juos nulinėmis reikšmėmis
    int el[10] = {0};

    // atspausdina visą masyvą į ekraną
    for(int i=0; i<10; i++)
    {
        printf("elementas nr %d. %d\n", i+1, el[i]);
    }

    // pačiam pirmam, ketvirtam ir dešimtam masyvo elementams priskiria reikšmes atitinkamai 1, 2 ir 3
    el[0] = 1;
    el[3] = 2;
    el[9] = 3;

    // ištrina iš masyvo trečią elementą
    for(int i = 2; i < 9; i++)
    {
        el[i] = el[i+1];
    }

    // įterpia į masyvą naują elementą su reikšme 4, taip, kad po įterpimo jis būtų septintas
    for(int i=9; i > 6; i--)
    {
        el[i] = el[i - 1];
    }
    el[6] = 4;

    // atspausdina visą masyvą į ekraną
    printf("Modified array: \n");
    for(int i=0; i<10; i++)
    {
        printf("elementas nr %d. %d\n", i+1, el[i]);
    }


    // paprašo vartotojo įvesti du skaičius (x ir y), ir masyvo elementui su indeksu x nustato naują reikšmę, lygią y
    int x, y;
    printf("\nPlease enter 2 numbers (x, y): ");
    scanf("%d %d", &x, &y);
    el[x] = y;

    // paprašo vartotojo įvesti vieną skaičių (x), ir ištrina iš masyvo elementą su indeksu x
    printf("\nPlease enter 1 number (x): ");
    scanf("%d", &x);
    for(int i = x; i < 9; i++)
    {
        el[i] = el[i+1];
    }
    el[9] = 0;

    //paprašo vartotoją įvesti du skaičius (x ir y), ir į masyvą įterpia naują elementą su reikšme y, taip, kad po įterpimo jo indeksas būtų x
    printf("\nPlease enter 2 numbers (x, y): ");
    scanf("%d %d", &x, &y);
    for(int i=9; i > x; i--)
    {
        el[i] = el[i - 1];
    }
    el[x] = y;

    // atspausdina visą masyvą į ekraną
    printf("Modified array: \n");
    for(int i=0; i<10; i++)
    {
        printf("elementas nr %d. %d\n", i+1, el[i]);
    }

    return 0;
}
