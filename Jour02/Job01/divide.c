#include <stdio.h>

int divide(int *value) {
    *value = *value / 2;
}

int main() {
    int number = 20;
    printf("The number %d\n", number);

    divide(&number);
    printf("The divided number is %d\n", number);
    printf("Press Enter to exit...");
    getchar(); // Wait for user input
    return 0;
}