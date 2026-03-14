#include "Solver.h"

int main() {
    int nx = 100;
    double x_start = 0.0;
    double x_end = 1.0;
    double a = 1.0;
    double cfl = 0.8;
    double final_time = 1.0;

    Solver solver(nx, x_start, x_end, a, cfl, final_time);

    solver.initializeGaussian(0.3, 0.08);
    solver.run();
    solver.writeSolutionWithExact("solution.dat");

    return 0;
}