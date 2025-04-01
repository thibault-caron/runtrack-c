#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void array_clone(char **strs, int n) {
    char **clone = malloc(n * sizeof(char *));
    if (clone == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        clone[i] = malloc((strlen(strs[i]) + 1) * sizeof(char));
        strcpy(clone[i], strs[i]);
        printf("%s\n", clone[i]);
        free(clone[i]);
    }
    free(clone);
}

int main() {
    char *strs[] = {"Hello", "World", "!"};
    int n = sizeof(strs) / sizeof(strs[0]);
    array_clone(strs, n);
    printf("Press Enter to exit...");
    getchar(); // Wait for user input
    return 0;
}