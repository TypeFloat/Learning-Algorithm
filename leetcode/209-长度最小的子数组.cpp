#include <gtest/gtest.h>

#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    int min_len = nums.size() + 1;
    int left = 0, right = 0, sum = nums[0];
    while (right < nums.size() && left <= right) {
        if (sum < target) {
            ++right;
            if (right >= nums.size()) break;
            sum += nums[right];
        } else {
            min_len = min(min_len, right - left + 1);
            sum -= nums[left];
            ++left;
        }
    }
    return min_len < nums.size() + 1 ? min_len : 0;
}

TEST(Q209, CASE1) {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    ASSERT_EQ(minSubArrayLen(7, nums), 2);
}

TEST(Q209, CASE2) {
    vector<int> nums = {1, 4, 4};
    ASSERT_EQ(minSubArrayLen(4, nums), 1);
}
TEST(Q209, CASE3) {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1};
    ASSERT_EQ(minSubArrayLen(11, nums), 0);
}

TEST(Q209, CASE4) {
    vector<int> nums = {1, 2, 3, 4, 5};
    ASSERT_EQ(minSubArrayLen(15, nums), 5);
}