#include <stdio.h>
#include <stdlib.h> // For free

char *my_strdup(const char *src);

int main() {
    char source[] = "Hello, world!";
    char *duplicate = my_strdup(source);

    if (duplicate == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Source: %s\n", source);
    printf("Duplicate: %s\n", duplicate);

    free(duplicate); // Free the allocated memory
    printf("Press Enter to exit...");
    getchar(); // Wait for user input

    return 0;
}
