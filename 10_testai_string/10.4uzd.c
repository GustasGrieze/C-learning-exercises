#include <assert.h>
#include <stdio.h>

char *custom_strchr(const char *str, int c) {
    while (*str != c) {
        if (!*str++) {
            return NULL;
        }
    }
    return (char *)str;
}

void test_strchr() {
    const char *str = "hello";
    assert(custom_strchr(str, 'e') == str + 1);
    assert(custom_strchr(str, 'x') == NULL);
}

int main() {
    test_strchr();
    printf("All strchr tests passed!\n");
    return 0;
}
