#include <stdio.h>
#include <string.h>

int main() {
    char email[100];
    char domain[100];
    int atPosition;
    int dotPosition;
    int valid;

    while (1) {
        valid = 1;
        atPosition = -1;
        dotPosition = -1;

        printf("Enter an email address: ");
        scanf("%99s", email);

        for (int i = 0; i < strlen(email); i++) {
            if (email[i] == '@') {
                if (atPosition == -1) {
                    atPosition = i;
                } else {
                    valid = 0;
                    break;
                }
            }

            if (email[i] == '.' && i > atPosition && atPosition != -1) {
                dotPosition = i;
                break;
            }
        }
        if (atPosition < 1 || dotPosition < atPosition + 2 || dotPosition == strlen(email) - 1) {
            valid = 0;
        }

        if (valid) {
            strcpy(domain, &email[atPosition + 1]);
            printf("Domain: %s\n", domain);

            FILE *fp = fopen("emails.txt", "a");
            if (fp != NULL) {
                fprintf(fp, "%s\n", email);
                fclose(fp);
            } else {
                printf("Failed to open the emails.txt file for writing.\n");
            }
            break;
        } else {
            printf("Invalid email address. Please try again.\n");
        }
    }

    return 0;
}
