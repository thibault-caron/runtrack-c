#include <stdio.h>
#include "manhattan.h"

int main() {
    point p1, p2;
    char choice;

    do {
        printf("Enter coordinates of the first point (x y): ");
        scanf("%d %d", &p1.x, &p1.y);

        printf("Enter coordinates of the second point (x y): ");
        scanf("%d %d", &p2.x, &p2.y);

        printf("Manhattan distance between (%d, %d) and (%d, %d): %d\n",
               p1.x, p1.y, p2.x, p2.y, manhattan(p1, p2));

        printf("Do you want to calculate another distance? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any leftover newline character
    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}