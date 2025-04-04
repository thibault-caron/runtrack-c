#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "music_list.h"

/**
 * string_compare - Compare two strings.
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: < 0 if s1 < s2, > 0 if s1 > s2, 0 if s1 == s2
 */
static int string_compare(const char *s1, const char *s2) {
    if (!s1 && !s2) return 0;
    if (!s1) return -1;
    if (!s2) return 1;
    
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    
    return ((unsigned char)*s1) - ((unsigned char)*s2);
}

/**
 * main - Entry point of the program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        write(2, "Usage: music <filename> <sort_criterion>\n", 41);
        return 1;
    }
    
    const char *filename = argv[1];
    const char *sort_criterion = argv[2];
    
    // Validate sort criterion
    if (string_compare(sort_criterion, "artist") != 0 &&
        string_compare(sort_criterion, "title") != 0 &&
        string_compare(sort_criterion, "year") != 0) {
        write(2, "Sort method does not exist.\n", 28);
        return 1;
    }
    
    // Read albums from the file
    album_node *album_list = NULL;
    if (!read_albums_from_file(filename, &album_list)) {
        // Error message already printed by read_albums_from_file
        return 1;
    }
    
    // Sort the album list
    if (!sort_album_list(&album_list, sort_criterion)) {
        write(2, "Sort method does not exist.\n", 28);
        free_album_list(album_list);
        return 1;
    }
    
    // Print the sorted album list
    print_album_list(album_list);
    
    // Free the album list
    free_album_list(album_list);
    
    return 0;
}
