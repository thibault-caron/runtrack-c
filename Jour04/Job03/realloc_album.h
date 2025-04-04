#ifndef REALLOC_ALBUM_H
#define REALLOC_ALBUM_H

#include "../Job02/print_album.h"

/**
 * realloc_album - Reallocates memory for an array of albums to a new size.
 *
 * @albums: Pointer to the original array of albums.
 * @current_size: The current size of the array.
 * @new_size: The desired new size of the array.
 *
 * This function allocates a new array with the requested size,
 * copies the content from the original array (up to min(current_size, new_size)),
 * and then frees the original array.
 *
 * Return:
 *   A pointer to the newly allocated array, or NULL if allocation fails.
 */
album *realloc_album(album *albums, size_t current_size, size_t new_size);

#endif
