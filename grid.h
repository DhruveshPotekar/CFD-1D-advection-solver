#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
public:
    Grid(int nx, double x_start, double x_end);

    int getNx() const;
    double getDx() const;
    double getX(int i) const;
    const std::vector<double>& getXCoords() const;

private:
    int nx;
    double x_start, x_end, dx;
    std::vector<double> x;
};

#endif