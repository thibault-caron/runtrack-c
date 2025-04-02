/**
 * my_atoi - Converts a string to an integer (ASCII to Integer).
 * @str: The input string to convert.
 *
 * Return: The integer value of the string.
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

    // Convert characters to integer
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        } else if (result != 0) {
            // Stop parsing if a non-digit is encountered after digits
            break;
        }
        str++;
    }

    return result * sign;
}
