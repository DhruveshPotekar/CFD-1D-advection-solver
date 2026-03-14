#ifndef BOUNDARYCONDITIONS_H
#define BOUNDARYCONDITIONS_H

#include "Field.h"

class BoundaryConditions {
public:
    static int periodicIndex(int i, int nx);
};

#endif