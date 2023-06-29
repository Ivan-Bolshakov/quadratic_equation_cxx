#include "gtest/gtest.h"
#include "lib.h"

TEST(SolveTest, NoRoots) {
    EXPECT_TRUE(version() > 0);
}

/*
#include "src/quadratic_equation.hpp"
TEST(SolveTest, TwoDistinctRoots) {
    std::vector<double> roots = solve(1, 0, -1);
    EXPECT_NEAR(1, roots[0], EPSILON);
    EXPECT_NEAR(-1, roots[1], EPSILON);
}

TEST(SolveTest, DoubleRoot) {
    std::vector<double> roots = solve(1, 2, 1);
    EXPECT_NEAR(-1, roots[0], EPSILON);
}

TEST(SolveTest, InvalidCoefficient) {
    EXPECT_THROW(solve(0, 2, 1), std::invalid_argument);
}
*/
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
