/**
 * power - Raises a base to the power of an exponent.
 * @base: The base integer.
 * @exponent: The exponent integer.
 *
 * Return: The result of base^exponent. If exponent < 0, returns 0.
 */
int power(int base, int exponent) {
    if (exponent < 0) {
        return 0; // Negative exponents are not handled
    }

    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}
