#include <stdio.h>
#include "manhattan.h"

/**
 * validate_input - Validates that the scanf operation succeeded.
 *
 * @result: The return value from scanf.
 * @expected: The expected number of successfully read items.
 *
 * Return:
 *   1 if valid, 0 if invalid.
 */
int validate_input(int result, int expected) {
    return (result == expected);
}

/**
 * main - Entry point of the program.
 *
 * This program calculates the Manhattan distance between two points
 * entered by the user. It repeatedly prompts the user for input until
 * they choose to exit.
 *
 * Return:
 *   0 on success, 1 on input error.
 */
int main() {
    point p1, p2;
    char choice;
    int scan_result;

    do {
        printf("Enter coordinates of the first point (x y): ");
        scan_result = scanf("%d %d", &p1.x, &p1.y);
        
        if (!validate_input(scan_result, 2)) {
            fprintf(stderr, "Invalid input for the first point. Please enter two integers.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        printf("Enter coordinates of the second point (x y): ");
        scan_result = scanf("%d %d", &p2.x, &p2.y);
        
        if (!validate_input(scan_result, 2)) {
            fprintf(stderr, "Invalid input for the second point. Please enter two integers.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        // Calculate and display the Manhattan distance
        int distance = manhattan(p1, p2);
        printf("Manhattan distance between (%d, %d) and (%d, %d): %d\n",
               p1.x, p1.y, p2.x, p2.y, distance);

        printf("Do you want to calculate another distance? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any leftover newline character
        
        // Clear the input buffer
        while (getchar() != '\n');
        
    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}