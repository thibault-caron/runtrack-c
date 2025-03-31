#include "my_functions.h"
#include <stdio.h> // Include for getchar()

int main() {
    my_putstr("Hello, world!\n");
    printf("Press Enter to exit...");
    getchar(); // Wait for user input
    return 0;
}
