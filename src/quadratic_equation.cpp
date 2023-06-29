#include <cmath>
#include <stdexcept>
#include <vector>

#include "quadratic_equation.hpp"

std::vector<double> QuardraticEquation::solve(double a, double b, double c)
{
    if (std::abs(a) < kEpsilon)
        throw std::invalid_argument("Coefficient 'a' cannot be zero");
    if (std::isinf(a) || std::isnan(a))
        throw std::invalid_argument("A is inf or nan");
    if (std::isinf(b) || std::isnan(b))
        throw std::invalid_argument("B is inf or nan");
    if (std::isinf(c) || std::isnan(c))
        throw std::invalid_argument("C is inf or nan");

    double discr = b * b - 4 * a * c;

    if (std::abs(discr) < kEpsilon)
    {
        return {-b / (2 * a)};
    }
    else if (discr > 0)
    {
        double root1 = (-b + std::sqrt(discr)) / (2 * a);
        double root2 = (-b - std::sqrt(discr)) / (2 * a);
        return {root1, root2};
    }
    else
    {
        return {};
    }
}
