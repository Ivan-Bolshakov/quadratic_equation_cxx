#include "gtest/gtest.h"
#include "quadratic_equation.hpp"
#include <cmath>

TEST(SolveTest, NoRoots)
{
    double a = 1;
    double b = 0;
    double c = 1;
    std::vector<double> roots = QuardraticEquation::solve(a, b, c);
    EXPECT_TRUE(roots.empty());
}

TEST(SolveTest, TwoDistinctRoots)
{
    double a = 1;
    double b = 0;
    double c = -1;
    double expected_res_1 = 1;
    double expected_res_2 = -1;
    std::vector<double> roots = QuardraticEquation::solve(a, b, c);
    EXPECT_EQ(roots.size(), 2);
    EXPECT_DOUBLE_EQ(expected_res_1, roots[0]);
    EXPECT_DOUBLE_EQ(expected_res_2, roots[1]);
}

TEST(SolveTest, OneRoot)
{
    double a = 1;
    double b = 2;
    double c = 1;
    double expected_res = -1;
    std::vector<double> roots = QuardraticEquation::solve(a, b, c);
    EXPECT_EQ(roots.size(), 1);
    EXPECT_DOUBLE_EQ(expected_res, roots[0]);
}

TEST(SolveTest, CoefAIsZero)
{
    double a = 0;
    double b = 0;
    double c = -1;
    EXPECT_THROW(QuardraticEquation::solve(a, b, c), std::invalid_argument);
}

TEST(SolveTest, AEqualNan)
{
    double a = NAN;
    double b = 3;
    double c = -1;
    EXPECT_THROW(QuardraticEquation::solve(a, b, c), std::invalid_argument);
}

TEST(SolveTest, BEqualNan)
{
    double a = 1;
    double b = NAN;
    double c = -1;
    EXPECT_THROW(QuardraticEquation::solve(a, b, c), std::invalid_argument);
}

TEST(SolveTest, CEqualNan)
{
    double a = 1;
    double b = 0;
    double c = NAN;
    EXPECT_THROW(QuardraticEquation::solve(a, b, c), std::invalid_argument);
}

TEST(SolveTest, AEqualInf)
{
    double a = INFINITY;
    double b = 3;
    double c = -1;
    EXPECT_THROW(QuardraticEquation::solve(a, b, c), std::invalid_argument);
}

TEST(SolveTest, BEqualInf)
{
    double a = 1;
    double b = INFINITY;
    double c = -1;
    EXPECT_THROW(QuardraticEquation::solve(a, b, c), std::invalid_argument);
}

TEST(SolveTest, CEqualInf)
{
    double a = 1;
    double b = 0;
    double c = INFINITY;
    EXPECT_THROW(QuardraticEquation::solve(a, b, c), std::invalid_argument);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
