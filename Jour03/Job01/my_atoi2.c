/**
 * my_atoi - Converts all digits in a string to an integer (ignores non-digits).
 * @str: The input string to convert.
 *
 * Return: The integer value of all digits in the string.
 */
int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;

    // Skip leading whitespaces
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f' || *str == '\v') {
        str++;
    }

    // Check for optional sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Parse all digits in the string, ignoring non-digits
    // in ascii '0' to '9' are 48 to 57
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        }
        str++;
    }

    return result * sign;
}
