#include <gtest/gtest.h>

bool isPerfectSquare(int num) {
    long long squd, mid;
    int left = 0, right = num;
    while (left <= right) {
        mid = (left + right) / 2;
        squd = mid * mid;
        if (squd == num)
            return true;
        else if (squd < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

TEST(Q367, CASE1) { ASSERT_EQ(isPerfectSquare(16), true); }

TEST(Q367, CASE2) { ASSERT_EQ(isPerfectSquare(14), false); }