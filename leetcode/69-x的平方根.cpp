#include <gtest/gtest.h>

#include "gtest/gtest.h"

int mySqrt(int x) {
    int left = 0, right = x;
    long long mid;
    long long squd;
    while (left <= right) {
        mid = (left + right) / 2;
        squd = mid * mid;
        if (squd < x)
            left = mid + 1;
        else if (squd > x)
            right = mid - 1;
        else
            return static_cast<int>(mid);
    }
    return static_cast<int>(left - 1);
}

TEST(Q69, CASE1) { ASSERT_EQ(mySqrt(4), 2); }

TEST(Q69, CASE2) { ASSERT_EQ(mySqrt(8), 2); }

TEST(Q69, CASE3) { ASSERT_EQ(mySqrt(0), 0); }

TEST(Q69, CASE4) { ASSERT_EQ(mySqrt(1), 1); }