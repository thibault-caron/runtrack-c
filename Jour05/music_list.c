#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "music_list.h"

void init_album_node(album_node *node) {
    if (!node) return;
    
    node->title = NULL;
    node->artist = NULL;
    node->year = 0;
    node->next = NULL;
}

/**
 * string_length - Calculate the length of a string.
 *
 * @str: The string to measure.
 *
 * Return: The length of the string, or 0 if NULL.
 */
static size_t string_length(const char *str) {
    if (!str) return 0;
    
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

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
 * find_char - Find a character in a string.
 *
 * @str: The string to search.
 * @ch: The character to find.
 *
 * Return: Pointer to the first occurrence of ch in str, or NULL if not found.
 */
static char *find_char(const char *str, char ch) {
    if (!str) return NULL;
    
    while (*str != '\0') {
        if (*str == ch) {
            return (char *)str;
        }
        str++;
    }
    
    return NULL;
}

/**
 * duplicate_string - Duplicate a string using dynamic memory allocation.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the new duplicate string, or NULL if allocation fails.
 */
static char *duplicate_string(const char *str) {
    if (!str) return NULL;
    
    size_t len = string_length(str);
    char *duplicate = malloc(len + 1);
    
    if (duplicate) {
        size_t i;
        for (i = 0; i < len; i++) {
            duplicate[i] = str[i];
        }
        duplicate[len] = '\0';
    }
    
    return duplicate;
}

album_node *create_album_node(const char *title, const char *artist, int year) {
    album_node *node = malloc(sizeof(album_node));
    if (!node) return NULL;
    
    init_album_node(node);
    
    node->title = duplicate_string(title);
    node->artist = duplicate_string(artist);
    node->year = year;
    
    if ((title && !node->title) || (artist && !node->artist)) {
        free_album_node(node);
        return NULL;
    }
    
    return node;
}

void free_album_node(album_node *node) {
    if (!node) return;
    
    free(node->title);
    free(node->artist);
    free(node);
}

void free_album_list(album_node *head) {
    album_node *current = head;
    while (current) {
        album_node *next = current->next;
        free_album_node(current);
        current = next;
    }
}

void print_album_node(const album_node *node) {
    if (!node || !node->title || !node->artist) {
        write(2, "Invalid album data.\n", 20);
        return;
    }
    
    write(1, "\"", 1);
    write(1, node->title, string_length(node->title));
    write(1, "\" by \"", 6);
    write(1, node->artist, string_length(node->artist));
    write(1, "\" released in ", 14);
    
    // Convert year to string
    char year_str[20];
    int temp = node->year;
    int index = 0;
    
    // Handle negative year (unlikely but just in case)
    int negative = 0;
    if (temp < 0) {
        negative = 1;
        temp = -temp;
    }
    
    // Build year digits in reverse
    do {
        year_str[index++] = '0' + (temp % 10);
        temp /= 10;
    } while (temp > 0);
    
    // Add negative sign if necessary
    if (negative) {
        year_str[index++] = '-';
    }
    
    // Print year digits in correct order
    while (--index >= 0) {
        write(1, &year_str[index], 1);
    }
    
    write(1, ".\n", 2);
}

void print_album_list(const album_node *head) {
    const album_node *current = head;
    while (current) {
        print_album_node(current);
        current = current->next;
    }
}

/**
 * compare_by_artist - Compare two album nodes by artist name.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 *
 * Return: < 0 if a < b, > 0 if a > b, 0 if a == b
 */
static int compare_by_artist(const album_node *a, const album_node *b) {
    if (!a->artist) return b->artist ? -1 : 0;
    if (!b->artist) return 1;
    
    return string_compare(a->artist, b->artist);
}

/**
 * compare_by_title - Compare two album nodes by title.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 *
 * Return: < 0 if a < b, > 0 if a > b, 0 if a == b
 */
static int compare_by_title(const album_node *a, const album_node *b) {
    if (!a->title) return b->title ? -1 : 0;
    if (!b->title) return 1;
    
    return string_compare(a->title, b->title);
}

/**
 * compare_by_year - Compare two album nodes by release year.
 *
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 *
 * Return: < 0 if a < b, > 0 if a > b, 0 if a == b
 */
static int compare_by_year(const album_node *a, const album_node *b) {
    return a->year - b->year;
}

/**
 * merge_lists - Merge two sorted lists into one.
 *
 * @a: Pointer to the first list.
 * @b: Pointer to the second list.
 * @compare: Comparison function to use.
 *
 * Return: Pointer to the merged sorted list.
 */
static album_node *merge_lists(album_node *a, album_node *b, 
                              int (*compare)(const album_node*, const album_node*)) {
    album_node dummy;
    album_node *tail = &dummy;
    
    dummy.next = NULL;
    
    while (a && b) {
        album_node **next;
        
        if (compare(a, b) <= 0) {
            next = &a;
        } else {
            next = &b;
        }
        
        tail->next = *next;
        tail = *next;
        *next = (*next)->next;
    }
    
    tail->next = a ? a : b;
    return dummy.next;
}

/**
 * merge_sort - Sort a linked list using the merge sort algorithm.
 *
 * Implementation uses a top-down approach with O(n log n) time complexity.
 * First divides the list into two halves using fast/slow pointer technique,
 * then recursively sorts each half, and finally merges the sorted halves.
 *
 * @head_ptr: Pointer to pointer to the first node.
 * @compare: Comparison function to use.
 */
static void merge_sort(album_node **head_ptr, 
                     int (*compare)(const album_node*, const album_node*)) {
    album_node *head = *head_ptr;
    
    // Base case: empty list or single element
    if (!head || !head->next) return;
    
    // Split list into two halves
    album_node *fast = head->next;
    album_node *slow = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    album_node *second_half = slow->next;
    slow->next = NULL;
    
    // Recursively sort both halves
    merge_sort(&head, compare);
    merge_sort(&second_half, compare);
    
    // Merge the sorted halves
    *head_ptr = merge_lists(head, second_half, compare);
}

/* See header file for function description */
int sort_album_list(album_node **head, const char *sort_by) {
    int (*compare)(const album_node*, const album_node*) = NULL;
    
    if (string_compare(sort_by, "artist") == 0) {
        compare = compare_by_artist;
    } else if (string_compare(sort_by, "title") == 0) {
       compare = compare_by_title;
    } else if (string_compare(sort_by, "year") == 0) {
        compare = compare_by_year;
    } else {
        return 0; // Sort method does not exist
    }
    
    merge_sort(head, compare);
    return 1;
}

/**
 * string_to_int - Convert a string to an integer.
 *
 * @str: The string to convert.
 *
 * Return: The integer value, or 0 if conversion fails.
 */
static int string_to_int(const char *str) {
    if (!str) return 0;
    
    int result = 0;
    int sign = 1;
    
    // Handle sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    
    // Process each digit
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    // Check if we had any digits
    if (*str != '\0' && *str != '\n' && *str != '\r') {
        return 0; // Invalid format
    }
    
    return result * sign;
}

/**
 * parse_line - Parse a line from the input file.
 *
 * @line: The line to parse.
 * @artist: Pointer to store the artist.
 * @title: Pointer to store the title.
 * @year: Pointer to store the year.
 *
 * Return: 1 if successful, 0 if the format is incorrect.
 */
static int parse_line(char *line, char **artist, char **title, int *year) {
    // Find first comma
    char *first_comma = find_char(line, ',');
    if (!first_comma) return 0;
    
    // Temporarily replace first comma with null terminator
    *first_comma = '\0';
    *artist = line;
    
    // Find second comma
    char *second_comma = find_char(first_comma + 1, ',');
    if (!second_comma) {
        *first_comma = ','; // Restore comma
        return 0;
    }
    
    // Temporarily replace second comma with null terminator
    *second_comma = '\0';
    *title = first_comma + 1;
    
    // Try to parse year
    *year = string_to_int(second_comma + 1);
    
    // Check if conversion was successful (non-zero)
    if (*year == 0) {
        *first_comma = ','; // Restore commas
        *second_comma = ',';
        return 0;
    }
    return 1;
}

/* See header file for function description */
int read_albums_from_file(const char *filename, album_node **head) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "File not found.\n", 16);
        return 0;
    }
    
    // Read the entire file into a buffer
    char buffer[4096]; // Adjust size as needed
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);
    
    if (bytes_read <= 0) {
        return 1; // Empty file is not an error
    }
    
    buffer[bytes_read] = '\0';
    
    // Process each line manually
    char *line_start = buffer;
    album_node *tail = NULL;
    
    while (1) {
        // Find end of line
        char *line_end = line_start;
        while (*line_end != '\0' && *line_end != '\n') {
            line_end++;
        }
        
        // Save original character at line end and null-terminate the line
        char original_char = *line_end;
        *line_end = '\0';
        
        // Process this line if it's not empty
        if (line_start < line_end) {
            char *artist = NULL;
            char *title = NULL;
            int year = 0;
            
            if (parse_line(line_start, &artist, &title, &year)) {
                // Create a duplicate of artist and title since they point to 
                // memory within our buffer which will become invalid
                album_node *node = create_album_node(title, artist, year);
                if (!node) {
                    free_album_list(*head);
                    *head = NULL;
                    return 0;
                }
                
                if (!*head) {
                    *head = node;
                } else {
                    tail->next = node;
                }
                tail = node;
            } else {
                write(2, "Incorrect format.\n", 18);
                free_album_list(*head);
                *head = NULL;
                return 0;
            }
        }
        
        // If we're at the end of the buffer, exit
        if (original_char == '\0') {
            break;
        }
        
        // Move to next line
        line_start = line_end + 1;
    }  
    return 1;
}
