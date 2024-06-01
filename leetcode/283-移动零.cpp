#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int> &nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
            ++right;
        }
        while (left < nums.size()) {
            nums[left++] = 0;
        }
    }
};

void test(vector<int> &nums, vector<int> &ans) {
    Solution solution = Solution();
    solution.moveZeroes(nums);
    ASSERT_EQ(nums, ans);
}

TEST(Q283, CASE1) {
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> ans = {1, 3, 12, 0, 0};
    test(nums, ans);
}

TEST(Q283, CASE2) {
    vector<int> nums = {0};
    vector<int> ans = {0};
    test(nums, ans);
}