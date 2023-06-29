#include "quadratic_equation.hpp"

#include <iostream>

int main()
{
    double a, b, c;

    while (true)
    {
        std::cout << "Введите коэффициенты: ";
        std::cin >> a >> b >> c;

        std::vector<double> roots = QuardraticEquation::solve(a, b, c);
        if (roots.empty())
        {
            std::cout << "Корней нет" << std::endl;
        }
        else if (roots.size() == 1)
        {
            std::cout << "1 корень: " << roots[0] << std::endl;
        }
        else
        {
            std::cout << "2 корня: " << roots[0] << " и " << roots[1] << std::endl;
        }
    }

    return 0;
}