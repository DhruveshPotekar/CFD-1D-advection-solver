#include "TimeIntegrator.h"

void TimeIntegrator::explicitEuler(Field& u, const Field& rhs, double dt) {
    int n = u.size();
    for (int i = 0; i < n; ++i) {
        u[i] += dt * rhs[i];
    }
}