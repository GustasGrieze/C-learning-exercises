#include <stdio.h>

int main() {
    char date[11];
    char weekDays[7][100];
    int year, month, day;

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%10s", date);

    if (sscanf(date, "%4d-%2d-%2d", &year, &month, &day) != 3) {
        printf("Incorrect date format.\n");
        return 1;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date.\n");
        return 1;
    }

    if (month < 3) {
        month += 12;
        year--;
    }
    int h = (day + 2*month + 3*(month + 1)/5 + year + year/4 - year/100 + year/400) % 7;

    FILE *fp = fopen("week.txt", "r");
    if (fp == NULL) {
        printf("Error opening week.txt.\n");
        return 1;
    }

    for (int i = 0; i < 7; i++) {
        fgets(weekDays[i], sizeof(weekDays[i]), fp);
        int len = 0;
        while (weekDays[i][len] != '\0' && weekDays[i][len] != '\n') {
            len++;
        }
        weekDays[i][len] = '\0';
    }
    fclose(fp);

    printf("The day is: %s\n", weekDays[h]);

    return 0;
}
