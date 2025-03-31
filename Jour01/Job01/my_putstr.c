#include "my_functions.h"

void my_putstr(char *str) {
    while (*str) {
        my_putchar(*str);
        str++;
    }
}

