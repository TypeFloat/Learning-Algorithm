#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> rtn(nums.size(), 0);
        rtn[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            rtn[i] = rtn[i - 1] * nums[i];
        }
        int mulVal = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            rtn[i] = mulVal * rtn[i - 1];
            mulVal *= nums[i];
        }
        rtn[0] = mulVal;
        return rtn;
    }
};

void test(vector<int> &nums, vector<int> &ans) {
    Solution solution = Solution();
    vector<int> rtn = solution.productExceptSelf(nums);
    ASSERT_EQ(rtn, ans);
}

TEST(Q238, CASE1) {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = {24, 12, 8, 6};
    test(nums, ans);
}

TEST(Q238, CASE2) {
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> ans = {0, 0, 9, 0, 0};
    test(nums, ans);
}