#include "SpatialDiscretization.h"
#include "BoundaryConditions.h"

void SpatialDiscretization::computeUpwindRHS(const Grid& grid, const Field& u, Field& rhs, double a) {
    int nx = grid.getNx();
    double dx = grid.getDx();

    for (int i = 0; i < nx; ++i) {
        int im1 = BoundaryConditions::periodicIndex(i - 1, nx);
        int ip1 = BoundaryConditions::periodicIndex(i + 1, nx);

        if (a > 0.0) {
            rhs[i] = -a * (u[i] - u[im1]) / dx;
        } else {
            rhs[i] = -a * (u[ip1] - u[i]) / dx;
        }
    }
}