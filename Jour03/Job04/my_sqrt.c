/**
 * my_sqrt - Calculates the square root of an integer.
 * @n: The integer to calculate the square root for.
 *
 * Return: The square root of n if it is an integer, otherwise 0.
 */
int my_sqrt(int n) {
    if (n < 0) {
        return 0; // Square root of negative numbers is not defined
    }

    for (int i = 0; i * i <= n; i++) {
        if (i * i == n) {
            return i;
        }
    }

    return 0;
}
