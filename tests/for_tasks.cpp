#include <gtest/gtest.h>

#include <cmath>
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

}  // namespace for_tasks
