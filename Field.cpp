#include "Field.h"

Field::Field(int size) : values(size, 0.0) {}

double& Field::operator[](int i) {
    return values[i];
}

const double& Field::operator[](int i) const {
    return values[i];
}

int Field::size() const {
    return static_cast<int>(values.size());
}

std::vector<double>& Field::data() {
    return values;
}

const std::vector<double>& Field::data() const {
    return values;
}