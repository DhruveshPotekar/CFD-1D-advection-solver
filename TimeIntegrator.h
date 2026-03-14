#ifndef TIMEINTEGRATOR_H
#define TIMEINTEGRATOR_H

#include "Field.h"

class TimeIntegrator {
public:
    static void explicitEuler(Field& u, const Field& rhs, double dt);
};

#endif