#include <stdio.h>
#include "factorial.c"

int main() {
    int test_num;
    char choice;

    do {
        printf("Enter number: ");
        scanf("%d", &test_num);

        printf(" factorial of %d: %d\n", test_num, factorial(test_num));

        printf("Do you want to calculate another power? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any leftover newline character
    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}