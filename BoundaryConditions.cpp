#include "BoundaryConditions.h"

int BoundaryConditions::periodicIndex(int i, int nx) {
    if (i < 0) return i + nx;
    if (i >= nx) return i - nx;
    return i;
}