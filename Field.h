#ifndef FIELD_H
#define FIELD_H

#include <vector>

class Field {
public:
    explicit Field(int size);

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;
    std::vector<double>& data();
    const std::vector<double>& data() const;

private:
    std::vector<double> values;
};

#endif