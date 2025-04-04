#include <stdio.h>

int power(int base, int exponent);

int main() {
    int base, exponent;
    char choice;

    do {
        printf("Enter base: ");
        scanf("%d", &base);

        printf("Enter exponent: ");
        scanf("%d", &exponent);

        printf("%d^%d = %d\n", base, exponent, power(base, exponent));

        printf("Do you want to calculate another power? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any leftover newline character
    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}