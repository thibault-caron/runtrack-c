/**
 * factorial - Calculates the factorial of a non-negative integer.
 * @n: The integer to calculate the factorial for.
 *
 * Return: The factorial of n. If n < 0, returns 0.
 */
int factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }

    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}
