#include <stdio.h>

int char_is_digit(char c);
int str_is_digit(char *str);

int main() {
    // Test char_is_digit
    char test_char = '5';
    printf("Is '%c' a digit? %d\n", test_char, char_is_digit(test_char));

    test_char = 'a';
    printf("Is '%c' a digit? %d\n", test_char, char_is_digit(test_char));

    // Test str_is_digit
    char test_str1[] = "12345";
    printf("Is \"%s\" a digit string? %d\n", test_str1, str_is_digit(test_str1));

    char test_str2[] = "123a5";
    printf("Is \"%s\" a digit string? %d\n", test_str2, str_is_digit(test_str2));

    printf("Press Enter to exit...");
    getchar(); // Wait for user input
    return 0;
}
