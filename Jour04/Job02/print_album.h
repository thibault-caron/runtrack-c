#ifndef PRINT_ALBUM_H
#define PRINT_ALBUM_H

#include <stdlib.h>

/**
 * struct album - Represents an album with a title, artist, and release year.
 *
 * @title: The title of the album (dynamically allocated string).
 * @artist: The artist of the album (dynamically allocated string).
 * @year: The release year of the album.
 */
typedef struct {
    char *title;  // Dynamically allocated
    char *artist; // Dynamically allocated
    int year;
} album;

/**
 * print_album - Prints the details of an album.
 *
 * @a: Pointer to the album to print.
 */
void print_album(const album *a);

/**
 * free_album - Frees the dynamically allocated memory in an album struct.
 *
 * @a: Pointer to the album struct whose memory needs to be freed.
 */
void free_album(album *a);

/**
 * init_album - Initialize an album structure with default values.
 *
 * @a: Pointer to the album struct to initialize.
 */
void init_album(album *a);

/**
 * cleanup_album - Free memory and reinitialize an album.
 *
 * @a: Pointer to the album struct to clean up.
 */
void cleanup_album(album *a);

#endif
