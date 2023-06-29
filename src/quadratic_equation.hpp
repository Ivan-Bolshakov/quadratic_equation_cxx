#pragma once
#include <vector>

class QuardraticEquation
{
public:
    static constexpr double kEpsilon = 1e-6;
    QuardraticEquation() = default;
    ~QuardraticEquation() = default;

    static std::vector<double> solve(double a, double b, double c);
};