#include <stdio.h>
#include <stdlib.h>

int getPositiveNumber(char *msg);

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {
    int choice;
    int valid;

    do {
        valid = 0;

        printf("%s\n", menuTitle);

        for (int i = 0; i < menuSize; i++) {
            printf("%d. %s\n", i + 1, menuOptions[i]);
        }

        printf("%s\n", inputMsg);
        choice = getPositiveNumber("");

        if (choice >= 1 && choice <= menuSize) {
            valid = 1;
        } else {
            printf("Invalid selection. Please try again:\n");
        }

    } while (!valid);

    return choice;
}

int getPositiveNumber(char *msg) {
    int number;
    char term;
    do {
        printf("%s", msg);
        fflush(stdout);
        if(scanf("%d%c", &number, &term) != 2 || term != '\n' || number <= 0) {
            printf("You must enter a positive integer. Please try again.\n");
            while(getchar() != '\n');
        } else {
            break;
        }
    } while (1);

    return number;
}

int main() {
    char *title = "Main Menu";
    char *options[] = {"Option 1", "Option 2", "Option 3", "Exit"};
    int menuSize = sizeof(options) / sizeof(options[0]);
    char *inputMsg = "Please enter your choice: ";

    int selection = showMenu(title, options, menuSize, inputMsg);
    printf("You selected: %d\n", selection);

    return 0;
}

