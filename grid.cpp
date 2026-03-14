#include "Grid.h"

Grid::Grid(int nx_, double x_start_, double x_end_)
    : nx(nx_), x_start(x_start_), x_end(x_end_) {
    dx = (x_end - x_start) / nx;
    x.resize(nx);
    for (int i = 0; i < nx; ++i) {
        x[i] = x_start + i * dx;
    }
}

int Grid::getNx() const {
    return nx;
}

double Grid::getDx() const {
    return dx;
}

double Grid::getX(int i) const {
    return x[i];
}

const std::vector<double>& Grid::getXCoords() const {
    return x;
}