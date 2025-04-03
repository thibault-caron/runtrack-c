#include <stdio.h>
#include <stdlib.h>
#include "print_album.h"

/**
 * print_album - Prints the details of an album.
 *
 * @a: Pointer to the album to print.
 *
 * This function prints the album's title, artist, and release year
 * in the format: "Title" by "Artist" released in Year.
 */
void print_album(const album *a) {
    if (!a || !a->title || !a->artist) {
        fprintf(stderr, "Invalid album data.\n");
        return;
    }
    printf("\"%s\" by \"%s\" released in %d.\n", a->title, a->artist, a->year);
}

/**
 * free_album - Frees the dynamically allocated memory in an album struct.
 *
 * @a: Pointer to the album struct whose memory needs to be freed.
 *
 * This function frees the memory allocated for the `title` and `artist` fields
 * of the album struct. The struct itself is not freed.
 */
void free_album(album *a) {
    if (!a) return;
    
    if (a->title) {
        free(a->title);
        a->title = NULL;
    }
    
    if (a->artist) {
        free(a->artist);
        a->artist = NULL;
    }
}

/**
 * init_album - Initialize an album structure with default values.
 *
 * @a: Pointer to the album struct to initialize.
 */
void init_album(album *a) {
    if (!a) return;
    
    a->title = NULL;
    a->artist = NULL;
    a->year = 0;
}

/**
 * cleanup_album - Free memory and reinitialize an album.
 *
 * @a: Pointer to the album struct to clean up.
 */
void cleanup_album(album *a) {
    if (!a) return;
    
    free_album(a);
    init_album(a);
}
