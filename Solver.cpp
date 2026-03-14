#include "Solver.h"
#include "SpatialDiscretization.h"
#include "TimeIntegrator.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>

Solver::Solver(int nx, double x_start, double x_end, double a_, double cfl_, double final_time_)
    : grid(nx, x_start, x_end),
      u(nx),
      rhs(nx),
      a(a_),
      cfl(cfl_),
      final_time(final_time_),
      time(0.0) {}

void Solver::initializeGaussian(double center, double width) {
    for (int i = 0; i < grid.getNx(); ++i) {
        double x = grid.getX(i);
        u[i] = std::exp(-std::pow((x - center) / width, 2));
    }
}

double Solver::computeTimeStep() const {
    return cfl * grid.getDx() / std::abs(a);
}

void Solver::run() {
    int step = 0;

    while (time < final_time) {
        double dt = computeTimeStep();

        if (time + dt > final_time) {
            dt = final_time - time;
        }

        SpatialDiscretization::computeUpwindRHS(grid, u, rhs, a);
        TimeIntegrator::explicitEuler(u, rhs, dt);

        time += dt;
        ++step;

        if (step % 50 == 0) {
            std::cout << "Step: " << step << ", Time: " << time << std::endl;
        }
    }

    std::cout << "Finished. Total steps = " << step << ", Final time = " << time << std::endl;
}

void Solver::writeSolution(const char* filename) const {
    std::ofstream file(filename);

    for (int i = 0; i < grid.getNx(); ++i) {
        file << grid.getX(i) << " " << u[i] << "\n";
    }

    file.close();
}