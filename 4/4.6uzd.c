#include <stdio.h>

int main() {
    int num, maxNum = 0, maxDigits = 0;
    printf("This is a program where the user enters a sequence of positive numbers, the end of which is marked by the first negative value entered.\nThe program has find which number among the input has the most digits.\n\nPLEASE ENTER DIFFERENT LENGTH NUMBERS, IF NOT THE PROGRAM WILL PRINT THE FIRST LARGEST DIGIT NUMBER ENTERED!!!!!\n\n");
    printf("Enter a sequence of positive numbers (end with a negative number):\n");

    while(1)
    {
        scanf("%d", &num);

        if (num < 0) break;
        printf("The number has been entered successfully!\n");
        int count = 0;
        int tempNum = num;
        while (tempNum) {
            count++;
            tempNum /= 10;
        }

        if (count > maxDigits) {
            maxDigits = count;
            maxNum = num;
        }

    }

    printf("The number with the most digits is: %d\n", maxNum);
    return 0;
}
