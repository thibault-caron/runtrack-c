#ifndef MANHATTAN_H
#define MANHATTAN_H

// Define the point structure
typedef struct {
    int x;
    int y;
} point;

/**
 * ABS - Macro to calculate the absolute value of a number.
 *
 * @x: The number to calculate the absolute value for.
 *
 * Return:
 *   The absolute value of x.
 */
#define ABS(x) ((x) < 0 ? -(x) : (x))

/**
 * manhattan - Calculates the Manhattan distance between two points.
 *
 * @p1: The first point.
 * @p2: The second point.
 *
 * Return:
 *   The Manhattan distance between p1 and p2.
 */
int manhattan(point p1, point p2);

#endif
