#include <stdlib.h> // For malloc

/**
 * my_itoa - Converts an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A pointer to the newly allocated string representing the integer,
 *         or NULL if memory allocation fails.
 *
 * Note: The caller is responsible for freeing the allocated memory.
 */
char *my_itoa(int num) {
    int temp = num;
    int length = (num <= 0) ? 1 : 0; // Account for '-' sign or '0'
    char *str;
    int i;

    // Calculate the number of digits
    while (temp != 0) {
        temp /= 10;
        length++;
    }

    // Allocate memory for the string (+1 for null terminator)
    str = (char *)malloc((length + 1) * sizeof(char));  // sizeof(char) is 1 (byte) in C
    if (str == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    str[length] = '\0'; // Null-terminate the string

    // Handle negative numbers
    if (num < 0) {
        str[0] = '-';
        num = -num;
    }

    // Convert digits to characters
    i = length - 1;
    if (num == 0) {
        str[i] = '0';
    } else {
        while (num > 0) {
            str[i--] = (num % 10) + '0';
            num /= 10;
        }
    }

    return str;
}
