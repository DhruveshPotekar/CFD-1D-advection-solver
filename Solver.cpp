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
      time(0.0),
      initial_center(0.0),
      initial_width(1.0) {}

void Solver::initializeGaussian(double center, double width) {
    initial_center = center;
    initial_width = width;

    for (int i = 0; i < grid.getNx(); ++i) {
        double x = grid.getX(i);
        u[i] = std::exp(-std::pow((x - center) / width, 2));
    }
}

double Solver::computeTimeStep() const {
    return cfl * grid.getDx() / std::abs(a);
}

double Solver::wrapToDomain(double x) const {
    double x_start = grid.getX(0);
    double x_end = x_start + grid.getNx() * grid.getDx();
    double length = x_end - x_start;

    while (x < x_start) {
        x += length;
    }
    while (x >= x_end) {
        x -= length;
    }

    return x;
}

double Solver::exactSolution(double x) const {
    double shifted_x = x - a * time;
    shifted_x = wrapToDomain(shifted_x);

    return std::exp(-std::pow((shifted_x - initial_center) / initial_width, 2));
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
    std::cout << "L2 error = " << computeL2Error() << std::endl;
}

double Solver::computeL2Error() const {
    double sum = 0.0;
    int nx = grid.getNx();

    for (int i = 0; i < nx; ++i) {
        double x = grid.getX(i);
        double u_exact = exactSolution(x);
        double diff = u[i] - u_exact;
        sum += diff * diff;
    }

    return std::sqrt(sum / nx);
}

void Solver::writeSolution(const char* filename) const {
    std::ofstream file(filename);

    for (int i = 0; i < grid.getNx(); ++i) {
        file << grid.getX(i) << " " << u[i] << "\n";
    }

    file.close();
}

void Solver::writeSolutionWithExact(const char* filename) const {
    std::ofstream file(filename);

    for (int i = 0; i < grid.getNx(); ++i) {
        double x = grid.getX(i);
        double u_exact = exactSolution(x);
        double error = u[i] - u_exact;

        file << x << " " << u[i] << " " << u_exact << " " << error << "\n";
    }

    file.close();
}