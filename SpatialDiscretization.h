#ifndef SPATIALDISCRETIZATION_H
#define SPATIALDISCRETIZATION_H

#include "Grid.h"
#include "Field.h"

class SpatialDiscretization {
public:
    static void computeUpwindRHS(const Grid& grid, const Field& u, Field& rhs, double a);
};

#endif