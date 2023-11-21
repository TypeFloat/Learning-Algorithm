#include <gtest/gtest.h>

#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] != 0) {
            nums[slow++] = nums[fast];
        };
        ++fast;
    }
    for (; slow < nums.size(); ++slow) {
        nums[slow] = 0;
    }
}

TEST(Q283, CASE1) {
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> target = {1, 3, 12, 0, 0};
    moveZeroes(nums);
    ASSERT_EQ(nums, target);
}

TEST(Q283, CASE2) {
    vector<int> nums = {0};
    vector<int> target = {0};
    moveZeroes(nums);
    ASSERT_EQ(nums, target);
}