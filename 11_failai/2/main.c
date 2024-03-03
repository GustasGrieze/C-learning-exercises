// main.c
#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main() {
    int m1[5], m2[5], m3[5];

    // Sugeneruojame masyvus m1, m2 ir m3 su atsitiktiniais duomenimis
    for (int i = 0; i < 5; i++) {
        m1[i] = rand();
        m2[i] = rand();
        m3[i] = rand();
    }

    // 1) Išsaugojame masyvą m1 į failą
    saveArrayToFile(m1, 5, "m1.dat");

    // 2) Į tą patį failą („ant viršaus“) išsaugome masyvą m3
    saveArrayToFile(m3, 5, "m1.dat");

    // 3) Užkrauname iš to failo masyvą m1
    loadArrayFromFile(m1, 5, "m1.dat");

    // 4) Išsaugome kitame faile masyvą m2
    saveArrayToFile(m2, 5, "m2.dat");

    // 5) Užkrauname iš to (kito) failo masyvą m3
    loadArrayFromFile(m3, 5, "m2.dat");

    // 6) Užkrauname iš pirmo (ankstesnio) failo masyvą m2
    loadArrayFromFile(m2, 5, "m1.dat");

    // Tikriname, ar skaitliukai saveCount ir loadCount yra lygūs 3
    if (saveCount == 3 && loadCount == 3) {
        printf("all good\n");
    } else {
        printf("something's wrong\n");
    }

    return 0;
}
