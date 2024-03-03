#include <assert.h>
#include <stdio.h>

size_t custom_strlen(const char *str) {
    size_t length = 0;
    while (str[length]) {
        length++;
    }
    return length;
}

void test_strlen() {
    assert(custom_strlen("") == 0); // Test for empty string
    assert(custom_strlen("hello") == 5); // Test for a normal string
    // Add more tests as needed
}

int main() {
    test_strlen();
    printf("All strlen tests passed!\n");
    return 0;
}
