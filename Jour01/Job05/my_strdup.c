#include <stdlib.h> // For malloc

int my_strlen(char *str);

char *my_strdup(const char *src) {
    int length = my_strlen((char *)src); // Get the length of the source string
    char *copy = (char *)malloc((length + 1) * sizeof(char)); // Allocate memory for the copy

    if (copy == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    for (int i = 0; i <= length; i++) {
        copy[i] = src[i]; // Copy each character, including the null terminator
    }

    return copy;
}
