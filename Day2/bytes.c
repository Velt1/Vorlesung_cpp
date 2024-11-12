#include <stdio.h>

int main() {
    char a;
    char b;
    printf("Size of a: %zu bytes\n", sizeof(a));
    printf("Size of b: %zu bytes\n", sizeof(b));
    printf("Total size of a and b: %zu bytes\n", sizeof(a) + sizeof(b));
    return 0;
}
