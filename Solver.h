#ifndef SOLVER_H
#define SOLVER_H

#include "Grid.h"
#include "Field.h"

class Solver {
public:
    Solver(int nx, double x_start, double x_end, double a, double cfl, double final_time);

    void initializeGaussian(double center, double width);
    void run();

    void writeSolution(const char* filename) const;
    void writeSolutionWithExact(const char* filename) const;
    double computeL1Error() const;
    double computeRMSE() const;

private:
    Grid grid;
    Field u;
    Field rhs;

    double a;
    double cfl;
    double final_time;
    double time;
    double elapsed;

    double L1_error;
    double RMSE_error;

    double initial_center;
    double initial_width;

    double computeTimeStep() const;
    double exactSolution(double x) const;
    double wrapToDomain(double x) const;
};

#endif