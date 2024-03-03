#include <assert.h>
#include <stdio.h>
#include <string.h>

char *custom_strcpy(char *dest, const char *src) {
    char *start = dest;
    while ((*dest++ = *src++));
    return start;
}

void test_strcpy() {
    char dest[50];
    assert(custom_strcpy(dest, "hello") == dest);
    assert(strcmp(dest, "hello") == 0);
}

int main() {
    test_strcpy();
    printf("All strcpy tests passed!\n");
    return 0;
}