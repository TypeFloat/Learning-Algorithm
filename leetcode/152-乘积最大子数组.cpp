#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxDp(nums.size(), 0);
        vector<int> minDp(nums.size(), 0);
        maxDp[0] = nums[0];
        minDp[0] = nums[0];
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxDp[i] = nums[i];
            maxDp[i] = max(maxDp[i], nums[i] * maxDp[i - 1]);
            maxDp[i] = max(maxDp[i], nums[i] * minDp[i - 1]);
            minDp[i] = nums[i];
            minDp[i] = min(minDp[i], nums[i] * maxDp[i - 1]);
            minDp[i] = min(minDp[i], nums[i] * minDp[i - 1]);
            maxVal = max(maxVal, maxDp[i]);
        }
        return maxVal;
    }
};

void test(vector<int>& nums, int ans) {
    Solution solution = Solution();
    ASSERT_EQ(solution.maxProduct(nums), ans);
}

TEST(Q152, CASE1) {
    vector<int> nums = {-1, 0, -2, 2};
    int ans = 2;
    test(nums, ans);
}

TEST(Q152, CASE2) {
    vector<int> nums = {3, 2, -2, 1};
    int ans = 6;
    test(nums, ans);
}

TEST(Q152, CASE3) {
    vector<int> nums = {-2, 0, -1};
    int ans = 0;
    test(nums, ans);
}

TEST(Q152, CASE4) {
    vector<int> nums = {2, 3, -2, 4};
    int ans = 6;
    test(nums, ans);
}

TEST(Q152, CASE5) {
    vector<int> nums = {3, -1, 4};
    int ans = 4;
    test(nums, ans);
}