#include <gtest/gtest.h>

#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    vector<int> rtn(nums.size());
    int l, r;
    for (int i = nums.size() - 1; i >= 0; --i) {
        l = nums[left] * nums[left];
        r = nums[right] * nums[right];
        if (l >= r) {
            rtn[i] = l;
            ++left;
        } else {
            rtn[i] = r;
            --right;
        }
    }
    return rtn;
}

TEST(Q977, CASE1) {
    vector<int> nums = {-4, -1, 0, 3, 10}, target = {0, 1, 9, 16, 100};
    ASSERT_EQ(sortedSquares(nums), target);
}

TEST(Q977, CASE2) {
    vector<int> nums = {-7, -3, 2, 3, 11}, target = {4, 9, 9, 49, 121};
    ASSERT_EQ(sortedSquares(nums), target);
}