#include <stdio.h>
#include <stdlib.h>

#define SIZE 10          // data size
#define FREQ_SIZE 1000   // upper bound for values

// input:
//    user enters 10 non-negative integers
// output:
//    report how many times each unique value occured,
//    display values and occurence times in ascending order

int main() {

   int inputArray[SIZE] = { 0 };
   int frequency[FREQ_SIZE] = { 0 };
   int diffNums[SIZE] = { 0 };
   int num, counter = 0;

   printf("Programa paprasys jusu ivesti 10 neneigiamu skaiciu!\nJinai jums pasakys, kiek kartu kiekvienas skaicius pasikartojo!\nSkaicius ir ju pasikartojimo kieki jinai jums atvaizduos didejimo tvarka!\n\n");

   printf("Iveskite seka is 10 nariu(-io)\n");

   while(counter < SIZE){
      printf("Iveskite %d sekos elementa: ", 1 + counter);
      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num <= FREQ_SIZE)){
            inputArray[counter++] = num;
            printf("Skaicius buvo ivestas sekmingai!\n");
         } else {
            printf("Virsyti masyvo reziai [0; %d]\n", FREQ_SIZE);
         }
      } else {
         printf("Netinkama ivestis! Iveskite sveika, neneigiama skaiciu!\n");
         while(getchar() != '\n')
            ;
      }
   }


   printf("----Visi skaiciai buvo ivesti teisingai!----\n");

   // proceeding to computations...

   for(int i=0; i<SIZE; i++){
        frequency[ inputArray[i] ]++;
   }

   int flag;
   int diffNumsCounter = 0;

   for(int i=0; i<SIZE; i++){
      flag=1;
      for(int j=0; j<i; j++){
         if(inputArray[i] == inputArray[j]){
            flag=0;
         }
      }
      if(flag){
         diffNums[diffNumsCounter] = inputArray[i];
         diffNumsCounter++;
      }
   }

   int temp;

   for(int j=0; j<diffNumsCounter-1; j++){
      for(int i=0; i<diffNumsCounter-j-1; i++){
         if(diffNums[i] > diffNums[i+1]){
            temp = diffNums[i];
            diffNums[i] = diffNums[i+1];
            diffNums[i+1] = temp;
         }
      }
   }

   printf("----Rezultatai tuoj bus atspausdinti!----\n");
   printf("Skaicius          Pasikartojimu daznis\n");
   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i] ] != 0 ){
         printf("       %d......................... %d\n", diffNums[i], frequency[diffNums[i]]);
      }
   }

   return 0;
}
