#include "manhattan.h"

/**
 * manhattan - Calculates the Manhattan distance between two points.
 *
 * @p1: The first point.
 * @p2: The second point.
 *
 * Return:
 *   The Manhattan distance between p1 and p2.
 */
int manhattan(point p1, point p2) {
    return ABS(p1.x - p2.x) + ABS(p1.y - p2.y);
}
