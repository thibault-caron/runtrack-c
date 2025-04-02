#include <stdio.h>

int power(int base, int exponent);

int main() {
    int base = 2, exponent = 3;
    printf("%d^%d = %d\n", base, exponent, power(base, exponent));

    base = 5, exponent = 0;
    printf("%d^%d = %d\n", base, exponent, power(base, exponent));

    base = 3, exponent = -2;
    printf("%d^%d = %d\n", base, exponent, power(base, exponent));

    printf("Press Enter to exit...");
    getchar(); // Wait for user input
    return 0;
}