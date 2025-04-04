#include <stdio.h>
#include <stdlib.h>
#include "../Job02/print_album.h"
#include "realloc_album.h"

/**
 * create_test_albums - Creates a test array of albums.
 *
 * @size: The size of the array to create.
 *
 * Return:
 *   A pointer to the newly created album array, or NULL if allocation fails.
 */
album *create_test_albums(size_t size) {
    album *albums = malloc(size * sizeof(album));
    if (!albums) {
        return NULL;
    }
    
    // Initialize all albums
    for (size_t i = 0; i < size; i++) {
        albums[i].title = NULL;
        albums[i].artist = NULL;
        albums[i].year = 0;
    }
    
    // Set values for some sample albums
    if (size > 0) {
        const char *title = "Master of Puppets";
        size_t len = 0;
        while (title[len]) len++;
        albums[0].title = malloc((len + 1) * sizeof(char));
        if (albums[0].title) {
            for (size_t j = 0; j <= len; j++) {
                albums[0].title[j] = title[j];
            }
        }
        
        const char *artist = "Metallica";
        len = 0;
        while (artist[len]) len++;
        albums[0].artist = malloc((len + 1) * sizeof(char));
        if (albums[0].artist) {
            for (size_t j = 0; j <= len; j++) {
                albums[0].artist[j] = artist[j];
            }
        }
        
        albums[0].year = 1986;
    }
    
    if (size > 1) {
        const char *title = "The Dark Side of the Moon";
        size_t len = 0;
        while (title[len]) len++;
        albums[1].title = malloc((len + 1) * sizeof(char));
        if (albums[1].title) {
            for (size_t j = 0; j <= len; j++) {
                albums[1].title[j] = title[j];
            }
        }
        
        const char *artist = "Pink Floyd";
        len = 0;
        while (artist[len]) len++;
        albums[1].artist = malloc((len + 1) * sizeof(char));
        if (albums[1].artist) {
            for (size_t j = 0; j <= len; j++) {
                albums[1].artist[j] = artist[j];
            }
        }
        
        albums[1].year = 1973;
    }
    
    return albums;
}

/**
 * free_all_albums - Frees all memory associated with an array of albums.
 *
 * @albums: Pointer to the album array.
 * @size: The size of the array.
 */
void free_all_albums(album *albums, size_t size) {
    if (albums) {
        for (size_t i = 0; i < size; i++) {
            free(albums[i].title);
            free(albums[i].artist);
        }
        free(albums);
    }
}

/**
 * main - Entry point of the program.
 *
 * This program demonstrates the realloc_album function by creating, resizing,
 * and printing arrays of albums.
 *
 * Return:
 *   0 on success, 1 on error.
 */
int main() {
    size_t initial_size = 2;
    size_t new_size = 4;
    
    // Create initial album array
    printf("Creating array of %zu albums...\n", initial_size);
    album *albums = create_test_albums(initial_size);
    if (!albums) {
        fprintf(stderr, "Failed to create album array\n");
        return 1;
    }
    
    // Print initial albums
    printf("\nOriginal albums:\n");
    for (size_t i = 0; i < initial_size; i++) {
        printf("[%zu] ", i);
        print_album(&albums[i]);
    }
    
    // Resize the album array
    printf("\nResizing array from %zu to %zu albums...\n", initial_size, new_size);
    album *new_albums = realloc_album(albums, initial_size, new_size);
    if (!new_albums) {
        fprintf(stderr, "Failed to resize album array\n");
        free_all_albums(albums, initial_size);
        return 1;
    }
    albums = new_albums;
    
    // Add data to the new albums
    if (new_size > 2) {
        const char *title = "Abbey Road";
        size_t len = 0;
        while (title[len]) len++;
        albums[2].title = malloc((len + 1) * sizeof(char));
        if (albums[2].title) {
            for (size_t j = 0; j <= len; j++) {
                albums[2].title[j] = title[j];
            }
        }
        
        const char *artist = "The Beatles";
        len = 0;
        while (artist[len]) len++;
        albums[2].artist = malloc((len + 1) * sizeof(char));
        if (albums[2].artist) {
            for (size_t j = 0; j <= len; j++) {
                albums[2].artist[j] = artist[j];
            }
        }
        
        albums[2].year = 1969;
    }
    
    // Print resized albums
    printf("\nResized albums:\n");
    for (size_t i = 0; i < new_size; i++) {
        printf("[%zu] ", i);
        print_album(&albums[i]);
    }
    
    // Free all memory
    free_all_albums(albums, new_size);
    
    printf("\nMemory freed successfully\n");
    return 0;
}
