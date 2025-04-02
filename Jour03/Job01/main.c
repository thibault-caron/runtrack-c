#include <stdio.h>

int my_atoi(const char *str);

int main() {
    char test_str1[] = "12345";
    char test_str2[] = "-6789";
    char test_str3[] = "   +42";
    char test_str4[] = "abc123bn4";

    printf("String: \"%s\" -> Integer: %d\n", test_str1, my_atoi(test_str1));
    printf("String: \"%s\" -> Integer: %d\n", test_str2, my_atoi(test_str2));
    printf("String: \"%s\" -> Integer: %d\n", test_str3, my_atoi(test_str3));
    printf("String: \"%s\" -> Integer: %d\n", test_str4, my_atoi(test_str4));

    printf("Press Enter to exit...");
    getchar(); // Wait for user input

    return 0;
}
