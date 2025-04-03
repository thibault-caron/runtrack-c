#ifndef MANHATTAN_H
#define MANHATTAN_H

// Define the point structure
typedef struct {
    int x;
    int y;
} point;

// ABS macro (ABSOLUTE): if x is negative, return -x; otherwise, return x
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Prototype for the manhattan function
int manhattan(point p1, point p2);

#endif
