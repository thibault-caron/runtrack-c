#include "manhattan.h"

int manhattan(point p1, point p2) {
    return ABS(p1.x - p2.x) + ABS(p1.y - p2.y);
}
