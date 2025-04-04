#include <stdlib.h>
#include "realloc_album.h"

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
album *realloc_album(album *albums, size_t current_size, size_t new_size) {
    // Handle special cases
    if (new_size == 0) {
        free(albums);
        return NULL;
    }
    
    if (albums == NULL) {
        return malloc(new_size * sizeof(album));
    }
    
    // Allocate new memory
    album *new_albums = malloc(new_size * sizeof(album));
    if (new_albums == NULL) {
        return NULL; // Return NULL if allocation fails
    }
    
    // Determine how many elements to copy
    size_t copy_size = (current_size < new_size) ? current_size : new_size;
    
    // Copy elements from old array to new array
    for (size_t i = 0; i < copy_size; i++) {
        // Initialize the album structure
        new_albums[i].title = NULL;
        new_albums[i].artist = NULL;
        new_albums[i].year = 0;
        
        // Copy title if exists
        if (albums[i].title) {
            size_t title_len = 0;
            const char *title_ptr = albums[i].title;
            while (*title_ptr++) title_len++; // Calculate string length
            
            new_albums[i].title = malloc((title_len + 1) * sizeof(char));
            if (new_albums[i].title) {
                char *dst = new_albums[i].title;
                const char *src = albums[i].title;
                while ((*dst++ = *src++)); // Copy string including null terminator
            }
        }
        
        // Copy artist if exists
        if (albums[i].artist) {
            size_t artist_len = 0;
            const char *artist_ptr = albums[i].artist;
            while (*artist_ptr++) artist_len++; // Calculate string length
            
            new_albums[i].artist = malloc((artist_len + 1) * sizeof(char));
            if (new_albums[i].artist) {
                char *dst = new_albums[i].artist;
                const char *src = albums[i].artist;
                while ((*dst++ = *src++)); // Copy string including null terminator
            }
        }
        
        // Copy year
        new_albums[i].year = albums[i].year;
    }
    
    // Initialize any new elements if enlarging the array
    for (size_t i = copy_size; i < new_size; i++) {
        new_albums[i].title = NULL;
        new_albums[i].artist = NULL;
        new_albums[i].year = 0;
    }
    
    // Free old array and its contents
    for (size_t i = 0; i < current_size; i++) {
        free(albums[i].title);
        free(albums[i].artist);
    }
    free(albums);
    
    return new_albums;
}
