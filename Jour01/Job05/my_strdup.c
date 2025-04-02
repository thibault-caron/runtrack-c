#include <stdlib.h> // For malloc

int my_strlen(char *str);

/**
 * my_strdup - Duplicates a string by allocating memory for a copy.
 * @src: The source string to duplicate.
 *
 * Return: A pointer to the newly allocated copy of the string,
 *         or NULL if memory allocation fails.
 *
 * Note: The caller is responsible for freeing the allocated memory.
 */
char *my_strdup(const char *src) {
    int length = my_strlen((char *)src);
    char *copy = (char *)malloc((length + 1) * sizeof(char));

    if (copy == NULL) {
        return NULL;
    }

    for (int i = 0; i <= length; i++) {
        copy[i] = src[i];
    }

    return copy;
}
