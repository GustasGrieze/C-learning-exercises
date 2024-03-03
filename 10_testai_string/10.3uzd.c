#include <assert.h>
#include <stdio.h>
#include <string.h>

char *custom_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for ( ; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

void test_strncpy() {
    char dest[50];
    assert(custom_strncpy(dest, "hello", 5) == dest);
    assert(strcmp(dest, "hello") == 0);
}

int main() {
    test_strncpy();
    printf("All strncpy tests passed!\n");
    return 0;
}