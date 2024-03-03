#include <stdio.h>

int main() {
    int num1, num2, num3;
    char filename[100];
    FILE *outFile;

    printf("This program takes three numbers separated by semicolons and finds the middle value.\n");
    printf("Please enter three numbers separated by semicolons: ");

    while (1) {
        if (scanf("%d;%d;%d", &num1, &num2, &num3) != 3) {
            printf("Invalid input. Please provide three numbers separated by semicolons: ");
            while(getchar() != '\n');
            continue;
        }
        break;
    }

    int middle;
    if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3)) {
        middle = num1;
    } else if ((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3)) {
        middle = num2;
    } else {
        middle = num3;
    }

    printf("Enter the name of the output file (must end with .txt): ");
    while (1) {
        scanf("%99s", filename);

        int len = 0;
        while (filename[len] != '\0') {
            len++;
        }

        if (len > 4 && filename[len-4] == '.' && filename[len-3] == 't' && filename[len-2] == 'x' && filename[len-1] == 't') {
            break;
        } else {
            printf("Invalid filename. Please provide a filename that ends with .txt: ");
        }
    }

    outFile = fopen(filename, "w");
    if (outFile) {
        fprintf(outFile, "Middle number: %d\n", middle);
        fclose(outFile);
        printf("Result successfully written to %s\n", filename);
    } else {
        printf("Error writing to file %s\n", filename);
    }

    return 0;
}
