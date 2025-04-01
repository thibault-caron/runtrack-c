#include <stdio.h>

char *my_strcpy(char *dest, const char *src);

int main() {
    char source[] = "Hello, world!";
    char destination[50]; // Ensure the destination has enough space

    my_strcpy(destination, source);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("Press Enter to exit...");
    getchar(); // Wait for user input

    return 0;
}
