char *my_strcpy(char *dest, const char *src) {
    char *original_dest = dest;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
    return original_dest;
}
