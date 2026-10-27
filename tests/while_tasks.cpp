#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>
#include <tuple>

int find_left_part_1(int A, int B) {
    if (A < B || A < 0 || B < 0) {
        return -1;
    }
    int placed = B;
    while (placed + B <= A) {
        placed += B;
    }
    return A - placed;
}

int solve_inequal_39(int N) {
    if (N <= 1) {
        return -1;
    }
    int k = 1;
    while (std::pow(3, k) <= N) {
        k += 1;
    }
    return k;
}

std::tuple<int, double, double> solve_eqution_58(double e) {
    int k = 2;
    double a_previous = 2;
    double a = 2 + 1 / a_previous;
    while (std::abs(a - a_previous) >= e) {
        a_previous = a;
        a = 2 + 1 / a_previous;
        k += 1;
    }
    return std::make_tuple(k, a_previous, a);
}

namespace while_tasks {
TEST(Test1, NormalBehaviourWithExistingLeft) {
    int a = 5;
    int b = 2;
    int res = find_left_part_1(a, b);
    EXPECT_EQ(res, 1);
}

TEST(Test1, NormalBehaviourWithoutLeft) {
    int a = 4;
    int b = 2;
    int res = find_left_part_1(a, b);
    EXPECT_EQ(res, 0);
}
TEST(Test1, NotPassingArgs) {
    int a = 2;
    int b = 4;
    int res = find_left_part_1(a, b);
    EXPECT_EQ(res, -1);
}

TEST(Test39, With3Pow) {
    int n = 81;
    int res = solve_inequal_39(n);
    EXPECT_EQ(res, 5);
}
TEST(Test39, WithNot3Pow) {
    int n = 80;
    int res = solve_inequal_39(n);
    EXPECT_EQ(res, 4);
}
TEST(Test39, NotPassingArgs) {
    int n = 0;
    int res = solve_inequal_39(n);
    EXPECT_EQ(res, -1);
}
TEST(Test58, NormalBehaviourBigE) {
    double e = 0.2;
    auto res = solve_eqution_58(e);
    int k = std::get<0>(res);
    double a_p = std::get<1>(res);
    double a = std::get<2>(res);
    EXPECT_EQ(k, 3);
    EXPECT_NEAR(a_p, 2.5, 1e-9);
    EXPECT_NEAR(a, 2.4, 1e-9);
}

TEST(Test58, NormalBehaviourSmallE) {
    double e = 0.02;
    auto res = solve_eqution_58(e);
    int k = std::get<0>(res);
    double a_p = std::get<1>(res);
    double a = std::get<2>(res);
    EXPECT_EQ(k, 4);
    EXPECT_NEAR(a_p, 2.4, 1e-9);
    EXPECT_NEAR(a, 2+1/2.4, 1e-9);
}
}  // namespace while_tasks
