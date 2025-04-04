#ifndef MUSIC_LIST_H
#define MUSIC_LIST_H

#include <stdlib.h>

/**
 * struct album_node - Represents an album in a linked list.
 *
 * @title: The title of the album (dynamically allocated string).
 * @artist: The artist of the album (dynamically allocated string).
 * @year: The release year of the album.
 * @next: Pointer to the next node in the linked list.
 */
typedef struct album_node {
    char *title;         // Dynamically allocated
    char *artist;        // Dynamically allocated
    int year;
    struct album_node *next;
} album_node;

/**
 * init_album_node - Initialize a new album node with default values.
 *
 * @node: Pointer to the node to initialize.
 */
void init_album_node(album_node *node);

/**
 * create_album_node - Create and initialize a new album node.
 *
 * @title: The title of the album.
 * @artist: The artist of the album.
 * @year: The release year of the album.
 *
 * Return: A pointer to the new album node, or NULL if allocation fails.
 */
album_node *create_album_node(const char *title, const char *artist, int year);

/**
 * free_album_node - Free the memory associated with a single album node.
 *
 * @node: Pointer to the node to free.
 */
void free_album_node(album_node *node);

/**
 * free_album_list - Free the entire linked list of albums.
 *
 * @head: Pointer to the first node in the list.
 */
void free_album_list(album_node *head);

/**
 * print_album_node - Print an album node in the required format.
 *
 * @node: Pointer to the node to print.
 */
void print_album_node(const album_node *node);

/**
 * print_album_list - Print all albums in the linked list.
 *
 * @head: Pointer to the first node in the list.
 */
void print_album_list(const album_node *head);

/**
 * sort_album_list - Sort the album list based on a specified criterion.
 *
 * @head: Pointer to pointer to the first node.
 * @sort_by: String specifying the sort criterion ("artist", "title", or "year").
 *
 * Return: 1 if successful, 0 if the sort method doesn't exist.
 */
int sort_album_list(album_node **head, const char *sort_by);

/**
 * read_albums_from_file - Read album information from a file.
 *
 * @filename: Name of the file to read.
 * @head: Pointer to pointer to the first node.
 *
 * Return: 1 if successful, 0 if there was an error.
 */
int read_albums_from_file(const char *filename, album_node **head);

#endif
