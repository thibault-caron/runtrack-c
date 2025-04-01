#include <stdio.h>
#include <string.h>

void sort(char *str) {
    int i, j;
    char temp;
    int length = strlen(str);

    for (i=0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[] = "Hello world!";
    printf("Before sort: %s\n", str);
    sort(str);
    
    printf("After sort: %s\n", str);
    printf("Press Enter to exit...");
    getchar(); // Wait for user input

    return 0;
}