#include <stdio.h>
#include <stdlib.h> // For free

char *my_itoa(int num);

int main() {
    int test_num1 = 12345;
    int test_num2 = -6789;
    int test_num3 = 0;

    char *str1 = my_itoa(test_num1);
    char *str2 = my_itoa(test_num2);
    char *str3 = my_itoa(test_num3);

    if (str1 && str2 && str3) {
        printf("Integer: %d -> String: \"%s\"\n", test_num1, str1);
        printf("Integer: %d -> String: \"%s\"\n", test_num2, str2);
        printf("Integer: %d -> String: \"%s\"\n", test_num3, str3);
    }

    // Free allocated memory
    free(str1);
    free(str2);
    free(str3);

    printf("Press Enter to exit...");
    getchar(); // Wait for user input

    return 0;
}
