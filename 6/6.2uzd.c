#include <stdio.h>

int main() {
    char filename[100] = "in.txt";
    char number[100];
    int intPart, fracPart;
    double realValue;
    int validInput;
    FILE *inFile;

    printf("This program reads a real number from a data file.\n");

    while (1) {
        validInput = 1;

        inFile = fopen(filename, "r");
        if (inFile == NULL) {
            printf("Unable to open file: %s. Please provide another file name: ", filename);
            scanf("%99s", filename);
            continue;
        }

        if (fgets(number, sizeof(number), inFile) == NULL) {
            printf("Unable to read data from file: %s. Please provide another file name: ", filename);
            scanf("%99s", filename);
            fclose(inFile);
            continue;
        }
        fclose(inFile);

        if (sscanf(number, "%d,%d", &intPart, &fracPart) != 2) {
            validInput = 0;
        }

        if (fracPart < 0 || fracPart >= 1000) {
            validInput = 0;
        }

        realValue = intPart + fracPart / 1000.0;
        if (realValue < 10 || realValue > 1000) {
            validInput = 0;
        }

        if (validInput) {
            int length = 0;
            while (number[length] != '\0' && number[length] != '\n') {
                length++;
            }
            length--; //remove the comma
            printf("Data successfully scanned. Number length: %d\n", length);
            break;
        } else {
            printf("Invalid number in file: %s. Please provide another file name: ", filename);
            scanf("%99s", filename);
        }
    }

    return 0;
}
