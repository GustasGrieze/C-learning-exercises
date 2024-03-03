#include <assert.h>
#include <stdio.h>
#include <string.h>

void *custom_memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dest;
}

void test_memcpy() {
    char dest[50];
    const char src[50] = "hello";
    assert(custom_memcpy(dest, src, 5) == dest);
    assert(memcmp(dest, src, 5) == 0);
}

int main() {
    test_memcpy();
    printf("All memcpy tests passed!\n");
    return 0;
}
