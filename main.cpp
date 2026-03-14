#include "Solver.h"
#include <chrono>
#include <iostream>

int main() {

    int nx = 1600;
    double x_start = 0.0;
    double x_end = 1.0;
    double a = 1.0;
    double cfl = 0.8;
    double final_time = 1.0;

    Solver solver(nx, x_start, x_end, a, cfl, final_time);

    solver.initializeGaussian(0.3, 0.08);

    // start timer
    auto start = std::chrono::high_resolution_clock::now();

    solver.run();

    // stop timer
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Wall time = " << elapsed.count() << " seconds\n";

    solver.writeSolutionWithExact("solution_x1600.dat");

    return 0;
}