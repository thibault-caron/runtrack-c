#include <stdio.h>
#include <stdlib.h>
#include "print_album.h"

#define INITIAL_BUFFER_SIZE 16
#define BUFFER_GROWTH 16
#define MAX_INPUT_SIZE 1024

/**
 * read_line - Reads a line from standard input and returns it as a dynamically allocated string.
 *
 * This function dynamically resizes the buffer as needed to accommodate the input.
 * The caller is responsible for freeing the returned string.
 *
 * Return:
 *   A pointer to the dynamically allocated string containing the input.
 *   Returns NULL if memory allocation fails or if input is too long.
 */
char *read_line() {
    size_t size = INITIAL_BUFFER_SIZE;
    size_t len = 0;
    char *buffer = malloc(size * sizeof(char));

    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory for input buffer.\n");
        return NULL;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Check for input size limit
        if (len >= MAX_INPUT_SIZE - 1) {
            fprintf(stderr, "Input too long (max %d characters).\n", MAX_INPUT_SIZE - 1);
            free(buffer);
            return NULL;
        }

        // Resize buffer if necessary
        if (len + 1 >= size) {
            size += BUFFER_GROWTH;
            char *new_buffer = realloc(buffer, size * sizeof(char));
            if (!new_buffer) {
                fprintf(stderr, "Failed to resize input buffer.\n");
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }

        buffer[len++] = ch;
    }

    // Handle empty input
    if (len == 0 && ch == '\n') {
        free(buffer);
        buffer = malloc(sizeof(char));
        if (!buffer) {
            fprintf(stderr, "Failed to allocate memory for empty string.\n");
            return NULL;
        }
        buffer[0] = '\0';
        return buffer;
    }

    // Null-terminate the string
    buffer[len] = '\0';

    // Resize buffer to exact size
    char *final_buffer = realloc(buffer, (len + 1) * sizeof(char));
    if (final_buffer) {
        buffer = final_buffer;
    }

    return buffer;
}

/**
 * validate_year - Validates that the input year is within a reasonable range.
 *
 * @year: The year to validate.
 *
 * Return:
 *   1 if valid, 0 if invalid.
 */
int validate_year(int year) {
    const int min_year = 1850;
    const int max_year = 2100;
    
    return (year >= min_year && year <= max_year);
}

/**
 * main - Entry point of the program.
 *
 * This program allows the user to input details of an album (title, artist, and year),
 * prints the album details, and frees the allocated memory. The user can repeat this
 * process until they choose to exit.
 *
 * Return:
 *   0 on success, 1 on error.
 */
int main() {
    album a;
    char choice;
    int scan_result;

    init_album(&a);

    do {
        printf("Enter album title: ");
        a.title = read_line();
        if (!a.title) {
            cleanup_album(&a);
            return 1;
        }

        printf("Enter artist name: ");
        a.artist = read_line();
        if (!a.artist) {
            cleanup_album(&a);
            return 1;
        }

        printf("Enter release year: ");
        scan_result = scanf("%d", &a.year);
        getchar(); // Consume the leftover newline character

        // Validate year input
        if (scan_result != 1 || !validate_year(a.year)) {
            fprintf(stderr, "Invalid year. Please enter a year between 1500 and 2100.\n");
            cleanup_album(&a);
            return 1;
        }

        print_album(&a);
        cleanup_album(&a);

        printf("Do you want to enter another album? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume the leftover newline character

    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}
