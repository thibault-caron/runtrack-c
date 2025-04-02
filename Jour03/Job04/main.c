#include <stdio.h>

int my_sqrt(int n);

int main() {
    int test_num1 = 16;
    int test_num2 = 25;
    int test_num3 = 10;
    int test_num4 = -4;

    printf("Square root of %d: %d\n", test_num1, my_sqrt(test_num1));
    printf("Square root of %d: %d\n", test_num2, my_sqrt(test_num2));
    printf("Square root of %d: %d\n", test_num3, my_sqrt(test_num3));
    printf("Square root of %d: %d\n", test_num4, my_sqrt(test_num4));

    printf("Press Enter to exit...");
    getchar(); // Wait for user input
    return 0;
}
