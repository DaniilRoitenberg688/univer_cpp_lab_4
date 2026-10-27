#include <gtest/gtest.h>

#include <cmath>
#include <iostream>
#include <limits>

double find_sum_of_row_10(int N) {
    if (N <= 0) {
        return std::numeric_limits<double>::quiet_NaN();
    };
    double res = 0;
    for (double i = 1; i <= N; i++) {
        res += 1 / i;
    }
    return res;
}

int find_sum_of_row_51(int N) {
    if (N <= 0) {
        return -1;
    };
    int res = 0;
    for (int i = 0; i <= N; i++) {
        res += std::pow((N + i), 2);
    }
    return res;
}

namespace for_tasks {
TEST(Test10, SimlpeBehaviour) {
    int n = 4;
    double res = find_sum_of_row_10(n);
    EXPECT_NEAR(res, 25.0 / 12, 1e-9);
}

TEST(Test10, Zero) {
    int n = 0;
    double res = find_sum_of_row_10(n);
    EXPECT_TRUE(std::isnan(res));
}

TEST(Test51, SimlpeBehaviour) {
    int n = 4;
    int res = find_sum_of_row_51(n);
    EXPECT_EQ(res, 190);
}

TEST(Test51, Zero) {
    int n = 0;
    int res = find_sum_of_row_51(n);
    EXPECT_EQ(res, -1);
}

}  // namespace for_tasks
